// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include <iostream>
#include <iomanip>

// Maximum array dimension specified by requirements
const int MAX_SIZE = 10;

// =============================================================================
// HELPER FUNCTIONS FOR INPUT & OUTPUT
// =============================================================================

// Reads matrix elements from the user
void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << "  Enter element [" << i << "][" << j << "]: ";
            std::cin >> matrix[i][j];
        }
    }
}

// Displays a matrix in a neat, aligned grid using setw()
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, int colWidth = 5) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << std::setw(colWidth) << matrix[i][j];
        }
        std::cout << std::endl;
    }
}

// =============================================================================
// PART A — TRANSPOSE A MATRIX
// =============================================================================
// Transposes an (M x N) matrix into an (N x M) matrix.
void transposeMatrix(const int src[MAX_SIZE][MAX_SIZE], int dest[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // Rows become columns, columns become rows
            dest[j][i] = src[i][j];
        }
    }
}

// =============================================================================
// PART B — ADD TWO MATRICES
// =============================================================================
// Computes element-wise sum of two (M x N) matrices.
void addMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// =============================================================================
// PART C — MULTIPLY TWO MATRICES
// =============================================================================
// Computes matrix product A(M x N) * B(N x P) = result(M x P).
void multiplyMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// =============================================================================
// MAIN FUNCTION
// =============================================================================
int main() {
    int matrixA[MAX_SIZE][MAX_SIZE];
    int matrixB[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];

    // -------------------------------------------------------------------------
    // DEMONSTRATE PART A: TRANSPOSE
    // -------------------------------------------------------------------------
    std::cout << "=================================================\n";
    std::cout << " PART A — Transpose a Matrix\n";
    std::cout << "=================================================\n";

    int rowsA, colsA;
    std::cout << "Enter number of rows (max " << MAX_SIZE << "): ";
    std::cin >> rowsA;
    std::cout << "Enter number of columns (max " << MAX_SIZE << "): ";
    std::cin >> colsA;

    if (rowsA <= 0 || rowsA > MAX_SIZE || colsA <= 0 || colsA > MAX_SIZE) {
        std::cout << "Error: Invalid dimensions.\n";
        return 1;
    }

    std::cout << "Enter elements for Matrix A (" << rowsA << "x" << colsA << "):\n";
    readMatrix(matrixA, rowsA, colsA);

    std::cout << "\nOriginal Matrix:\n";
    printMatrix(matrixA, rowsA, colsA);

    transposeMatrix(matrixA, result, rowsA, colsA);

    std::cout << "\nTransposed Matrix:\n";
    printMatrix(result, colsA, rowsA);

    // -------------------------------------------------------------------------
    // DEMONSTRATE PART B: ADDITION
    // -------------------------------------------------------------------------
    std::cout << "\n=================================================\n";
    std::cout << " PART B — Add Two Matrices\n";
    std::cout << "=================================================\n";

    int rowsSum, colsSum;
    std::cout << "Enter number of rows for addition (max " << MAX_SIZE << "): ";
    std::cin >> rowsSum;
    std::cout << "Enter number of columns for addition (max " << MAX_SIZE << "): ";
    std::cin >> colsSum;

    if (rowsSum <= 0 || rowsSum > MAX_SIZE || colsSum <= 0 || colsSum > MAX_SIZE) {
        std::cout << "Error: Invalid dimensions.\n";
        return 1;
    }

    std::cout << "Enter elements for Matrix 1 (" << rowsSum << "x" << colsSum << "):\n";
    readMatrix(matrixA, rowsSum, colsSum);

    std::cout << "Enter elements for Matrix 2 (" << rowsSum << "x" << colsSum << "):\n";
    readMatrix(matrixB, rowsSum, colsSum);

    addMatrices(matrixA, matrixB, result, rowsSum, colsSum);

    std::cout << "\nMatrix 1:\n";
    printMatrix(matrixA, rowsSum, colsSum);
    std::cout << "\nMatrix 2:\n";
    printMatrix(matrixB, rowsSum, colsSum);
    std::cout << "\nSum Matrix:\n";
    printMatrix(result, rowsSum, colsSum);

    // -------------------------------------------------------------------------
    // DEMONSTRATE PART C: MULTIPLICATION
    // -------------------------------------------------------------------------
    std::cout << "\n=================================================\n";
    std::cout << " PART C — Multiply Two Matrices\n";
    std::cout << "=================================================\n";

    int m, n, p;
    std::cout << "For multiplication A(M x N) * B(N x P):\n";
    std::cout << "Enter M (rows of A, max " << MAX_SIZE << "): ";
    std::cin >> m;
    std::cout << "Enter N (columns of A / rows of B, max " << MAX_SIZE << "): ";
    std::cin >> n;
    std::cout << "Enter P (columns of B, max " << MAX_SIZE << "): ";
    std::cin >> p;

    if (m <= 0 || m > MAX_SIZE || n <= 0 || n > MAX_SIZE || p <= 0 || p > MAX_SIZE) {
        std::cout << "Error: Invalid dimensions.\n";
        return 1;
    }

    std::cout << "Enter elements for Matrix A (" << m << "x" << n << "):\n";
    readMatrix(matrixA, m, n);

    std::cout << "Enter elements for Matrix B (" << n << "x" << p << "):\n";
    readMatrix(matrixB, n, p);

    multiplyMatrices(matrixA, matrixB, result, m, n, p);

    std::cout << "\nMatrix A:\n";
    printMatrix(matrixA, m, n);
    std::cout << "\nMatrix B:\n";
    printMatrix(matrixB, n, p);
    std::cout << "\nProduct Matrix (A x B):\n";
    printMatrix(result, m, p);

    return 0;
}