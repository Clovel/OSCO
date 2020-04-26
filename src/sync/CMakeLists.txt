# 
#                     Copyright (C) 2020 Clovis Durand
# 
# -----------------------------------------------------------------------------

# Header files --------------------------------------------
file(GLOB_RECURSE PUBLIC_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/inc/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/inc/*.hpp
)

set(HEADERS
    ${PUBLIC_HEADERS}
)

# Source files --------------------------------------------
file(GLOB SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

message("SYNC SOURCES : ${SOURCES}")

# Link directories ----------------------------------------

# Target definition ---------------------------------------
add_library(${CMAKE_PROJECT_NAME}Sync
    ${SOURCES}
)
add_dependencies(${CMAKE_PROJECT_NAME}Sync
    ${CMAKE_PROJECT_NAME}Clock
    ${CMAKE_PROJECT_NAME}Driver
)
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
    PUBLIC_HEADER DESTINATION include
)
