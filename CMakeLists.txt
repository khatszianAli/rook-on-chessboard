cmake_minimum_required(VERSION 3.27)
project(chessboard_with_rook_with_qt LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()


qt_add_executable(rook rook.cpp)
target_link_libraries(rook PRIVATE Qt6::Widgets)

