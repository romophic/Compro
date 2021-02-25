cmake_minimum_required(VERSION 3.8)
project("Compro")

add_executable("main" "src/main")
add_compile_definitions(DEBUG)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
