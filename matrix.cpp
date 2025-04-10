#include "matrix.hpp"
#include <iostream>
#include <stdexcept>

// Constructor that initializes an NxN matrix filled with 0's
template <typename T>
Matrix<T>::Matrix(size_t N) : size(N) {
    data = new T*[size]; // Allocates an array of pointers for each row
    for (std::size_t i = 0; i < size; i++) { // Iterates over each row in the matrix
        data[i] = new T[size]{}; // Allocates an array of integers for the ith row, initializing each value to 0
    }
}

// Constructor that initializes a matrix with a given array
template <typename T>
Matrix<T>::Matrix(T** nums, std::size_t N) : size(N) {
    data = new T*[size]; // Allocates an array of pointers for each row
    for (std::size_t i = 0; i < size; i++) { // Iterates over each row in the matrix
        data[i] = new T[size]; // Allocates an array of integers for the ith row
        for (std::size_t j = 0; j < size; j++) { // Iterates over each column in the matrix
            data[i][j] = nums[i][j]; // Copies each element to the target matrix
        }
    }
}

// Constructor that copies one matrix's contents to another
template <typename T>
Matrix<T>::Matrix(const Matrix& other) : size(other.size) {
    data = new T*[size]; // Allocates an array of pointers for each row
    for (std::size_t i = 0; i < size; ++i) { // Iterates over each row in the matrix
        data[i] = new T[size]; // Allocates an array of integers for the ith row
        for (std::size_t j = 0; j < size; ++j) { // Iterates over each column in the matrix
            data[i][j] = other.data[i][j]; // Copies the other matrix's ith, jth value
        }
    }
}

// Destructor which cleans up the memory to avoid leaks
template <typename T>
Matrix<T>::~Matrix() {
    for (std::size_t i = 0; i < size; ++i) { // Iterates over each row in the matrix
        delete[] data[i]; // Deletes the ith row
    }

    delete[] data; // Deletes the array of row pointers, fully deleting the matrix
}

// Assignment operator which proper copting of one matrix to another and cleans up memory
template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix& other) {
    if (this != &other) { // Checks if we're trying to assign the matrix to itself
        for (std::size_t i = 0; i < size; ++i) // Iterates over each row in the matrix
            delete[] data[i]; // Deletes the ith row

        delete[] data; // Deletes the array of row pointers, fully deleting the matrix

        size = other.size; // Sets the matrix's size to the size of other
        data = new T*[size]; // Allocates an array of pointers for each row
        for (std::size_t i = 0; i < size; ++i) { // Iterates over each row in the matrix
            data[i] = new T[size]; // Allocates an array of integers for the ith row
            for (std::size_t j = 0; j < size; ++j) { // Iterates over each column in the matrix
                data[i][j] = other.data[i][j]; // Copies the other matrix's ith, jth value
            }
        }
    }

    return *this; // Returns the current matrix
}


// Returns the sum of two matrices
template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix &rhs) const {
    Matrix result(size); // Creates a matrix of correct size to store the result

    for (std::size_t i = 0; i < size; i++) { // Iterates over the rows of the matrices
        for (std::size_t j = 0; j < size; j++) { // Iterates over the columns of the matrices
            result.data[i][j] = data[i][j] + rhs.data[i][j]; // Puts the sum in the resultant matrix
        }
    }
    return result; // Returns the resultant matrix
}

// Returns the dot product of two matrices
template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix &rhs) const {
    Matrix result(size); // Creates a matrix of correct size to store the result

    for (std::size_t i = 0; i < size; i++) { // Iterates over the rows of this matrix
        for (std::size_t j = 0; j < size; j++) { // Iterates over the columns of the rhs matrix
            result.data[i][j] = 0; // Initializes the value at 0 in the resulting matrix
            for (std::size_t k = 0; k < size; k++) { // Iterates over the elements for the dot product
                result.data[i][j] += data[i][k] * rhs.data[k][j]; // Puts the dot product in the resultant matrix
            }
        }
    }
    return result; // Returns the resultant matrix
}

// Sets a given value in a matrix
template <typename T>
void Matrix<T>::set_value(std::size_t i, std::size_t j, T n) {
    // Throws error if the index is out of range
    if (i >= size || j >= size) {
        throw std::out_of_range("Index out of range");
    }
    data[i][j] = n;
}

// Returns a value from a given place in a matrix
template <typename T>
T Matrix<T>::get_value(std::size_t i, std::size_t j) const {
    // Throws error if the index is out of range
    if (i >= size || j >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[i][j];
}

// Returns the size of the matrix
template <typename T>
std::size_t Matrix<T>::get_size() const {
    return size;
}

// Returns the sum of the major diagonal
template <typename T>
T Matrix<T>::sum_diagonal_major() const {
    T sum = 0; // Initializes the sum at 0 with type T

    for (std::size_t i = 0; i < size; i++) { // Iterates over the size of the matrix
        sum += data[i][i]; // Adds each element along the major diagonal to the sum
    }

    return sum; // Returns the sum
}

// Returns the sum of the minor diagonal
template <typename T>
T Matrix<T>::sum_diagonal_minor() const {
    T sum = 0; // Initializes the sum at 0 with type T

    for (std::size_t i = 0; i < size; i++) { // Iterates over the size of the matrix
        sum += data[i][size - i - 1]; // Adds each element along the minor diagonal to the sum
    }

    return sum; // Returns the sum
}

// Swaps two rows in a matrix
template <typename T>
void Matrix<T>::swap_rows(std::size_t r1, std::size_t r2) {
    if (r1 < size && r2 < size) { // Checks if the rows are within the bounds of the matrix
        std::swap(data[r1], data[r2]); // Swaps the two rows
    }
}

// Swaps two columns in a matrix
template <typename T>
void Matrix<T>::swap_cols(std::size_t c1, std::size_t c2) {
    if (c1 < size && c2 < size) { // Checks if the columns are within the bounds of the matrix
        for (std::size_t i = 0; i < size; i++) { // Iterates over each row in the matrix
            std::swap(data[i][c1], data[i][c2]); // Swaps the two column values in the ith row
        }
    }
}

// Prints the matrix
template <typename T>
void Matrix<T>::print_matrix() const {
    std::size_t N = size; // Gets the size of the matrices we are working with

    for (std::size_t i = 0; i <  N; i++) { // Iterates over each row in the matrix
        for (std::size_t j = 0; j <  N; j++) { // Iterates over each column in the matrix
            std::cout << data[i][j] << " "; // Prints the jth element in the ith row
        }
        std::cout << std::endl; // Prints a newline for each new row
    }
}

template class Matrix<int>; // Explicitly instantiate the template for type int
template class Matrix<double>; // Explicitly instantiate the template for type double