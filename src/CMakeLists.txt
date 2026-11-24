add_library(compmathlib
    find_root/bisection.cpp
    lin_alg/matrix/matrix.cpp
)

target_include_directories(compmathlib
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)