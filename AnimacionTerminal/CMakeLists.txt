
cmake_minimum_required(VERSION 3.10)

project(AnimacionTerminal CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(ftxui REQUIRED)

add_executable(animacion main.cpp)

target_link_libraries(animacion PRIVATE ftxui::screen ftxui::dom)
