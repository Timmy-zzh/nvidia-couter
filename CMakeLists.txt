cmake_minimum_required(VERSION 3.5)

# 项目目标：实现zmq跨进程通信，与audio服务进行通信 
project(NvidiaCouter)

include_directories(include)

add_executable(nvidia-couter-cmake main.cpp)