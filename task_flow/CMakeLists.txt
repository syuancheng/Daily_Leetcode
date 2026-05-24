cmake_minimum_required(VERSION 3.16)

project(task_flow CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(task_flow_core INTERFACE)
target_include_directories(task_flow_core INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

find_package(brpc CONFIG QUIET)

if(TARGET brpc::brpc)
  target_link_libraries(task_flow_core INTERFACE brpc::brpc)
elseif(TARGET brpc)
  target_link_libraries(task_flow_core INTERFACE brpc)
else()
  find_path(BRPC_INCLUDE_DIR
    NAMES butil/atomicops.h
    PATHS /opt/homebrew/opt/brpc/include /usr/local/opt/brpc/include
  )
  find_library(BRPC_LIBRARY
    NAMES brpc
    PATHS /opt/homebrew/opt/brpc/lib /usr/local/opt/brpc/lib
  )

  if(NOT BRPC_INCLUDE_DIR OR NOT BRPC_LIBRARY)
    message(FATAL_ERROR "Could not find bRPC. Install it with `brew install brpc`, or set brpc_DIR/CMAKE_PREFIX_PATH.")
  endif()

  target_include_directories(task_flow_core INTERFACE ${BRPC_INCLUDE_DIR})
  target_link_libraries(task_flow_core INTERFACE ${BRPC_LIBRARY})
endif()

add_subdirectory(bthread)
