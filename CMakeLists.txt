cmake_minimum_required(VERSION 3.16)
project(open_cv_demo)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(./src)

set(src_dir_list_files ./src/*.cpp ./src/*.h
        )
file(GLOB_RECURSE SOURCES ${src_dir_list_files})

message(---Debug Echo---)
foreach(src_file ${SOURCES})
    message(src_file=${src_file})
endforeach()

add_executable(open_cv_demo ${SOURCES})

find_package(OpenCV REQUIRED)
target_link_libraries(open_cv_demo ${OpenCV_LIBS})