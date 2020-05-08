cmake_minimum_required(VERSION 3.14)
project(MeetupRider)

set(CMAKE_CXX_STANDARD 14)
link_libraries(ws2_32 wsock32)


file(GLOB_RECURSE SRC "src/*.cpp" "src/*.h")
add_executable(MeetupRider main.cpp ${SRC} )