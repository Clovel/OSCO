# 
#                     Copyright (C) 2020 Clovis Durand
# 
# -----------------------------------------------------------------------------

# Include directories -------------------------------------
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/data/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/driver/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/statemachine/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/clock/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/sync/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/rxmgr/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/od/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/core/inc
)

# Subdirectories (OSCO modules) ---------------------------
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/data)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/driver)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/statemachine)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/clock)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/sync)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/rxmgr)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/od)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/core)
