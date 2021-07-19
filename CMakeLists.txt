#[[
cmake_minimum_required(VERSION 3.19)
project(CSCD437_CodeVulnerabilities C)

set(CMAKE_C_STANDARD 99)

add_executable(CSCD437_CodeVulnerabilities main.c a.c)]]

cmake_minimum_required(VERSION 3.5)
project(CSCD437_CodeVulnerabilities C)

add_executable(CSCD437_CodeVulnerabilities a.c)

include(../PVS-Studio.cmake)
pvs_studio_add_target(TARGET example1.analyze ALL
        OUTPUT FORMAT errorfile
        ANALYZE ${PROJECT_NAME}
        MODE GA:1,2
        LOG target.err)