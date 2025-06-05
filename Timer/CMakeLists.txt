cmake_minimum_required(VERSION 3.10)
project(timer C)

set(CMAKE_C_STANDARD 11)

# 1) Указываем, что собранный бинарник и копия .exe окажутся в корне проекта
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

# 2) Создаём таргет timer из main.c
add_executable(timer main.c)

# 3) После сборки создаём копию timer -> timer.exe в PROJECT_SOURCE_DIR
add_custom_command(TARGET timer POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        "${PROJECT_SOURCE_DIR}/timer"
        "${PROJECT_SOURCE_DIR}/timer.exe"
)

# 4) При конфигурации (cmake) сразу генерируем скрипт run_timer.sh в PROJECT_SOURCE_DIR
file(WRITE "${PROJECT_SOURCE_DIR}/run_timer.sh"
        "#!/bin/bash\n"
        "\"${PROJECT_SOURCE_DIR}/timer\"\n"
)
file(CHMOD "${PROJECT_SOURCE_DIR}/run_timer.sh"
        PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE
        GROUP_READ GROUP_EXECUTE
        WORLD_READ WORLD_EXECUTE
)
