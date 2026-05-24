cmake_minimum_required(VERSION 3.16)

project(bthread_example CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(bthread_example example.cpp)

find_package(brpc CONFIG QUIET)

if(TARGET brpc::brpc)
  target_link_libraries(bthread_example PRIVATE brpc::brpc)
elseif(TARGET brpc)
  target_link_libraries(bthread_example PRIVATE brpc)
else()
  find_path(BRPC_INCLUDE_DIR
    NAMES bthread/bthread.h
    PATHS /opt/homebrew/opt/brpc/include /usr/local/opt/brpc/include
  )
  find_library(BRPC_LIBRARY
    NAMES brpc
    PATHS /opt/homebrew/opt/brpc/lib /usr/local/opt/brpc/lib
  )

  if(NOT BRPC_INCLUDE_DIR OR NOT BRPC_LIBRARY)
    message(FATAL_ERROR "Could not find bRPC. Install it with `brew install brpc`, or set brpc_DIR/CMAKE_PREFIX_PATH.")
  endif()

  target_include_directories(bthread_example PRIVATE ${BRPC_INCLUDE_DIR})
  target_link_libraries(bthread_example PRIVATE ${BRPC_LIBRARY})
endif()
