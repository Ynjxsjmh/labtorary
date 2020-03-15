
$path = Split-Path -Path $MyInvocation.MyCommand.Definition -Parent #��ȡ��ǰĿ¼
$dirs = Get-ChildItem -Path $path -Directory       # ��ȡ��ǰ�ļ����������ļ���
$targetDirectory = "I"

foreach ($dir in $dirs) {
    $files = Get-ChildItem -Path $dir.FullName -File       # ��ȡ��ǰ�ļ����������ļ�
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