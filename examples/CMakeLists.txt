add_executable(bisection_example
    cpp/find_root/bisection.cpp
)

set_target_properties(bisection_example PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin/find_root"
)

target_link_libraries(bisection_example
    PRIVATE compmathlib
)