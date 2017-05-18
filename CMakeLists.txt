cmake_minimum_required(VERSION 3.7)
project(Ex3)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES
        set.h
        list.h
        Order.c
        Company.c
        Room.c
        mtm_ex3.h
        Escaper.c
        )

SET(GCC_COVERAGE_COMPILE_FLAGS "-Wall -pedantic-errors -Werror -DNDEBUG")
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
link_directories(.)
add_executable(Ex3 ${SOURCE_FILES})
target_link_libraries (Ex3 libmtm.a)