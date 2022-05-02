cmake_minimum_required(VERSION 3.22)
project(bardazzi_lab)

set(CMAKE_CXX_STANDARD 14)

add_executable(bardazzi_lab main.cpp Note.cpp Note.h Collection.cpp Collection.h Observer.cpp Observer.h Subject.cpp Subject.h Important.cpp Important.h Google_tests/NoteTest.cpp Google_tests/runAllTests.cpp Google_tests/CollectionTest.cpp Google_tests/ImportantTest.cpp)
add_subdirectory(Google_tests)
