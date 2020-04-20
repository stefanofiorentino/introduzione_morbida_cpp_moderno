cmake_minimum_required(VERSION 3.15)
project(morbida_01)

set(CMAKE_CXX_STANDARD 17)

option(USE_UBSAN "Use address sanitizer by adding -fsanitize=undefined -fno-sanitize-recover=all -fno-omit-frame-pointer flags" OFF)

add_executable(morbida_01 main.cpp)

if(USE_UBSAN)
    target_compile_options(morbida_01 PUBLIC $<$<CONFIG:Debug>:-fsanitize=undefined -fno-sanitize-recover=all -fno-omit-frame-pointer>)
    target_link_libraries(morbida_01 PUBLIC $<$<CONFIG:Debug>:-fsanitize=undefined>)
endif()