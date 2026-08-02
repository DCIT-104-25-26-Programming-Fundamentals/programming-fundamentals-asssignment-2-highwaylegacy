// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 6
// =============================================================================
//
// TASK: Multiplication Table Generator
//
// Write a C++ program that generates multiplication tables using loops
// and functions.
//
// -----------------------------------------------------------------------------
// PART A — Single Table
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Print the multiplication table for that number from 1 to 12.
//
// Expected output (if user enters 5):
//
//   Multiplication Table for 5:
//   5  x  1  =  5
//   5  x  2  =  10
//   5  x  3  =  15
//   ...
//   5  x  12 =  60
//
// -----------------------------------------------------------------------------
// PART B — Bonus: Tables from 1 to N
// -----------------------------------------------------------------------------
// - Ask the user to enter a number N.
// - Print the full multiplication table for every number from 1 to N.
// - Add a separator line (e.g. "---") between each table.
//
// Expected output (if user enters 3):
//
//   Multiplication Table for 1:
//   1  x  1  =  1
//   ...
//   1  x  12 =  12
//   ---------------------------
//   Multiplication Table for 2:
//   2  x  1  =  2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - N must be a positive integer. If the user enters an invalid value,
//   print an error message and stop.
// - Each part must be in its own function (see scaffold below).
// - Complete Part A before attempting Part B.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

#include <iostream>
#include <iomanip>

// =============================================================================
// FUNCTION IMPLEMENTATIONS
// =============================================================================

// -----------------------------------------------------------------------------
// PART A — Single Table
// -----------------------------------------------------------------------------
// Prints the multiplication table for a single number from 1 to 12.
void printSingleTable(int n) {
    std::cout << "Multiplication Table for " << n << ":\n";
    for (int i = 1; i <= 12; ++i) {
        std::cout << n << "  x  " 
                  << std::left << std::setw(2) << i 
                  << " =  " << (n * i) << std::endl;
    }
}

// -----------------------------------------------------------------------------
// PART B — Bonus: Tables from 1 to N
// -----------------------------------------------------------------------------
// Prints full multiplication tables for every number from 1 to N,
// separated by a divider line.
void printTablesUpToN(int n) {
    for (int i = 1; i <= n; ++i) {
        printSingleTable(i);
        if (i < n) {
            std::cout << "---------------------------\n";
        }
    }
}

// =============================================================================
// MAIN FUNCTION
// =============================================================================
int main() {
    // -------------------------------------------------------------------------
    // DEMONSTRATE PART A: Single Table
    // -------------------------------------------------------------------------
    std::cout << "=================================================\n";
    std::cout << " PART A — Single Table\n";
    std::cout << "=================================================\n";

    int singleNum;
    std::cout << "Enter a number for its multiplication table: ";
    std::cin >> singleNum;

    // Validate positive integer
    if (singleNum <= 0) {
        std::cout << "Error: Number must be a positive integer." << std::endl;
        return 1;
    }

    std::cout << std::endl;
    printSingleTable(singleNum);

    // -------------------------------------------------------------------------
    // DEMONSTRATE PART B: Tables from 1 to N
    // -------------------------------------------------------------------------
    std::cout << "\n=================================================\n";
    std::cout << " PART B — Bonus: Tables from 1 to N\n";
    std::cout << "=================================================\n";

    int maxNum;
    std::cout << "Enter N to generate tables from 1 to N: ";
    std::cin >> maxNum;

    // Validate positive integer
    if (maxNum <= 0) {
        std::cout << "Error: Number must be a positive integer." << std::endl;
        return 1;
    }

    std::cout << std::endl;
    printTablesUpToN(maxNum);

    return 0;
}