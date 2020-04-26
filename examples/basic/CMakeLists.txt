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
)

# Source files --------------------------------------------
set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/../deps/TimerThread/src/TimerThread.cxx
    ${CMAKE_CURRENT_SOURCE_DIR}/OSCOMutex.c
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

# Target definition ---------------------------------------
add_executable(${CMAKE_PROJECT_NAME}-basic
    ${SOURCES}
)
add_dependencies(${CMAKE_PROJECT_NAME}-basic
    ${CMAKE_PROJECT_NAME}
)
target_link_libraries(${CMAKE_PROJECT_NAME}-basic
    ${CMAKE_PROJECT_NAME}
    Threads::Threads
)
