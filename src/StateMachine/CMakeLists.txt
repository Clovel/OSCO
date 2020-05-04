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

message("STATE_MACHINE SOURCES : ${SOURCES}")

# Target definition ---------------------------------------
add_library(${CMAKE_PROJECT_NAME}StateMachine
    ${SOURCES}
)

add_dependencies(${CMAKE_PROJECT_NAME}StateMachine
    ${CMAKE_PROJECT_NAME}Driver
)

target_link_libraries(${CMAKE_PROJECT_NAME}StateMachine
    ${CMAKE_PROJECT_NAME}Driver
)

#----------------------------------------------------------------------------
# The installation is prepended by the CMAKE_INSTALL_PREFIX variable
install(TARGETS ${CMAKE_PROJECT_NAME}StateMachine
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    PUBLIC_HEADER DESTINATION include
)
