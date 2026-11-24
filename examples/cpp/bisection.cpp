#include "find_root/bisection.hpp"
#include <math.h>
#include <stdio.h>

double f(double x) {
    return x - 1;
}

int main() {
    Solution sol = compmathlib::bisection(f, {0.8, 1.13}, 0.001);

    printf("root at %f\n", sol.root);
    return 0;
}