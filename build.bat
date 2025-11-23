@echo off
echo Building DSA Visualizer...
echo.

g++ src/main.cpp src/linked_list.cpp src/data_structures.cpp -std=c++17 ^
    -I./external/Crow/include ^
    -I./external/asio/include ^
    -o dsa_visualizer.exe ^
    -lws2_32 -lmswsock -pthread ^
    -DASIO_STANDALONE

if %errorlevel% equ 0 (
    echo.
    echo ✓ Build successful!
    echo.
    echo Run the server with: run.bat
) else (
    echo.
    echo ✗ Build failed!
    echo Please check the errors above.
)

pause