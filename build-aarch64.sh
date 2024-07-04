#!/bin/bash
###
 # @Descripttion:
###

TOOLCHAIN_PREFIX=aarch64-linux-gnu
PLATFORM_ABI=aarch64

mkdir -p build-aarch64 && cd build-aarch64
cmake -G "Unix Makefiles" .. \
      -DPLATFORM_ABI="${PLATFORM_ABI}" \
      -DCMAKE_SYSTEM_NAME=Linux \
      -DCMAKE_SYSTEM_VERSION=1 \
      -DCMAKE_SYSTEM_PROCESSOR=aarch64 \
      -DCMAKE_LINKER=${TOOLCHAIN_PREFIX}-ld \
      -DCMAKE_C_COMPILER=${TOOLCHAIN_PREFIX}-gcc \
      -DCMAKE_CXX_COMPILER=${TOOLCHAIN_PREFIX}-g++ \
      -DBUILD_TEST=OFF
make -j4

cd ..

# ./output/NvidiaCouter