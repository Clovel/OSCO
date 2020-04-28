# 
#                     Copyright (C) 2020 Clovis Durand
# 
# -----------------------------------------------------------------------------

# Definitions ---------------------------------------------
add_definitions(-DEXAMPLE)

# Sub-modules ---------------------------------------------
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/deps/can-ip)

# Sub-directories -----------------------------------------
add_subdirectory(basic)
add_subdirectory(basic-non-threaded)
