# 设置 CMake 最低版本要求
cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(nb_tcp)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加可执行文件
add_executable(nb_tcp_app src/main.cpp src/tuntap.cpp)

# 包含头文件目录
target_include_directories(nb_tcp_app PRIVATE ${CMAKE_SOURCE_DIR}/include)
