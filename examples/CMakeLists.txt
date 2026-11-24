# Bisection example
add_executable(bisection_example
    cpp/find_root/bisection.cpp
)

set_target_properties(bisection_example PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin/find_root"
)

target_link_libraries(bisection_example
    PRIVATE compmathlib
)

# Matrix example
add_executable(matrix_example
    cpp/lin_alg/matrix.cpp
)

set_target_properties(matrix_example PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin/lin_alg"
)

target_link_libraries(matrix_example
    PRIVATE compmathlib
)