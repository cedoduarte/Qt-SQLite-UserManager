cmake_minimum_required(VERSION 3.14)

project(sha256jeremy LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_library(sha256jeremy SHARED
  sha256jeremy_global.h
  sha256jeremy.cpp sha256jeremy.h
  SHA256.h SHA256.cpp
)

target_link_libraries(sha256jeremy PRIVATE Qt${QT_VERSION_MAJOR}::Core)

target_compile_definitions(sha256jeremy PRIVATE SHA256JEREMY_LIBRARY)
