#!/bin/bash

# 设置构建目录
BUILD_DIR="build-aarch64"
mkdir -p $BUILD_DIR
cd $BUILD_DIR

# 配置CMake
cmake .. -G "Unix Makefiles"

# 构建项目
make -j8

# 运行可执行文件
./nvidia-couter-cmake