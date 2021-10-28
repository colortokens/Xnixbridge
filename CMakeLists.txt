cmake_minimum_required (VERSION 3.2)

project (Xnixbridge)

set(CMAKE_CXX_STANDARD 14)

# Enable Control-Flow Integrity (CFI) ------------------------------------------

# TODO: Investigate the option(s) to enable cfi. Adding the recommended flag
#       -fsanitize=cfi results in the below "unsupported option" error.
#
# clang: error: unsupported option '-fsanitize=cfi'
# for target 'x86_64-apple-darwin19.6.0'

# set(X_CFI_FLAGS "-flto -fsanitize=cfi -fvisibility=default")
set(X_CFI_FLAGS "-flto -fvisibility=default")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${X_CFI_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${X_CFI_FLAGS}")

# ------------------------------------------------------------------------------

include_directories(
  src/main/include
)

add_library(Xnixbridge src/main/c/xnx/bridge/list.c)

file(GLOB XBHEADERS src/main/include/xnx/bridge/*.h)

set_target_properties(Xnixbridge PROPERTIES PUBLIC_HEADER "${XBHEADERS}")

add_executable(Xnixbridgetest src/test/c/Xnixbridgetest.cpp)
target_link_libraries(Xnixbridgetest INTERFACE xnx)

set_property(TARGET Xnixbridge PROPERTY XCODE_ATTRIBUTE_ENABLE_HARDENED_RUNTIME YES)

# Install necessary directory tree, libraries and binary -----------------------

install(TARGETS Xnixbridge LIBRARY DESTINATION lib PUBLIC_HEADER DESTINATION include/xnx/bridge)

# Uninstall the files installed by "make install" ------------------------------

if(NOT TARGET uninstall)
  configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/src/main/cmake/cmake_uninstall.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
    IMMEDIATE @ONLY)

  add_custom_target(uninstall
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)
endif()

# ------------------------------------------------------------------------------

