// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//      - Ask the user to enter the student's name and ID.
//      - Ask how many scores to enter, then collect each score one by one.
//      - Save the student record and confirm it was added.
//
//   2. Display All Students
//      - Print a formatted table showing every student's:
//          Name, ID, individual scores, and their average score.
//      - If no students have been added yet, print a message saying so.
//
//   3. Calculate Average Score for a Specific Student
//      - Ask the user to enter a student ID.
//      - Find the student and print their average score.
//      - If the ID is not found, print an error message.
//
//   4. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ================================
//      STUDENT RECORD SYSTEM MENU
//   ================================
//   1. Add student
//   2. Display all students
//   3. Calculate average score
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Student name: Alice Mensah
//   Student ID: 20240001
//   How many scores? 3
//   Enter score 1: 78
//   Enter score 2: 85
//   Enter score 3: 90
//   Student "Alice Mensah" added successfully.
//
//   Enter your choice (1-4): 3
//   Enter student ID: 20240001
//   Alice Mensah's average score: 84.33
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>
#include <sstream>

// =============================================================================
// DATA STRUCTURE DEFINITIONS
// =============================================================================
struct Student {
    std::string name;
    int id;
    std::vector<double> scores;
};

// =============================================================================
// HELPER FUNCTION
// =============================================================================
// Computes the average of a vector of scores
double computeAverage(const std::vector<double>& scores) {
    if (scores.empty()) {
        return 0.0;
    }
    double sum = 0.0;
    for (double score : scores) {
        sum += score;
    }
    return sum / scores.size();
}

// =============================================================================
// FUNCTION IMPLEMENTATIONS
// =============================================================================

// Displays the Student Record System application menu
void displayMenu() {
    std::cout << "\n================================\n";
    std::cout << "   STUDENT RECORD SYSTEM MENU\n";
    std::cout << "================================\n";
    std::cout << "1. Add student\n";
    std::cout << "2. Display all students\n";
    std::cout << "3. Calculate average score\n";
    std::cout << "4. Quit\n";
    std::cout << "Enter your choice (1-4): ";
}

// -----------------------------------------------------------------------------
// FEATURE 1 — Add a Student
// -----------------------------------------------------------------------------
void addStudent(std::vector<Student>& students) {
    Student newStudent;

    std::cout << "Student name: ";
    std::getline(std::cin, newStudent.name);

    std::cout << "Student ID: ";
    std::cin >> newStudent.id;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Error: Invalid ID format.\n";
        return;
    }

    int numScores = 0;
    std::cout << "How many scores? ";
    std::cin >> numScores;

    if (std::cin.fail() || numScores < 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Error: Number of scores must be a non-negative integer.\n";
        return;
    }

    for (int i = 1; i <= numScores; ++i) {
        double score = 0.0;
        std::cout << "Enter score " << i << ": ";
        std::cin >> score;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Error: Invalid score value.\n";
            return;
        }
        newStudent.scores.push_back(score);
    }

    // Clear leftover newline character after reading numeric inputs
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    students.push_back(newStudent);
    std::cout << "Student \"" << newStudent.name << "\" added successfully." << std::endl;
}

// -----------------------------------------------------------------------------
// FEATURE 2 — Display All Students
// -----------------------------------------------------------------------------
void displayAllStudents(const std::vector<Student>& students) {
    if (students.empty()) {
        std::cout << "No student records available.\n";
        return;
    }

    std::cout << "\n--------------------------------------------------------------------------------\n";
    std::cout << std::left << std::setw(12) << "ID"
              << std::setw(22) << "Name"
              << std::setw(32) << "Scores"
              << std::setw(12) << "Average" << "\n";
    std::cout << "--------------------------------------------------------------------------------\n";

    for (const Student& student : students) {
        std::ostringstream ss;
        for (size_t i = 0; i < student.scores.size(); ++i) {
            ss << student.scores[i];
            if (i + 1 < student.scores.size()) {
                ss << ", ";
            }
        }
        std::string scoresStr = ss.str();

        double avg = computeAverage(student.scores);

        std::cout << std::left << std::setw(12) << student.id
                  << std::setw(22) << student.name
                  << std::setw(32) << (scoresStr.empty() ? "None" : scoresStr)
                  << std::fixed << std::setprecision(2) << avg << "\n";
    }
    std::cout << "--------------------------------------------------------------------------------\n";
    // Reset formatting flags
    std::cout << std::defaultfloat;
}

// -----------------------------------------------------------------------------
// FEATURE 3 — Calculate Average Score for a Specific Student
// -----------------------------------------------------------------------------
void calculateStudentAverage(const std::vector<Student>& students) {
    if (students.empty()) {
        std::cout << "No student records available.\n";
        return;
    }

    int searchId = 0;
    std::cout << "Enter student ID: ";
    std::cin >> searchId;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Error: Invalid ID format.\n";
        return;
    }

    // Clear leftover newline character
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (const Student& student : students) {
        if (student.id == searchId) {
            double avg = computeAverage(student.scores);
            std::cout << student.name << "'s average score: " 
                      << std::fixed << std::setprecision(2) << avg << std::endl;
            std::cout << std::defaultfloat; // Reset float format
            return;
        }
    }

    std::cout << "Error: Student with ID " << searchId << " not found." << std::endl;
}

// =============================================================================
// MAIN FUNCTION
// =============================================================================
int main() {
    std::vector<Student> students;
    int choice = 0;

    while (true) {
        displayMenu();
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid choice. Please enter a number between 1 and 4.\n";
            continue;
        }

        // Clear trailing newline before reading strings in menu options
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choice == 1) {
            addStudent(students);
        } else if (choice == 2) {
            displayAllStudents(students);
        } else if (choice == 3) {
            calculateStudentAverage(students);
        } else if (choice == 4) {
            std::cout << "Goodbye!" << std::endl;
            break;
        } else {
            std::cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        }
    }

    return 0;
}