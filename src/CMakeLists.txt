# 
#                     Copyright (C) 2020 Clovis Durand
# 
# -----------------------------------------------------------------------------

# Subdirectories (OSCO modules) ---------------------------
add_subdirectory(rxmgr)
add_subdirectory(driver)
add_subdirectory(clock)
add_subdirectory(sync)
add_subdirectory(od)

# Header files --------------------------------------------
file(GLOB PUBLIC_HEADERS
    ${CMAKE_SOURCE_DIR}/inc/*.h
    ${CMAKE_SOURCE_DIR}/inc/*.hpp
)

file(GLOB_RECURSE MODULE_HEADERS
    ${CMAKE_SOURCE_DIR}/src/*.h
    ${CMAKE_SOURCE_DIR}/src/*.hpp
)

set(HEADERS
    ${PUBLIC_HEADERS}
    ${MODULE_HEADERS}
)

include_directories(
    ${CMAKE_SOURCE_DIR}/inc
    ${CMAKE_SOURCE_DIR}/src/driver/inc
    ${CMAKE_SOURCE_DIR}/src/clock/inc
    ${CMAKE_SOURCE_DIR}/src/sync/inc
    ${CMAKE_SOURCE_DIR}/src/rxmgr/inc
    ${CMAKE_SOURCE_DIR}/src/od/inc
)

# Source files --------------------------------------------
file(GLOB SOURCES
    ${CMAKE_SOURCE_DIR}/src/*.c
    ${CMAKE_SOURCE_DIR}/src/*.cpp
)

message("MAIN SOURCES : ${SOURCES}")

# Link directories ----------------------------------------

# Target definition ---------------------------------------
add_library(${CMAKE_PROJECT_NAME} SHARED
    ${SOURCES}
)
add_dependencies(${CMAKE_PROJECT_NAME}
    ${CMAKE_PROJECT_NAME}Driver
    ${CMAKE_PROJECT_NAME}Clock
    ${CMAKE_PROJECT_NAME}Sync
    ${CMAKE_PROJECT_NAME}RxMgr
    ${CMAKE_PROJECT_NAME}OD
)
target_link_libraries(${CMAKE_PROJECT_NAME}
    ${CMAKE_PROJECT_NAME}Driver
    ${CMAKE_PROJECT_NAME}Clock
    ${CMAKE_PROJECT_NAME}Sync
    ${CMAKE_PROJECT_NAME}RxMgr
    ${CMAKE_PROJECT_NAME}OD
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
