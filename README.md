# Project overview
## How to compile the project
First of all, you have to download [SFML 2.5.1](https://www.sfml-dev.org/files/SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit.zip) and [MinGW 7.3.0](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win64/Personal%20Builds/mingw-builds/7.3.0/threads-posix/seh/x86_64-7.3.0-release-posix-seh-rt_v5-rev0.7z/download).

1. Unpack the downloaded compiler and SFML
2. Add `%MINGW_PATH%/bin` to `%Path%` environment variable
3. Copy `%SFML_PATH%/include` content into `%MINGW_PATH%/include`
4. Copy `%SFML_PATH%/lib` content into `%MINGW_PATH%/lib`
5. Edit your `Makefile` and set the correct path to MinGW
6. In MinGW folder, copy `mingw32-make.exe` and save in the same folder as `make.exe`
7. Now you must be able to compile the project just by typing `make` in command line

If you wanna debug the project, you can compile the debug version of project by typing `make debug`.