$directoryToSearch = "C:\"
$targetDirectoryName = "system32"
$excludedirectory = "C:\Windows\System32"

Write-Host "Looking for directories named system32 outside of c:\windows that contain .dll files."

$foundDirectories = Get-ChildItem -Path $directoryToSearch -Filter $targetDirectoryName -Recurse -Directory -ErrorAction SilentlyContinue |
                    Where-Object {
                        $_.FullName -ne $excludeDirectory
                    }

if ($foundDirectories) {
    Write-Host "Found a directory, checking for .dll files"
    foreach ($dir in $foundDirectories.FullName) {
        $foundDlls = Get-ChildItem -Path $dir -Filter *.Dll
        if ($foundDlls){
            Write-Host "found Dll files in '$dir'"
            foreach ($dll in $foundDlls){
                Write-Host "    - DLL: '$($dll.name)'"
            }
        }
        else {
            Write-Host "No Dll files found in '$dir'"
        }
    }
} 
else {
    Write-Host "No directory named '$targetDirectoryName' found."
}
