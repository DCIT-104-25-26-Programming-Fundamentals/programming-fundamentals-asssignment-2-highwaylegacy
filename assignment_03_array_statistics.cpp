// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

#include <iostream>

// =============================================================================
// FUNCTION IMPLEMENTATIONS
// =============================================================================

// Computes the sum of all elements in the array using a loop
double computeSum(const double arr[], int size) {
    double sum = 0.0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum;
}

// Computes the average of all elements in the array
double computeAverage(const double arr[], int size) {
    if (size <= 0) {
        return 0.0;
    }
    return computeSum(arr, size) / size;
}

// Finds the maximum value in the array using a loop
double findMax(const double arr[], int size) {
    double maxVal = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

// Finds the minimum value in the array using a loop
double findMin(const double arr[], int size) {
    double minVal = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return minVal;
}

// =============================================================================
// MAIN FUNCTION
// =============================================================================
int main() {
    int n;

    std::cout << "How many numbers? ";
    std::cin >> n;

    // Validate that N is a positive integer
    if (n <= 0) {
        std::cout << "Error: Number of elements must be a positive integer." << std::endl;
        return 1;
    }

    // Dynamically allocate array for N elements
    double* numbers = new double[n];

    // Read elements from user
    for (int i = 0; i < n; ++i) {
        std::cout << "Enter number " << (i + 1) << ": ";
        std::cin >> numbers[i];
    }

    // Print results
    std::cout << "\nResults:\n";
    std::cout << "Sum:    " << computeSum(numbers, n) << std::endl;
    std::cout << "Average: " << computeAverage(numbers, n) << std::endl;
    std::cout << "Maximum: " << findMax(numbers, n) << std::endl;
    std::cout << "Minimum: " << findMin(numbers, n) << std::endl;

    // Clean up dynamically allocated memory
    delete[] numbers;

    return 0;
}