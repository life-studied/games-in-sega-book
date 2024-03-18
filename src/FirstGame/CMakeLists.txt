
include_directories(${PROJECT_SOURCE_DIR}/include/FirstGame)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SRC_LIST)
add_executable(FirstGame ${SRC_LIST})

message("execute command: copy FirstGame config")
execute_process(COMMAND cp ${PROJECT_SOURCE_DIR}/configs/FirstGame/map* ${EXECUTABLE_OUTPUT_PATH}/configs/*
                WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
                TIMEOUT 3
                RESULT_VARIABLE result_var)
message("execute result: ${result_var} ${PROJECT_SOURCE_DIR}/configs/FirstGame/map*")