cmake_minimum_required(VERSION 3.9)
project(Demo)

set(CMAKE_CXX_STANDARD 14)

#ZLIB
find_package(ZLIB)

add_executable(
        ${PROJECT_NAME}
        Main.cpp
)

#ZLIB
target_link_libraries(${PROJECT_NAME}  ${ZLIB_LIBRARIES})