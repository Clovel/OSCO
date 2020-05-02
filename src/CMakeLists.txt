# 
#                     Copyright (C) 2020 Clovis Durand
# 
# -----------------------------------------------------------------------------

# Include directories -------------------------------------
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/driver/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/statemachine/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/clock/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/sync/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/rxmgr/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/od/inc
)

# Subdirectories (OSCO modules) ---------------------------
add_subdirectory(driver)
add_subdirectory(statemachine)
add_subdirectory(clock)
add_subdirectory(sync)
add_subdirectory(rxmgr)
add_subdirectory(od)

# Header files --------------------------------------------
file(GLOB PUBLIC_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/../inc/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../inc/*.hpp
)

file(GLOB_RECURSE MODULE_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp
)

set(HEADERS
    ${PUBLIC_HEADERS}
    ${MODULE_HEADERS}
)

# Source files --------------------------------------------
file(GLOB SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

message("MAIN SOURCES : ${SOURCES}")

# Link directories ----------------------------------------

# Target definition ---------------------------------------
add_library(${CMAKE_PROJECT_NAME}
    ${SOURCES}
)

add_dependencies(${CMAKE_PROJECT_NAME}
    ${CMAKE_PROJECT_NAME}Driver
    ${CMAKE_PROJECT_NAME}StateMachine
    ${CMAKE_PROJECT_NAME}Clock
    ${CMAKE_PROJECT_NAME}Sync
    ${CMAKE_PROJECT_NAME}RxMgr
    ${CMAKE_PROJECT_NAME}OD
    ${CMAKE_PROJECT_NAME}GenOD
)

target_link_libraries(${CMAKE_PROJECT_NAME}
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
    PUBLIC_HEADER DESTINATION include
)
