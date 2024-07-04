#!/bin/sh

# windows 下，可使用Git Bash运行该文件
mkdir build

cd build

cmake .. -G "MinGW Makefiles"

mingw32-make.exe

cd ..