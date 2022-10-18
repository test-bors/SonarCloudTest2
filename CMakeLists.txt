cmake_minimum_required(VERSION 3.0)
set(CMAKE_FIND_PACKAGE_PREFER_CONFIG ON)

project(test_SonarCloud)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(source_files
  main.cpp
)

add_executable(${PROJECT_NAME} ${source_files})
