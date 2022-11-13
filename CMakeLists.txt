cmake_minimum_required(VERSION 3.18)
project(csv_playground)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(abseil-cpp)

add_executable(csv_playground main.cpp line_reader.cpp)
target_link_libraries(csv_playground absl::strings)
