# 
#                     Copyright (C) 2020 Clovis Durand
# 
# -----------------------------------------------------------------------------

# The Core module is in fact the whole OSCO stack 
# once the other modules are linked.

# Header files --------------------------------------------
file(GLOB PUBLIC_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/inc/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/inc/*.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../../inc/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../inc/*.hpp
)

set(HEADERS
    ${PUBLIC_HEADERS}
)

# Source files --------------------------------------------
file(GLOB SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

message("CORE SOURCES : ${SOURCES}")

# Target definition ---------------------------------------
add_library(${CMAKE_PROJECT_NAME}
    ${SOURCES}
)

add_dependencies(${CMAKE_PROJECT_NAME}
    ${CMAKE_PROJECT_NAME}Data
    ${CMAKE_PROJECT_NAME}Driver
    ${CMAKE_PROJECT_NAME}StateMachine
    ${CMAKE_PROJECT_NAME}Clock
    ${CMAKE_PROJECT_NAME}Sync
    ${CMAKE_PROJECT_NAME}RxMgr
    ${CMAKE_PROJECT_NAME}OD
    ${CMAKE_PROJECT_NAME}GenOD
)

target_link_libraries(${CMAKE_PROJECT_NAME}
    ${CMAKE_PROJECT_NAME}Data
    ${CMAKE_PROJECT_NAME}Driver
    ${CMAKE_PROJECT_NAME}StateMachine
    ${CMAKE_PROJECT_NAME}Clock
    ${CMAKE_PROJECT_NAME}Sync
    ${CMAKE_PROJECT_NAME}RxMgr
    ${CMAKE_PROJECT_NAME}OD
    ${CMAKE_PROJECT_NAME}GenOD
)
set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES 
    PUBLIC_HEADER "${PUBLIC_HEADERS}"
)

#----------------------------------------------------------------------------
# The installation is prepended by the CMAKE_INSTALL_PREFIX variable
install(TARGETS ${CMAKE_PROJECT_NAME}
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    PUBLIC_HEADER DESTINATION include
)
