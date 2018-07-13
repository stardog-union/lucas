cmake_minimum_required(VERSION 3.1)
project(lucas LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(lucas INTERFACE)
target_sources(lucas
  INTERFACE
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/lucas.h>
    $<INSTALL_INTERFACE:include/lucas.h>
)

add_executable(fib fib.cc)
target_link_libraries(fib lucas)
