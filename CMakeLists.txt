cmake_minimum_required(VERSION 3.10)
project(CODA_algorithm)

set(CMAKE_CXX_STANDARD 17)

# 현재 폴더의 모든 cpp 파일 찾아서 각각 실행파일로 만들기
file(GLOB SRC_FILES "*.cpp")

foreach(src ${SRC_FILES})
    get_filename_component(exe ${src} NAME_WE)
    add_executable(${exe} ${src})
endforeach()