# 
#                     Copyright (C) 2020 Clovis Durand
# 
# -----------------------------------------------------------------------------

# Header files --------------------------------------------
file(GLOB_RECURSE PUBLIC_HEADERS
    ${CMAKE_SOURCE_DIR}/src/od/inc/*.h
    ${CMAKE_SOURCE_DIR}/src/od/inc/*.hpp
)

set(HEADERS
    ${PUBLIC_HEADERS}
)

include_directories(
    ${CMAKE_SOURCE_DIR}/src/od/inc
)

# Source files --------------------------------------------
file(GLOB SOURCES
    ${CMAKE_SOURCE_DIR}/src/od/src/*.c
    ${CMAKE_SOURCE_DIR}/src/od/src/*.cpp
)

message("OD SOURCES : ${SOURCES}")

# Link directories ----------------------------------------

# Target definition ---------------------------------------
add_library(${CMAKE_PROJECT_NAME}OD SHARED
    ${SOURCES}
)
# add_dependencies(${CMAKE_PROJECT_NAME}OD
# )
link_directories(${CMAKE_SOURCE_DIR}/dest/lib)
# target_link_libraries(${CMAKE_PROJECT_NAME}OD
# )

#------------------------------------------------------------------------------
# pkgconfig
#------------------------------------------------------------------------------

#----------------------------------------------------------------------------
# The installation is prepended by the CMAKE_INSTALL_PREFIX variable
install(TARGETS ${CMAKE_PROJECT_NAME}OD
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    PUBLIC_HEADER DESTINATION include
)
