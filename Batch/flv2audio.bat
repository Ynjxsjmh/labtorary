@echo off
for %%f in (*.flv) do (
    echo %%~nf
    ffmpeg -i "%%~nf.flv" -acodec libmp3lame -aq 4 "%%~nf.mp3
)
