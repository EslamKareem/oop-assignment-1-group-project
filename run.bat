@echo off
cd /d "%~dp0"

g++ main.cpp -o app.exe
if errorlevel 1 (
    echo Build failed. Please make sure MinGW / g++ is installed and added to PATH.
    pause
    exit /b 1
)

echo Project built successfully.
echo Enter one of the available image files when prompted, for example:
echo   luffy.jpg
 echo   FellAsleep.jpg
echo.
app.exe
