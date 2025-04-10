#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <cstddef>
#include <stdexcept>
#include <iostream>

// all of your function definitions should be in this file now

template<typename T>
class Matrix {
private:
    T** data;
    std::size_t size;

public:
    Matrix(std::size_t N);
    Matrix(T**nums, std::size_t N);
    Matrix(const Matrix& other);
    Matrix& operator=(const Matrix& other);
    ~Matrix();

    Matrix operator+(const Matrix &rhs) const;
    Matrix operator*(const Matrix &rhs) const;
    void set_value(std::size_t i, std::size_t j, T n);
    T get_value(std::size_t i, std::size_t j) const;
    std::size_t get_size() const;
    T sum_diagonal_major() const;
    T sum_diagonal_minor() const;
    void swap_rows(std::size_t r1, std::size_t r2);
    void swap_cols(std::size_t c1, std::size_t c2);
    void print_matrix() const;
};

#endif // __MATRIX_HPP__
