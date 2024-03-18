
include_directories(${PROJECT_SOURCE_DIR}/include/FirstGame)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SRC_LIST)
add_executable(FirstGame ${SRC_LIST})