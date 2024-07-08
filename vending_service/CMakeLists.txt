cmake_minimum_required(VERSION 2.8.3)

set(vending_service ${PROJECT_SOURCE_DIR}/vending_service/ZmqServiceDemo.cpp 
                    ${PROJECT_SOURCE_DIR}/vending_service/ZmqServiceCall.cpp
                    )

SET(VENDING_SERVICE_FILES ${vending_service} PARENT_SCOPE)