// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )    e.g.  10 + 3  =  13
//   2. Subtraction       ( - )    e.g.  10 - 3  =  7
//   3. Multiplication    ( * )    e.g.  10 * 3  =  30
//   4. Division          ( / )    e.g.  10 / 3  =  3.33
//   5. Modulus           ( % )    e.g.  10 % 3  =  1  (remainder)
//   6. Exponentiation    ( ^ )    e.g.  2 ^ 8   =  256
//   7. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        SIMPLE CALCULATOR
//   ============================
//   1. Addition
//   2. Subtraction
//   3. Multiplication
//   4. Division
//   5. Modulus
//   6. Exponentiation
//   7. Quit
//   Select an operation (1-7):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Select an operation (1-7): 4
//   Enter first number : 10
//   Enter second number: 3
//   Result: 10 / 3 = 3.33
//
//   Select an operation (1-7): 4
//   Enter first number : 5
//   Enter second number: 0
//   Error: Cannot divide by zero.
//
//   Select an operation (1-7): 7
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Each arithmetic operation MUST be written as its own function.
// - Use a loop so the calculator keeps running until the user selects Quit.
// - Division by zero must be caught and handled with a clear error message
//   (do NOT let the program crash).
// - Use fixed and setprecision(2) to display results to 2 decimal places.
// - Handle invalid menu choices gracefully.
// - For exponentiation use a loop or the pow() function from <cmath>.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>

// =============================================================================
// FUNCTION IMPLEMENTATIONS FOR ARITHMETIC OPERATIONS
// =============================================================================

// 1. Addition
double add(double a, double b) {
    return a + b;
}

// 2. Subtraction
double subtract(double a, double b) {
    return a - b;
}

// 3. Multiplication
double multiply(double a, double b) {
    return a * b;
}

// 4. Division
double divide(double a, double b) {
    return a / b;
}

// 5. Modulus (remainder)
long long modulus(long long a, long long b) {
    return a % b;
}

// 6. Exponentiation
double exponentiate(double base, double exponent) {
    return std::pow(base, exponent);
}

// =============================================================================
// MENU DISPLAY FUNCTION
// =============================================================================
void displayMenu() {
    std::cout << "\n============================\n";
    std::cout << "     SIMPLE CALCULATOR\n";
    std::cout << "============================\n";
    std::cout << "1. Addition\n";
    std::cout << "2. Subtraction\n";
    std::cout << "3. Multiplication\n";
    std::cout << "4. Division\n";
    std::cout << "5. Modulus\n";
    std::cout << "6. Exponentiation\n";
    std::cout << "7. Quit\n";
    std::cout << "Select an operation (1-7): ";
}

// =============================================================================
// MAIN FUNCTION
// =============================================================================
int main() {
    int choice = 0;

    while (true) {
        displayMenu();
        std::cin >> choice;

        // Handle invalid non-integer inputs gracefully
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid choice. Please select an operation between 1 and 7.\n";
            continue;
        }

        // Option 7: Quit
        if (choice == 7) {
            std::cout << "Goodbye!" << std::endl;
            break;
        }

        // Validate menu range
        if (choice < 1 || choice > 7) {
            std::cout << "Invalid choice. Please select an operation between 1 and 7.\n";
            continue;
        }

        double a = 0.0, b = 0.0;
        std::cout << "Enter first number : ";
        std::cin >> a;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Error: Invalid number input.\n";
            continue;
        }

        std::cout << "Enter second number: ";
        std::cin >> b;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Error: Invalid number input.\n";
            continue;
        }

        // Check for division or modulus by zero
        if ((choice == 4 || choice == 5) && b == 0.0) {
            std::cout << "Error: Cannot divide by zero." << std::endl;
            continue;
        }

        // Perform calculation and print result
        switch (choice) {
            case 1:
                std::cout << "Result: " << a << " + " << b << " = "
                          << std::fixed << std::setprecision(2) << add(a, b) << std::endl;
                break;
            case 2:
                std::cout << "Result: " << a << " - " << b << " = "
                          << std::fixed << std::setprecision(2) << subtract(a, b) << std::endl;
                break;
            case 3:
                std::cout << "Result: " << a << " * " << b << " = "
                          << std::fixed << std::setprecision(2) << multiply(a, b) << std::endl;
                break;
            case 4:
                std::cout << "Result: " << a << " / " << b << " = "
                          << std::fixed << std::setprecision(2) << divide(a, b) << std::endl;
                break;
            case 5: {
                long long intA = static_cast<long long>(a);
                long long intB = static_cast<long long>(b);
                std::cout << "Result: " << intA << " % " << intB << " = "
                          << modulus(intA, intB) << std::endl;
                break;
            }
            case 6:
                std::cout << "Result: " << a << " ^ " << b << " = "
                          << std::fixed << std::setprecision(2) << exponentiate(a, b) << std::endl;
                break;
        }

        // Reset formatting flags for future iterations
        std::cout << std::defaultfloat;
    }

    return 0;
}