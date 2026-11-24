#include "lin_alg/matrix/matrix.hpp"
#include <iostream>

int main() {
    // Initialise some basic matrices
    compmathlib::Matrix zeros = compmathlib::Matrix::zeros(4, 3);
    compmathlib::print_matrix(zeros);

    std::cout << std::endl;
    compmathlib::Matrix ones = compmathlib::Matrix::ones(2, 2);
    compmathlib::print_matrix(ones);

    std::cout << std::endl;
    compmathlib::Matrix constant = compmathlib::Matrix::constant(2, 3, 4);
    compmathlib::print_matrix(constant);

    std::cout << std::endl;
    compmathlib::Matrix A = compmathlib::Matrix({{2, 3}, {4, 2}});
    compmathlib::print_matrix(A);

    // Retrieve column vector
    std::cout << std::endl;
    std::vector<double> col = A.col(1);
    for (double c : col) {
        std::cout << c << " " << std::endl;
    }
    return 0;
}