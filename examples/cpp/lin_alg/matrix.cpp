#include "lin_alg/matrix/matrix.hpp"

int main() {
    compmathlib::Matrix zeros = compmathlib::Matrix::zeros(4, 3);
    compmathlib::print_matrix(zeros);
    return 0;
}