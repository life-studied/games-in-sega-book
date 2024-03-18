cmake_minimum_required(VERSION 3.25)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(Games
        VERSION 2024.3
        PROJECT_DESCRIPTION "Games from book"
        LANGUAGES C CXX)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release")
if (CMAKE_BUILD_TYPE MATCHES "(Debug)|(Release)")
    message("Current build type: ${CMAKE_BUILD_TYPE}")
else()
    message("Set default buile type to Debug.")
    set(CMAKE_BUILD_TYPE "Debug")
endif()

set(PROJECT_BINARY_DIR ${PROJECT_SOURCE_DIR}/bin)

execute_process(COMMAND cp -r ./configs ${PROJECT_BINARY_DIR}/configs
                WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
                TIMEOUT 3
                RESULT_VARIABLE result_var)

add_subdirectory(src/FirstGame)

