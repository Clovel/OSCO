# 
#                     Copyright (C) 2020 Clovis Durand
# 
# -----------------------------------------------------------------------------

# Definitions ---------------------------------------------
add_definitions(-DEXAMPLE_BASIC)

# Requirements --------------------------------------------

# Header files --------------------------------------------
file(GLOB_RECURSE PUBLIC_HEADERS 
    ${CMAKE_SOURCE_DIR}/dest/include/*.h
    ${CMAKE_SOURCE_DIR}/dest/include/*.hpp
)

set(HEADERS
    ${PUBLIC_HEADERS}
)

include_directories(
    ${CMAKE_SOURCE_DIR}/dest/include
)

# Source files --------------------------------------------
set(SOURCES
    ${CMAKE_SOURCE_DIR}/examples/basic/main.cpp
)

# Target definition ---------------------------------------
add_executable(${CMAKE_PROJECT_NAME}-basic
    ${SOURCES}
)
add_dependencies(${CMAKE_PROJECT_NAME}-basic ${CMAKE_PROJECT_NAME})
link_directories(${CMAKE_SOURCE_DIR}/dest/lib)
target_link_libraries(${CMAKE_PROJECT_NAME}-basic ${CMAKE_PROJECT_NAME})
