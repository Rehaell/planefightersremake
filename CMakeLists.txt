cmake_minimum_required(VERSION 3.14)
project(PlaneFightersRemake)

# Define the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Download and install Raylib
include(FetchContent)
FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 5.0 # You can specify a specific tag, branch, or commit
)
FetchContent_GetProperties(raylib)

if(NOT raylib_POPULATED)
    FetchContent_Populate(raylib)
    add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
endif()

include(cmake/CopyAssets.cmake)
copy_assets(${CMAKE_CURRENT_BINARY_DIR}
    )

# Add the main executable
add_executable(PlaneFightersRemake main.cpp functions.cpp)

# Link Raylib to the project
target_link_libraries(PlaneFightersRemake raylib)

# Add the assets as a dependency
add_dependencies(PlaneFightersRemake copy_assets)


# Required for some platforms
if(APPLE)
    target_link_libraries(PlaneFightersRemake "-framework IOKit")
    target_link_libraries(PlaneFightersRemake "-framework Cocoa")
    target_link_libraries(PlaneFightersRemake "-framework OpenGL")
elseif(UNIX)
    list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")
endif()