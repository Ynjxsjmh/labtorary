
$path = Split-Path -Path $MyInvocation.MyCommand.Definition -Parent #获取当前目录
$dirs = Get-ChildItem -Path $path -Directory       # 获取当前文件夹下所有文件夹
$targetDirectory = "I"

foreach ($dir in $dirs) {
    $files = Get-ChildItem -Path $dir.FullName -File       # 获取当前文件夹下所有文件
    $destinationDirectory = Join-Path -Path $dir.FullName -ChildPath $targetDirectory

    if(!(Test-Path $destinationDirectory))
    {
        New-Item -Path $destinationDirectory -ItemType Directory | Out-Null
    }

    foreach ($file in $files) {
        Move-Item -Path $file.FullName -Destination $destinationDirectory
    }
}

pause