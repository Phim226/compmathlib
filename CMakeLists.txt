cmake_minimum_required(VERSION 3.28)

project(
    compmathlib
    VERSION 0.1.0
)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(compmathlib
    src/find_root/bisection.cpp
    src/lin_alg/matrix/matrix.cpp
)

target_include_directories(compmathlib
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

# Bisection example executable
add_executable(bisection_example
    examples/cpp/bisection.cpp
)

target_link_libraries(bisection_example
    PRIVATE compmathlib
)