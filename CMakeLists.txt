cmake_minimum_required(VERSION 3.5)

set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(ls004)

#флаги компилятора
#target_compile_options()

add_subdirectory(src)
#add_subdirectory(dyn_lib)
#add_subdirectory(sta_lib)

