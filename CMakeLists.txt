cmake_minimum_required(VERSION 3.14)
project(CAL_PROJ)

set(CMAKE_CXX_STANDARD 14)

add_executable(CAL_PROJ main.cpp src/Person.h src/Vehicle.h src/Person.cpp src/Vehicle.cpp src/Time.cpp src/Time.h src/Request.cpp src/Request.h src/Journey.cpp src/Journey.h src/Graph.h src/MutablePriorityQueue.h)

