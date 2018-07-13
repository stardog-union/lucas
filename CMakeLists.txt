cmake_minimum_required(VERSION 3.1)

set(default_build_type "Release")
if(CMAKE_BUILD_TYPE)
  message(STATUS "Build type is '${CMAKE_BUILD_TYPE}'.")
else()
  message(STATUS "Setting build type to '${default_build_type}'.")
  set(CMAKE_BUILD_TYPE "${default_build_type}" CACHE STRING "Build type (default ${default_build_type})" FORCE)
endif()

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)


#######################################
# RocksDB Required OS flags
########################################
if (CMAKE_SYSTEM_NAME MATCHES "Darwin")
    add_definitions(-DOS_MACOSX)
endif ()


#######################################
# Build fib
#######################################

set(FIB_COMMON_FLAGS "-Wall -Werror=reorder -Wno-unused-function -pedantic -Wno-unknown-pragmas -Wno-vla -pthread -U_FORTIFY_SOURCE -fno-omit-frame-pointer -fno-common")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_DEBUG} ${FIB_COMMON_FLAGS}")
set(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS_DEBUG} ${FIB_COMMON_FLAGS}")

add_library(lucas INTERFACE)
target_include_directories(lucas INTERFACE lucas.h)

add_executable(fib fib.cc)
target_link_libraries(fib lucas)

install(TARGETS lucas EXPORT lucas_proj DESTINATION include)
install(EXPORT lucas_proj NAMESPACE lucas_ DESTINATION lib/lucas)
