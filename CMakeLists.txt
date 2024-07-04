# 指定CMake的最小版本要求  
cmake_minimum_required(VERSION 3.5)

########## 项目目标：实现zmq跨进程通信，与audio服务进行通信 

# 设置项目名称  
project(NvidiaCouter)

# 添加全局编译定义  
add_definitions("-O3 -Wall -fPIC -Wno-unused-result")  
# 设置C++编译标准为C++11  
add_compile_options(-std=c++11)  
  
# 添加额外的编译器标志  
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-builtin-macro-redefined")  
  
# 设置CMake模块路径，以便找到自定义的Find模块  
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" "${CMAKE_MODULE_PATH}")  

# 查找并包含Algocc库（这可能是一个自定义的或第三方库）  
find_package(Algocc REQUIRED)  

# 尝试根据项目源目录的名称设置Algocc的路径  -- 找打了Algocc项目的路径
get_filename_component(DIR_NAME ${PROJECT_SOURCE_DIR} NAME)  
string(REPLACE ${DIR_NAME} "algocc" PROJECT_ALGOCC_PATH ${PROJECT_SOURCE_DIR})  

# 添加子目录到项目中，这些子目录包含更多的CMakeLists.txt文件  
add_subdirectory(vending_client)  
add_subdirectory(vending_service)  
add_subdirectory(utils)  

# 设置Algocc、ZeroMQ和Jsoncpp的根目录  
set(AlgoccHome ${PROJECT_ALGOCC_PATH})  
set(ZeromqHome ${AlgoccHome}/zeromq)  
set(JsoncppHome ${AlgoccHome}/jsoncpp)   
message("AlgoccHome -----------" ${AlgoccHome})
message("ZeromqHome -----------" ${ZeromqHome})
message("JsoncppHome -----------" ${JsoncppHome})
  
# 调用自定义的algocc_add_include函数来添加Algocc相关的包含目录  
algocc_add_include(${AlgoccHome})  

# 添加全局包含目录,所有的.h文件
include_directories(${PROJECT_SOURCE_DIR}/vending_client  
                    ${PROJECT_SOURCE_DIR}/vending_service    
                    ${PROJECT_SOURCE_DIR}/utils  
                    ${ZeromqHome}/include  
                    ${JsoncppHome}/include
                    )  

# 添加库目录到链接器搜索路径  
link_directories(${AlgoccHome}/libs/${PLATFORM_ABI}  
                 ${ZeromqHome}/libs/${PLATFORM_ABI}  
                 ${JsoncppHome}/libs/${PLATFORM_ABI}  
                )  

# 设置一些常用的库  
set(COMMON_LIBS algocc zmq jsoncpp pthread dl)  

# 设置主程序文件  
set(MAIN_FILES main.cpp ${VENDING_CLIENT_FILES})  

# 添加可执行文件  
add_executable(${PROJECT_NAME} ${MAIN_FILES})  
# 链接主程序所需的库  
target_link_libraries(${PROJECT_NAME} ${COMMON_LIBS} ${UDEV_LIBRARIES})  

# 添加一个共享库dwcamera  
# add_library(dwcamera SHARED ${RPC_CLIENT_FILE}  
#                            ${SHA_MEM_FILE})  
# # 链接dwcamera库所需的库  
# target_link_libraries(dwcamera ${COMMON_LIBS})  

# # 如果设置了BUILD_TEST，则添加客户端测试  
# if (BUILD_TEST)  
#     # 添加一个可执行文件cameraclient  
#     add_executable(cameraclient ${RPC_CLIENT_MAIN})  
#     # 链接cameraclient所需的库  
#     target_link_libraries(cameraclient dwcamera)  
  
#     # 添加另一个测试程序  
#     add_executable(test_wechat_qrcode test/test_wechat_qrcode.cpp)  
#     # 链接test_wechat_qrcode所需的库  
#     target_link_libraries(test_wechat_qrcode ${OPENCV_LIBRARIES})  
# endif() 


## install
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/output)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/output)
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${PROJECT_SOURCE_DIR})