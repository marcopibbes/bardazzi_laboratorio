cmake_minimum_required(VERSION 3.22)
project(bardazzi_lab)

set(CMAKE_CXX_STANDARD 14)

add_executable(bardazzi_lab main.cpp Note.cpp Note.h Collection.cpp Collection.h Observer.cpp Observer.h Subject.cpp Subject.h Important.cpp Important.h)
