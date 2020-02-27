# 
#                     Copyright (C) 2020 Clovis Durand
# 
# -----------------------------------------------------------------------------

# Header files --------------------------------------------
file(GLOB_RECURSE PUBLIC_HEADERS
    ${CMAKE_SOURCE_DIR}/src/driver/inc/*.h
    ${CMAKE_SOURCE_DIR}/src/driver/inc/*.hpp
)

set(HEADERS
    ${PUBLIC_HEADERS}
)

include_directories(
    ${CMAKE_SOURCE_DIR}/src/driver/inc
    ${CMAKE_SOURCE_DIR}/src/rxmgr/inc
)

# Source files --------------------------------------------
file(GLOB SOURCES
    ${CMAKE_SOURCE_DIR}/src/driver/src/*.c
    ${CMAKE_SOURCE_DIR}/src/driver/src/*.cpp
)

message("DRIVER SOURCES : ${SOURCES}")

# Link directories ----------------------------------------

# Target definition ---------------------------------------
add_library(${CMAKE_PROJECT_NAME}Driver
    ${SOURCES}
)
add_dependencies(${CMAKE_PROJECT_NAME}Driver
    ${CMAKE_PROJECT_NAME}RxMgr
)
target_link_libraries(${CMAKE_PROJECT_NAME}Driver
    ${CMAKE_PROJECT_NAME}RxMgr
    can-ip # YOUR DRIVER LIBRARY HERE
)

#------------------------------------------------------------------------------
# pkgconfig
#------------------------------------------------------------------------------

#----------------------------------------------------------------------------
# The installation is prepended by the CMAKE_INSTALL_PREFIX variable
install(TARGETS ${CMAKE_PROJECT_NAME}Driver
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    PUBLIC_HEADER DESTINATION include
)
