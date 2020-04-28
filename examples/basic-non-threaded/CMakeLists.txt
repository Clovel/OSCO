# 
#                     Copyright (C) 2020 Clovis Durand
# 
# -----------------------------------------------------------------------------

# Definitions ---------------------------------------------
add_definitions(-DEXAMPLE_BASIC)

# Requirements --------------------------------------------

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

# Header files --------------------------------------------
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/../deps/TimerThread/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/../deps/can-ip/inc
)

# Source files --------------------------------------------
set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/../deps/TimerThread/src/TimerThread.cxx
    ${CMAKE_CURRENT_SOURCE_DIR}/OSCOMutex.c
    ${CMAKE_CURRENT_SOURCE_DIR}/CANDriverWrapper.c
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

message(STATUS "EXAMPLE BASIC SOURCES : ${SOURCES}")

# Target definition ---------------------------------------
add_executable(${CMAKE_PROJECT_NAME}-basic-non-threaded
    ${SOURCES}
)
add_dependencies(${CMAKE_PROJECT_NAME}-basic-non-threaded
    ${CMAKE_PROJECT_NAME}
    can-ip
)
target_link_libraries(${CMAKE_PROJECT_NAME}-basic-non-threaded
    ${CMAKE_PROJECT_NAME}
    Threads::Threads
    can-ip
)
