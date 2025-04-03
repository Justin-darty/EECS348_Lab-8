#include <iostream>
#include <fstream>
#include "matrix.hpp"

// Prologue Comment
// Author: Justin Daugherty
// Date: 2025-04-02
//
// This file implements a simple command-line interface for reading matrices from a file,
// performing matrix addition, multiplication, and diagonal sum calculations, and displaying the results.

void read_matrices_from_file(const std::string& filename, Matrix& matrix1, Matrix& matrix2) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Unable to open file." << std::endl;
        return;
    }

    std::size_t N;
    file >> N; // Read the size of the matrix
    std::vector<std::vector<int>> mat1(N, std::vector<int>(N));
    std::vector<std::vector<int>> mat2(N, std::vector<int>(N));

    // Read the first matrix
    for (auto& row : mat1)
        for (auto& val : row)
            file >> val;

    // Read the second matrix
    for (auto& row : mat2)
        for (auto& val : row)
            file >> val;

    matrix1 = Matrix(mat1); // Initialize the first matrix with read data
    matrix2 = Matrix(mat2); // Initialize the second matrix with read data

    // Print both matrices
    std::cout << "Matrix 1:" << std::endl;
    matrix1.print_matrix();
    std::cout << "\nMatrix 2:" << std::endl;
    matrix2.print_matrix();
}

int main() {
    Matrix matrix1(3), matrix2(3); // Initialize 3x3 matrices

    // Read matrices from file
    read_matrices_from_file("matrix_input.txt", matrix1, matrix2);

    // Perform matrix addition and display the result
    Matrix sum = matrix1 + matrix2;
    std::cout << "\nMatrix Sum:" << std::endl;
    sum.print_matrix();

    // Perform matrix multiplication and display the result
    Matrix product = matrix1 * matrix2;
    std::cout << "\nMatrix Product:" << std::endl;
    product.print_matrix();

    // Display the sum of the main diagonal and secondary diagonal
    std::cout << "\nMain diagonal sum: " << matrix1.sum_diagonal_major() << std::endl;
