#include "matrix.hpp"
#include <iostream>
#include <fstream>

int main(int argc, char *argv[]) {
    // Tells the user to add a filename when running the file
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    std::ifstream file(argv[1]); // Opens the file

    std::size_t N; // Declares a variable for the size of the array
    file >> N; // Puts the size of the array into the variable

    int type_flag; // Declares a variable for the type of element (int or double)
    file >> type_flag; // Puts the value into type_flag

    // Returns an error if the size is zero
    if (N == 0) {
        std::cerr << "Matrix size cannot be zero." << std::endl;
        return 1;
    }

    if (type_flag == 0) { // Checks if the type is int
        int** matrix_1 = new int*[N]; // Creates an array of size N for rows of the first matrix
        int** matrix_2 = new int*[N]; // Creates an array of size N for rows of the second matrix

        for (std::size_t i = 0; i < N; ++i) { // Iterates over each row in the matrix
            matrix_1[i] = new int[N]; // Creates an array for the elements in the ith row
            matrix_2[i] = new int[N]; // Creates an array for the elements in the ith row
        }

        for (std::size_t i = 0; i < N; ++i) { // Iterates over each row in the matrix
            for (std::size_t j = 0; j < N; ++j) { // Iterates over each column in the matrix
                file >> matrix_1[i][j]; // Puts the element into the matrix
            }
        }
        for (std::size_t i = 0; i < N; ++i) { // Iterates over each row in the matrix
            for (std::size_t j = 0; j < N; ++j) { // Iterates over each column in the matrix
                file >> matrix_2[i][j]; // Puts the element into the matrix
            }
        }

        file.close(); // Closes the file

        Matrix<int> matrix1(matrix_1, N); // Creates the matrix object with the first matrix
        Matrix<int> matrix2(matrix_2, N); // Creates the matrix object with the second matrix

        // Prints the first matrix
        std::cout << "Matrix 1:" << std::endl;
        matrix1.print_matrix();

        // Prints the second matrix
        std::cout << "\nMatrix 2:" << std::endl;
        matrix2.print_matrix();

        // Prints the sum of the two matrices
        std::cout << "\nMatrix Sum:" << std::endl;
        (matrix1 + matrix2).print_matrix();

        // Prints the product of the two matrices
        std::cout << "\nMatrix Product:" << std::endl;
        (matrix1 * matrix2).print_matrix();

        std::cout << "\nSum of Major Diagonal (Matrix 1): " << matrix1.sum_diagonal_major() << std::endl; // Prints the sum of the major diagonal of the first matrix
        std::cout << "Sum of Minor Diagonal (Matrix 1): " << matrix1.sum_diagonal_minor() << std::endl; // Prints the sum of the minor diagonal of the first matrix

        // Deletes the matrices in order to clean up the memory
        for (std::size_t i = 0; i < N; ++i) {
            delete[] matrix_1[i];
            delete[] matrix_2[i];
        }
        delete[] matrix_1;
        delete[] matrix_2;

    } else if (type_flag == 1) {
        double** matrix_1 = new double*[N]; // Creates an array of size N for the first matrix
        double** matrix_2 = new double*[N]; // Creates an array of size N for the second matrix

        for (std::size_t i = 0; i < N; ++i) { // Iterates over each row in the matrix
            matrix_1[i] = new double[N]; // Creates an array for the elements in the ith row
            matrix_2[i] = new double[N]; // Creates an array for the elements in the ith row
        }

        // Read data from file
        for (std::size_t i = 0; i < N; ++i) { // Iterates over each row in the matrix
            for (std::size_t j = 0; j < N; ++j) { // Iterates over each column in the matrix
                file >> matrix_1[i][j]; // Puts the element into the matrix
            }
        }
        for (std::size_t i = 0; i < N; ++i) { // Iterates over each row in the matrix
            for (std::size_t j = 0; j < N; ++j) { // Iterates over each column in the matrix
                file >> matrix_2[i][j]; // Puts the element into the matrix
            }
        }

        file.close(); // Closes the file

        Matrix<double> matrix1(matrix_1, N); // Creates the matrix object with the first matrix
        Matrix<double> matrix2(matrix_2, N); // Creates the matrix object with the second matrix

        // Prints the first matrix
        std::cout << "Matrix 1:" << std::endl;
        matrix1.print_matrix();

        // Prints the second matrix
        std::cout << "\nMatrix 2:" << std::endl;
        matrix2.print_matrix();

        // Prints the sum of the two matrices
        std::cout << "\nMatrix Sum:" << std::endl;
        (matrix1 + matrix2).print_matrix();

        // Prints the product of the two matrices
        std::cout << "\nMatrix Product:" << std::endl;
        (matrix1 * matrix2).print_matrix();

        std::cout << "\nSum of Major Diagonal (Matrix 1): " << matrix1.sum_diagonal_major() << std::endl; // Prints the sum of the major diagonal of the first matrix
        std::cout << "Sum of Minor Diagonal (Matrix 1): " << matrix1.sum_diagonal_minor() << std::endl; // Prints the sum of the minor diagonal of the first matrix

        // Deletes the matrices in order to clean up the memory
        for (std::size_t i = 0; i < N; ++i) {
            delete[] matrix_1[i];
            delete[] matrix_2[i];
        }
        delete[] matrix_1;
        delete[] matrix_2;

    } else {
        return 1;
    }

    return 0;
}
