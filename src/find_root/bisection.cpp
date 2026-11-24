#include <float.h>
#include <cmath>
#include <array>
#include "find_root/bisection.hpp"

namespace compmathlib{

Solution bisection(
    std::function<double(double)> f,
    Interval init_int,
    double abs_err,
    std::optional<int> max_iter
) {
    // Initialise Solution struct
    Solution result {
        DBL_MIN,
        {},
        "bisection",
        false,
        "Root found"
    };

    double a = init_int[0];
    double b = init_int[1];

    // Check that the interval is valid
    if (a>b){
        result.message = "Invalid interval: Start of interval is greater than the end";
        return result;

    /* This check only guarantees that there isn't an even number of roots in the interval.
    *  If f(a)*f(b) < 0.0 then this only guarantees that an odd number of roots are present,
    *  so care needs to be taken about the interval to avoid unwanted behaviour.
    */
    } else if (f(a)*f(b) > 0.0) {
        result.message = "Invalid interval: Interval does not contain a single root";
        return result;
    }

    // Calculate number of steps to achieve desired absolute error
    const int num_steps = std::ceil(std::log2((b - a)/abs_err));

    // Prevent loop starting if it will take too many steps
    if (max_iter.has_value() && num_steps > max_iter){
        result.message = "Number of steps exceeds maximum";
        return result;
    }

    // Perform bisection algorithm
    double c = a + 0.5*(b - a);
    for(int i = 1; i <= num_steps; i++){
        result.iters.push_back(c);

        double fc = f(c);
        double fa = f(a);
        if (fc == 0.0){
            result.root = c;
            break;
        } else if (fc*fa < 0.0) {
            b = c;
        } else {
            a = c;
        }

        c = a + 0.5*(b - a);
    }

    result.iters.push_back(c);
    result.root = c;
    result.root_found = true;

    return result;
}

}