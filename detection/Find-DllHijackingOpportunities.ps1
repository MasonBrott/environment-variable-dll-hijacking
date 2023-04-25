$directoryToSearch = "C:\"
$targetDirectoryName = "system32"
$excludedirectory = "C:\Windows\System32"
$searchIntervalInSeconds = 5 # Adjust the search interval as needed

$foundDirectoriesCache = @{}

function Search-ForSystem32Directories {
    $newDirectoriesAndDlls = Get-ChildItem -Path $directoryToSearch -Filter *.dll -Recurse -ErrorAction SilentlyContinue -File |
                             Where-Object { $_.DirectoryName -like "*\$targetDirectoryName" -and $_.DirectoryName -ne $excludeDirectory } |
                             Select-Object -Property DirectoryName, Name

    foreach ($entry in $newDirectoriesAndDlls) {
        $dir = $entry.DirectoryName
        $dll = $entry.Name

        if (-not $foundDirectoriesCache.ContainsKey($dir)) {
            Write-Host "Found a new directory, checking for .dll files: '$dir'"
            $foundDirectoriesCache[$dir] = [System.Collections.Generic.HashSet[string]]::new()
        }

        if (-not $foundDirectoriesCache[$dir].Contains($dll)) {
            Write-Host "New DLL file found in '$dir':"
            Write-Host "    - DLL: '$dll'"
            $foundDirectoriesCache[$dir].Add($dll)
        }
    }
}

Clear-Host
Write-Host "Starting continuous search for new entries..."

while ($true) {
    Search-ForSystem32Directories
    Start-Sleep -Seconds $searchIntervalInSeconds
}