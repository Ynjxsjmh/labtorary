Function FindLostOneInDir($dir) {
    $dirs = Get-ChildItem -Path $dir.FullName -Directory;

    Foreach ($sub_dir in $dirs) {
        FindLostOneInDir($sub_dir);
    }

    $to_natural = { [regex]::Replace($_, '\d+', { $args[0].Value.PadLeft(20) }) };
    $sorted_files = Get-ChildItem -Path $dir.FullName -File | Sort-Object $to_natural;
    if ($sorted_files.Length -lt 1) {
        Write-Host "$dir is not a validate target directory"
        return ;
    }

    $lost_files = New-Object Collections.Generic.List[Int];

    try {
        $max_num = [int][System.IO.Path]::GetFileNameWithoutExtension($sorted_files[$sorted_files.Length-1].Name);
    } catch {
        Write-Host "The last sorted file name in $dir has some problems";
    }

    $total_size = 0;
    for ($i = 0; $i -lt $max_num; $i++) {
        $total_size = $total_size + [int]$sorted_files[$i].Length;

        try {
            $cur_num = [int][System.IO.Path]::GetFileNameWithoutExtension($sorted_files[$i].Name);
            $next_num = [int][System.IO.Path]::GetFileNameWithoutExtension($sorted_files[$i+1].Name);
        } catch {
            Write-Host "File name in $dir has some problems, $sorted_files[$i] is not pure number";
            continue;
        }

        for ($j=($cur_num+1); $j -lt $next_num; $j++) {
            $lost_files.Add($j);
        }
    }

    if ($lost_files.Count -gt 0) {
        Write-Host "Lost files in dir: $dir";
        Write-Host $lost_files;
        $is_no_lost_file = False;
    }

    if ($total_size -le 0 -and $max_num * 1024 * 150 -le $total_size) {
        Write-Host "Average size in $dir is lower than 150kb, total size is $total_size";
    }
}

$path = Read-Host 'Directory you want to test';

$dir = [System.IO.DirectoryInfo]$path

FindLostOneInDir($dir)

# 1.jpg 缺失查不出来
# $total_size 总是 0
# 有的文件是分组递增的