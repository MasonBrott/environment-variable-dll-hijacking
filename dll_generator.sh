#!/bin/bash

echo "Starting new DLL builds for original DLLs in input folder"

input_folder="$(dirname `realpath $0`)/input"
output_folder="$(dirname `realpath $0`)/output"

cd $input_folder
# Find all of the DLLs in the input folder
dll_files=($(find . -type f -name "*.dll"))

for dll in "${dll_files[@]}"
do
    # Make the .def file
    (   echo -e "LIBRARY Harman\nEXPORTS\n"
        # Getting functions of real DLL
        objdump=$(x86_64-w64-mingw32-objdump -p "$dll")
        # Magic with sed/perl to get everything formatted
        offset=`echo "$objdump" | sed -n -r "s/Export Address Table -- Ordinal Base ([0-9]+)/\1/gp"`
        (echo "$objdump" | perl -ne "print if s/^\s+\[\s{0,3}([0-9]{1,4})\]\s*([^ \s]+)\$/'\"'.\$2.'\"=\"$(echo $dll | sed 's/.\//c:\\\\/' | sed 's/\//\\\\/g').'.\$2.'\"@'.(\$1+${offset:=0})/ep")
    ) > "$output_folder/$dll.def"

    timeout 10s x86_64-w64-mingw32-windres -i "$dll" -O coff -o "$output_folder/$dll.res" 2> /dev/null
    if [ $? -eq 0 ]; then
        # Compile the new DLL (.c template, .def file, and .res file)
        x86_64-w64-mingw32-gcc -shared -mwindows -o "$output_folder/$dll" "$output_folder/$dll.def" "$output_folder/$dll.res" ../new_temp.c
        # Get rid of the non DLL files
        rm "$output_folder/$dll.def" "$output_folder/$dll.res";
    else
        # Compile new DLL (.c template and .def file)
        x86_64-w64-mingw32-gcc -shared -mwindows -o "$output_folder/$dll" "$output_folder/$dll.def" ../new_temp.c
        # Get rid of non DLL files
        rm "$output_folder/$dll.def"
    fi
    
done