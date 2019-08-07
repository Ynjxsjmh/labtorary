# https://superuser.com/questions/1319917/powershell-get-child-item-how-to-filter-by-size

Get-ChildItem -Recurse -File | where Length -lt 50kb | Remove-Item