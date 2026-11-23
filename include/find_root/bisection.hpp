#include "find_root/detail/solution.hpp"
#include <optional>
#include <functional>

using Interval = std::array<double, 2>;

/**
* @brief Finds roots of continuous functions using the bisection method. Care should be taken to ensure that the initial interval contains only a single root.
*
* @param f        The function being solved
* @param init_int Initial interval containing a single root
* @param abs_err  The desired absolute error
* @param max_iter The maximum number of iterations (optional)
*
* @return A Solution object containing root and iteration information
*/
Solution bisection(
    std::function<double(double)> f,
    Interval init_int,
    double abs_err,
    std::optional<int> max_iter = std::nullopt
);