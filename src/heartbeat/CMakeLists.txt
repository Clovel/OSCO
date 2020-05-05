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

message("HEARTBEAT SOURCES : ${SOURCES}")

# Target definition ---------------------------------------
add_library(${CMAKE_PROJECT_NAME}Heartbeat
    ${SOURCES}
)

add_dependencies(${CMAKE_PROJECT_NAME}Heartbeat
    ${CMAKE_PROJECT_NAME}Data
    ${CMAKE_PROJECT_NAME}Driver
    ${CMAKE_PROJECT_NAME}StateMachine
    ${CMAKE_PROJECT_NAME}Clock
)

target_link_libraries(${CMAKE_PROJECT_NAME}Heartbeat
    ${CMAKE_PROJECT_NAME}Data
    ${CMAKE_PROJECT_NAME}Driver
    ${CMAKE_PROJECT_NAME}StateMachine
    ${CMAKE_PROJECT_NAME}Clock
)

#----------------------------------------------------------------------------
# The installation is prepended by the CMAKE_INSTALL_PREFIX variable
install(TARGETS ${CMAKE_PROJECT_NAME}Heartbeat
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    PUBLIC_HEADER DESTINATION include
)
