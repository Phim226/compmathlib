#include "lin_alg/matrix/matrix.hpp"
#include <iostream>

int main() {
    compmathlib::Matrix zeros = compmathlib::Matrix::zeros(4, 3);
    compmathlib::print_matrix(zeros);

    std::cout << std::endl;
    compmathlib::Matrix ones = compmathlib::Matrix::ones(2, 2);
    compmathlib::print_matrix(ones);

    std::cout << std::endl;
    compmathlib::Matrix constant = compmathlib::Matrix::constant(2, 2, 4);
    compmathlib::print_matrix(constant);
    return 0;
}