# 
#                     Copyright (C) 2020 Clovis Durand
# 
# -----------------------------------------------------------------------------

# Header files --------------------------------------------
file(GLOB_RECURSE PUBLIC_HEADERS
    ${CMAKE_SOURCE_DIR}/inc/*.h
    ${CMAKE_SOURCE_DIR}/inc/*.hpp
)

set(HEADERS
    ${PUBLIC_HEADERS}
)

include_directories(
    ${CMAKE_SOURCE_DIR}/inc
)

# Source files --------------------------------------------
file(GLOB_RECURSE SOURCES
    ${CMAKE_SOURCE_DIR}/driver/*.c
    ${CMAKE_SOURCE_DIR}/driver/*.cpp

    ${CMAKE_SOURCE_DIR}/src/*.c
    ${CMAKE_SOURCE_DIR}/src/*.cpp
)

# Target definition ---------------------------------------
add_library(${CMAKE_PROJECT_NAME}
    ${SOURCES}
)
set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES PUBLIC_HEADER "${PUBLIC_HEADERS}")

# TODO : Link CAN Driver with pkg-config path
target_link_libraries(${CMAKE_PROJECT_NAME} can-ip)

#----------------------------------------------------------------------------
# The installation is prepended by the CMAKE_INSTALL_PREFIX variable
install(TARGETS ${CMAKE_PROJECT_NAME}
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    PUBLIC_HEADER DESTINATION include
)
