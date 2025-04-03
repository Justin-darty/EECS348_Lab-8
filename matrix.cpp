#include "matrix.hpp"
#include <iostream>
#include <stdexcept>

// Prologue Comment
// Author: Justin Daugherty
// Date: 2025-04-02
//
// This file implements the Matrix class, providing functions for matrix addition, 
// multiplication, accessing values, swapping rows and columns, and calculating diagonal sums.

Matrix::Matrix(std::size_t N) : data(N, std::vector<int>(N, 0)) {}

Matrix::Matrix(std::vector<std::vector<int>> nums) : data(std::move(nums)) {}

// Matrix addition: Adds corresponding elements of two matrices and returns the result
Matrix Matrix::operator+(const Matrix &rhs) const {
    if (get_size() != rhs.get_size()) throw std::invalid_argument("Matrix sizes do not match.");

    Matrix result(get_size());
    for (std::size_t i = 0; i < get_size(); i++)
        for (std::size_t j = 0; j < get_size(); j++)
            result.data[i][j] = data[i][j] + rhs.data[i][j];

    return result;
}

// Matrix multiplication: Multiplies two matrices and returns the result
Matrix Matrix::operator*(const Matrix &rhs) const {
    if (get_size() != rhs.get_size()) throw std::invalid_argument("Matrix sizes do not match.");

    Matrix result(get_size());
    for (std::size_t i = 0; i < get_size(); i++)
        for (std::size_t j = 0; j < get_size(); j++)
            for (std::size_t k = 0; k < get_size(); k++)
                result.data[i][j] += data[i][k] * rhs.data[k][j];

    return result;
}

// Sets the value at the specified position (i, j)
void Matrix::set_value(std::size_t i, std::size_t j, int n) {
    if (i >= get_size() || j >= get_size()) throw std::out_of_range("Index out of bounds.");
    data[i][j] = n;
}

// Gets the value at the specified position (i, j)
int Matrix::get_value(std::size_t i, std::size_t j) const {
    if (i >= get_size() || j >= get_size()) throw std::out_of_range("Index out of bounds.");
    return data[i][j];
}

// Returns the size of the matrix (NxN)
int Matrix::get_size() const {
    return data.size();
}

// Calculates the sum of the main diagonal
int Matrix::sum_diagonal_major() const {
    int sum = 0;  // Correct initialization of the sum variable
    for (std::size_t i = 0; i < get_size(); i++) {
        sum += data[i][i];  // Sum the diagonal elements
    }
    return sum;  // Make sure to return the result
}
int Matrix::sum_diagonal_minor() const {
    int sum = 0;
    std::size_t size = get_size();  // Assuming get_size() returns the dimension of the square matrix.
    for (std::size_t i = 0; i < size; i++) {
        sum += data[i][size - i - 1];  // Minor diagonal element
    }
    return sum;
}
void Matrix::swap_rows(std::size_t r1, std::size_t r2) {
    if (r1 < get_size() && r2 < get_size()) {
        std::swap(data[r1], data[r2]);
    } else {
        std::cerr << "Invalid row indices." << std::endl;
    }
}
void Matrix::swap_cols(std::size_t c1, std::size_t c2) {
    if (c1 < get_size() && c2 < get_size()) {
        for (std::size_t i = 0; i < get_size(); i++) {
            std::swap(data[i][c1], data[i][c2]);
        }
    } else {
        std::cerr << "Invalid column indices." << std::endl;
    }
}

