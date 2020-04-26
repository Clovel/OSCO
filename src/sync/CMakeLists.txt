# 
#                     Copyright (C) 2020 Clovis Durand
# 
# -----------------------------------------------------------------------------

# Header files --------------------------------------------
file(GLOB_RECURSE PUBLIC_HEADERS
    ${CMAKE_SOURCE_DIR}/src/sync/inc/*.h
    ${CMAKE_SOURCE_DIR}/src/sync/inc/*.hpp
)

set(HEADERS
    ${PUBLIC_HEADERS}
)

include_directories(
    ${CMAKE_SOURCE_DIR}/src/sync/inc
    ${CMAKE_SOURCE_DIR}/src/clock/inc
    ${CMAKE_SOURCE_DIR}/src/driver/inc
)

# Source files --------------------------------------------
file(GLOB SOURCES
    ${CMAKE_SOURCE_DIR}/src/sync/src/*.c
    ${CMAKE_SOURCE_DIR}/src/sync/src/*.cpp
)

message("DRIVER SOURCES : ${SOURCES}")

# Link directories ----------------------------------------

# Target definition ---------------------------------------
add_library(${CMAKE_PROJECT_NAME}Sync
    ${SOURCES}
)
add_dependencies(${CMAKE_PROJECT_NAME}Sync
    ${CMAKE_PROJECT_NAME}Clock
    ${CMAKE_PROJECT_NAME}Driver
)
link_directories(${CMAKE_SOURCE_DIR}/dest/lib)
target_link_libraries(${CMAKE_PROJECT_NAME}Sync
    ${CMAKE_PROJECT_NAME}Clock
    ${CMAKE_PROJECT_NAME}Driver
)
#------------------------------------------------------------------------------
# pkgconfig
#------------------------------------------------------------------------------

#----------------------------------------------------------------------------
# The installation is prepended by the CMAKE_INSTALL_PREFIX variable
install(TARGETS ${CMAKE_PROJECT_NAME}Sync
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    PUBLIC_HEADER DESTINATION include
)
