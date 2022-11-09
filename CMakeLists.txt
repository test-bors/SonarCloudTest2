cmake_minimum_required(VERSION 3.0)
set(CMAKE_FIND_PACKAGE_PREFER_CONFIG ON)

project(SonarCloudTest)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(source_files
  main.cpp
)

add_executable(${PROJECT_NAME} ${source_files})
