cmake_minimum_required(VERSION 3.16)

project(qt-workspace
    VERSION 1.0.0
    DESCRIPTION "Qt projects and experiments"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

add_subdirectory(apps/hello)
