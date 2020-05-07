cmake_minimum_required(VERSION 3.14)
project(CAL_PROJ)

set(CMAKE_CXX_STANDARD 14)

add_executable(CAL_PROJ main.cpp src/Person.cpp src/Vehicle.cpp src/Time.cpp src/Request.cpp src/Journey.cpp graphViewer/connection.cpp graphViewer/graphviewer.cpp)

