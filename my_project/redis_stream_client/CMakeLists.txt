cmake_minimum_required(VERSION 2.6)
#创建工程
project(redis_stream_client)
set(CMAKE_CXX_FLAGS "-std=c++11")

include_directories(/usr/local/include/hiredis)
link_directories(/usr/local/lib)

add_executable(app main.cpp redis_tool.cpp) #将程序生成可执行文件
target_link_libraries(app hiredis) #链接lib文件到可执行文件中