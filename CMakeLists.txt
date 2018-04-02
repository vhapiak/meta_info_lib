cmake_minimum_required(VERSION 3.3)

project(meta_info_lib)

add_library(mil INTERFACE)

target_include_directories(
    mil
    INTERFACE ${PROJECT_SOURCE_DIR}/include
)

add_subdirectory(test)

option(with_benchmarks "Build benchmarks" off)
if (with_benchmarks)
    add_subdirectory(benchmark)
endif()
