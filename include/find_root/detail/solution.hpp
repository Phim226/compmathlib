#pragma once

#include <vector>
#include <string>

/**
 * @brief Struct containing information about the result of an iterative numerical method.
 */
struct Solution {
    double root;
    std::vector<double> iters;
    std::string method;
    bool root_found;
    std::string message;
};