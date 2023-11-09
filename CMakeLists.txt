cmake_minimum_required(VERSION 3.22)
project(CallCenter)

set(CMAKE_CXX_STANDARD 17)

find_package(nlohmann_json 3.2.0 REQUIRED)

add_executable(CallCenter main.cpp
        include/config.h
        src/config.cpp
)

target_link_libraries(CallCenter PRIVATE nlohmann_json::nlohmann_json)

