#pragma once

#include <vector>
#include <array>

namespace compmathlib{

/**
 * @brief Struct containing matrix size data on number of rows and columns.
 *
 */
struct MatrixSize {
    std::size_t rows;
    std::size_t cols;
};


/**
 * @brief Matrix class representing a rectangular array of numbers.
 *
 */
class Matrix {
    private:
        std::vector<std::vector<double>> data;
        MatrixSize matrix_size;

    public:

        // Constructor
        Matrix(std::vector<std::vector<double>> mdata);

        // Named constructors

        /**
         * @brief Initialises a Matrix object with every entry a given value with the size specified by the rows and cols arguments.
         *
         * @param rows Number of rows
         * @param cols Number of columns
         * @param num value of the matrix entries
         * @return Matrix
         */
        static Matrix constant(std::size_t tows, std::size_t cols, double num);

        /**
         * @brief Initialises a Matrix object of all 0s with the size specified by the rows and cols arguments.
         *
         * @param rows Number of rows
         * @param cols Number of columns
         * @return Matrix
         */
        static Matrix zeros(std::size_t rows, std::size_t cols);

        /**
         * @brief Initialises a Matrix object of all 0s with the size specified by the rows and cols arguments.
         *
         * @param rows Number of rows
         * @param cols Number of columns
         * @return Matrix
         */
        static Matrix ones(std::size_t rows, std::size_t cols);

        // Getters

        /**
         * @brief Returns the size of the matrix.
         *
         * @return MatrixSize
         */
        MatrixSize size();

        /**
         * @brief Returns the i-th row of the matrix.
         *
         * @param i Row index
         * @return std::vector<double>&
         */
        std::vector<double>& operator[](std::size_t i);

        /**
         * @brief Returns the i-th row of the matrix as a constant.
         *
         * @param i Row index
         * @return const std::vector<double>&
         */
        const std::vector<double>& operator[](std::size_t i) const;
};

/**
 * @brief Multiplies matrices of compatible sizes together.
 *
 * @param A First matrix
 * @param B Second matrix
 * @return Matrix
 *
 * @exception std::invalid_argument if the number of columns of A does not equal to number of
 *            columns of B
 */
Matrix matmul(const Matrix A, const Matrix B);

}