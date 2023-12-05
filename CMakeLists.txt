cmake_minimum_required(VERSION 3.22)
project(CallCenter)

set(CMAKE_CXX_STANDARD 17)

find_package(nlohmann_json REQUIRED)
find_package(Boost REQUIRED)
find_package(GTest REQUIRED)

add_executable(CallCenter main.cpp
        src/Config.cpp
        src/NoSuchFileException.cpp
        src/CallHttpController.cpp
        src/JsonReaderImpl.cpp
        src/CallServiceImpl.cpp
        src/CallQueue.cpp
        src/CDRWriterImpl.cpp
        src/Operator.cpp
)
add_executable(Tests tests/AllTests.cpp
        src/JsonReaderImpl.cpp
        src/NoSuchFileException.cpp
        src/CallQueue.cpp
        src/Config.cpp)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
    target_link_libraries(Tests ${Boost_LIBRARIES})
endif()

enable_testing()

target_link_libraries(${PROJECT_NAME} nlohmann_json::nlohmann_json)
target_link_libraries(Tests GTest::gtest GTest::gtest_main nlohmann_json::nlohmann_json)