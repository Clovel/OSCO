# 
#                     Copyright (C) 2020 Clovis Durand
# 
# -----------------------------------------------------------------------------

# Header files --------------------------------------------
file(GLOB_RECURSE PUBLIC_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/inc/*.h
)

set(HEADERS
    ${PUBLIC_HEADERS}
)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/od/inc
)

# Source files --------------------------------------------
file(GLOB SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c
)

message("Generated OD SOURCES : ${SOURCES}")

# Link directories ----------------------------------------

# Target definition ---------------------------------------
add_library(${CMAKE_PROJECT_NAME}GenOD
    ${SOURCES}
)

#----------------------------------------------------------------------------
# The installation is prepended by the CMAKE_INSTALL_PREFIX variable
install(TARGETS ${CMAKE_PROJECT_NAME}GenOD
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    PUBLIC_HEADER DESTINATION include
)
