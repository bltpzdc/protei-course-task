cmake_minimum_required(VERSION 3.22)
project(CallCenter)

set(CMAKE_CXX_STANDARD 17)

find_package(nlohmann_json REQUIRED)
find_package(Boost REQUIRED)

add_executable(CallCenter main.cpp
        include/Config.h
        src/Config.cpp
        src/NoSuchFileException.cpp
        src/CallHttpController.cpp
        src/JsonReaderImpl.cpp
        src/CallServiceImpl.cpp
        src/CallQueue.cpp
        src/CDRWriterImpl.cpp
        src/Operator.cpp
)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
endif()

target_link_libraries(${PROJECT_NAME} nlohmann_json::nlohmann_json)

