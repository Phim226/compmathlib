#include "lin_alg/matrix/matrix.hpp"
#include <stdexcept>

namespace compmathlib{

Matrix::Matrix(std::vector<std::vector<double>> data) {
    // Check rows all have the same length
    size_t row_length = data[0].size();
    for (std::vector<double> v : data) {
        if (v.size() != row_length) {
            throw std::invalid_argument(
                "Rows must all be the same length"
            );
        }
    }

    // Check input data isn't empty
    if (data.empty()) {
        throw std::invalid_argument(
            "Matrix cannot be empty"
        );
    } else if (data[0].empty()) {
        throw std::invalid_argument(
            "Rows cannot be empty"
        );
    }


    this->data = data;
    this->matrix_size = {data.size(), data[0].size()};
}


Matrix Matrix::constant(std::size_t rows, std::size_t cols, double num) {
    std::vector<double> r(cols, num);
    std::vector<std::vector<double>> data(rows, r);
    return Matrix(data);
}

Matrix Matrix::zeros(std::size_t rows, std::size_t cols) {
    return Matrix::constant(rows, cols, 0);
}

Matrix Matrix::ones(std::size_t rows, std::size_t cols) {
    return Matrix::constant(rows, cols, 1);
}

MatrixSize Matrix::size() {
    return this->matrix_size;
}

std::vector<double>& Matrix::operator[](std::size_t i) {
    return data.at(i);
}

const std::vector<double>& Matrix::operator[](std::size_t i) const {
    return data.at(i);
}

double dot(const std::vector<double> v, const std::vector<double> w){
    int v_size = v.size();
    // Check vectors are the same length
    if (v_size != w.size()) {
        throw std::invalid_argument(
            "Vectors must be the same length"
        );
    }

    double dot = 0;
    for (int i = 0; i < v_size; i++) {
        dot += v[i]*w[i];
    }

    return dot;
}

Matrix matmul(Matrix A, Matrix B){
    size_t a_row = A.size().rows;
    size_t a_col = A.size().cols;
    size_t b_row = B.size().rows;
    size_t b_col = B.size().cols;

    // Check if A has size a x n and B has size m x b then n == m
    if (a_col != b_row) {
        throw std::invalid_argument(
            "Matrices have incompatible sizes: Columns of A should match rows of B"
        );
    }

    Matrix C = Matrix::zeros(a_row, b_col);

    return C;
}

}