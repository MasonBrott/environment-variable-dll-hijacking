Find-Hijacking
  - Searches the C drive for any folder named System32 that is not c:\windows\system32
  - Outputs the .dll files in those directories to be investigated

Find-DllHijackingOpportunities
  - Same as Find-Hijacking but is in a while loop to only output new findings
  - Used as kind of a dashboard functionality

image_load_dll_from_non_sys32_location
  - Sigma rule to detect image loads from a directory other than c:\windows\system32
  - Will have false positives, need to update to only search on executables run from c:\windows\system32
