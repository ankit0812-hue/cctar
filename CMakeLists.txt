cmake_minimum_required(VERSION 3.1...3.29)
project(
  cctar_demo
  VERSION 1.0
  LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 14)
find_package(LibArchive REQUIRED)
add_executable(cctar
"main.cpp"
"src/utility.cpp"
"src/functions.cpp")
target_link_libraries(cctar LibArchive::LibArchive)
