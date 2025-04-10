#include "matrix.hpp"
#include <iostream>
#include <fstream>

#include "matrix.hpp"

int main(int argc, char *argv[]) {
    // Tells the user to add a filename when running the file
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1; // Halts the program
    }

    std::ifstream file(argv[1]); // Opens the file

    std::size_t N; // Declares a variable for the size of the array
    file >> N; // Puts the size of the array into the variable

    // Returns an error if the size is zero
    if (N == 0 ) {
        std::cerr << "Matrix size cannot be zero." << std::endl;
        return 1;
    }

    std::vector<std::vector<int>> matrix_1(N, std::vector<int>(N)); // Creates an array of size N for the first matrix
    std::vector<std::vector<int>> matrix_2(N, std::vector<int>(N)); // Creates an array of size N for the second matrix
    
    for (std::size_t i = 0; i < N; i++) { // Iterates over each row in the matrix
        for (std::size_t j = 0; j < N; j++) { // Iterates over each column in the matrix
            file >> matrix_1[i][j]; // Puts the element into the matrix
        }
    }
    for (std::size_t i = 0; i < N; i++) { // Iterates over each row in the matrix
        for (std::size_t j = 0; j < N; j++) { // Iterates over each column in the matrix
            file >> matrix_2[i][j]; // Puts the element into the matrix
        }
    }

    file.close(); // Closes the file
    
    Matrix matrix1(matrix_1); // Creates the matrix object with the first matrix
    Matrix matrix2(matrix_2); // Creates the matrix object with the second matrix
    
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

    return 0;
}
}
