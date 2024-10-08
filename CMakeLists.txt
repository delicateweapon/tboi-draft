cmake_minimum_required(VERSION 3.28)
project(tboi C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_FLAGS "-Wall -Wextra -Wpedantic -Werror -std=c2x")
set(CMAKE_C_DEBUG_FLAGS "${CMAKE_C_FLAGS} -g -pg -fsanitize=address")
set(CMAKE_C_RELEASE_FLAGS "${CMAKE_C_FLAGS} -O3")
set(CMAKE_C_LINK_FLAGS "-fuse-ld=mold")

file(GLOB SOURCE_FILES src/*/*.c src/*.c)

add_executable(tboi ${SOURCE_FILES})

set_target_properties(tboi PROPERTIES
    COMPILE_FLAGS "${CMAKE_C_FLAGS}"
)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set_target_properties(tboi PROPERTIES
        COMPILE_FLAGS "${CMAKE_C_DEBUG_FLAGS}"
    )
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    set_target_properties(tboi PROPERTIES
        COMPILE_FLAGS "${CMAKE_C_RELEASE_FLAGS}"
    )
endif()

target_link_libraries(tboi PRIVATE m SDL3 GL)
