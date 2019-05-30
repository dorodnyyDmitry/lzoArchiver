cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

project(untitled2 LANGUAGES CXX)
add_executable(${PROJECT_NAME} "main.cpp" "compressor.hpp" "compressor.cpp" "utility.cpp" "utility.hpp" "mainwindow.cpp" "mainwindow.hpp" "mainwindow.ui")

set_target_properties(${PROJECT_NAME} PROPERTIES
    AUTOMOC ON
    AUTOUIC ON
    AUTORCC ON
    )

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

find_package(Qt5 REQUIRED COMPONENTS Widgets)

include(FindPkgConfig)
pkg_check_modules(lzolib REQUIRED IMPORTED_TARGET lzo2)
target_link_libraries(${PROJECT_NAME} PRIVATE PkgConfig::lzolib Qt5::Widgets)
