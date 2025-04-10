#include "matrix.hpp"
#include <iostream>
#include <stdexcept>

// Constructor that initializes an NxN matrix filled with 0's
Matrix::Matrix(size_t N) : size(N) {
    data = new int*[size];
    for (std::size_t i = 0; i < size; i++) {
        data[i] = new int[size]{};
    }
}

// Constructor that initializes a matrix with a given array
Matrix::Matrix(int** nums, std::size_t N) : size(N) {
    data = new int*[size];
    for (std::size_t i = 0; i < size; i++) {
        data[i] = new int[size];
        for (std::size_t j = 0; j < size; j++) {
            data[i][j] = nums[i][j];
        }
    }
}

// Returns the sum of two matrices
Matrix Matrix::operator+(const Matrix &rhs) const {
    std::size_t N = data.size(); // Gets the size of the matrices we are working with
    Matrix result(N); // Creates a matrix of correct size to store the result

    for (std::size_t i = 0; i < N; i++) { // Iterates over the rows of the matrices
        for (std::size_t j = 0; j < N; j++) { // Iterates over the columns of the matrices
            result.data[i][j] = data[i][j] + rhs.data[i][j]; // Puts the sum in the resultant matrix
        }
    }
    return result; // Returns the resultant matrix
}

// Returns the dot product of two matrices
Matrix Matrix::operator*(const Matrix &rhs) const {
    std::size_t N = data.size(); // Gets the size of the matrices we are working with
    Matrix result(N); // Creates a matrix of correct size to store the result

    for (std::size_t i = 0; i < N; i++) { // Iterates over the rows of this matrix
        for (std::size_t j = 0; j < N; j++) { // Iterates over the columns of the rhs matrix
            result.data[i][j] = 0; // Initializes the value at 0 in the resulting matrix
            for (std::size_t k = 0; k < N; k++) { // Iterates over the elements for the dot product
                result.data[i][j] += data[i][k] * rhs.data[k][j]; // Puts the dot product in the resultant matrix
            }
        }
    }
    return result; // Returns the resultant matrix
}

// Sets a given value in a matrix
void Matrix::set_value(std::size_t i, std::size_t j, int n) {
    // Throws error if the index is out of range
    if (i >= data.size() || j >= data.size()) {
        throw std::out_of_range("Index out of range");
    }
    data[i][j] = n;
}

// Returns a value from a given place in a matrix
int Matrix::get_value(std::size_t i, std::size_t j) const {
    // Throws error if the index is out of range
    if (i >= data.size() || j >= data.size()) {
        throw std::out_of_range("Index out of range");
    }
    return data[i][j];
}

// Returns the size of the matrix
int Matrix::get_size() const {
    return data.size();
}

// Returns the sum of the major diagonal
int Matrix::sum_diagonal_major() const {
    int sum = 0; // Initializes the sum at 0

    for (std::size_t i = 0; i < data.size(); i++) { // Iterates over the size of the matrix
        sum += data[i][i]; // Adds each element along the major diagonal to the sum
    }

    return sum; // Returns the sum
}

// Returns the sum of the minor diagonal
int Matrix::sum_diagonal_minor() const {
    int sum = 0; // Initializes the sum at 0

    for (std::size_t i = 0; i < data.size(); i++) { // Iterates over the size of the matrix
        sum += data[i][data.size() - i - 1]; // Adds each element along the minor diagonal to the sum
    }

    return sum; // Returns the sum
}

// Swaps two rows in a matrix
void Matrix::swap_rows(std::size_t r1, std::size_t r2) {
    if (r1 < data.size() && r2 < data.size()) { // Checks if the rows are within the bounds of the matrix
        std::swap(data[r1], data[r2]); // Swaps the two rows
    }
}

// Swaps two columns in a matrix
void Matrix::swap_cols(std::size_t c1, std::size_t c2) {
    if (c1 < data.size() && c2 < data.size()) { // Checks if the columns are within the bounds of the matrix
        for (std::size_t i = 0; i < data.size(); i++) { // Iterates over each row in the matrix
            std::swap(data[i][c1], data[i][c2]); // Swaps the two column values in the ith row
        }
    }
}

// Prints the matrix
void Matrix::print_matrix() const {
    std::size_t N = data.size(); // Gets the size of the matrices we are working with

    for (std::size_t i = 0; i <  N; i++) { // Iterates over each row in the matrix
        for (std::size_t j = 0; j <  N; j++) { // Iterates over each column in the matrix
            std::cout << data[i][j] << " "; // Prints the jth element in the ith row
        }
        std::cout << std::endl; // Prints a newline for each new row
    }
}