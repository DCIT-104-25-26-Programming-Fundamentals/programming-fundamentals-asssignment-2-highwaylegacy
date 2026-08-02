// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 7
// =============================================================================
//
// TASK: Console-Based To-Do List Application
//
// Build a simple to-do list program that runs entirely in the console and
// allows the user to manage their tasks interactively using a menu.
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Task
//      - Prompt the user to type a task description.
//      - Add it to the list and confirm it was added.
//
//   2. View All Tasks
//      - Display all tasks currently in the list, numbered from 1.
//      - If the list is empty, print a friendly message saying so.
//
//   3. Delete a Task
//      - Show the list of tasks with their numbers.
//      - Ask the user which task number they want to remove.
//      - Remove the task and confirm the deletion.
//      - If the task number is invalid, print an error message.
//
//   4. Quit
//      - End the program with a farewell message.
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        TO-DO LIST MENU
//   ============================
//   1. Add task
//   2. View tasks
//   3. Delete task
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Enter task: Buy groceries
//   Task added: "Buy groceries"
//
//   Enter your choice (1-4): 2
//   Your Tasks:
//   1. Buy groceries
//   2. Study for exams
//
//   Enter your choice (1-4): 3
//   Enter task number to delete: 1
//   Task "Buy groceries" has been removed.
//
//   Enter your choice (1-4): 4
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Store tasks in a vector<string> (a dynamic list of text).
// - Use a loop to keep the menu running until the user chooses to quit.
// - Each feature MUST be implemented in its own function (see scaffold below).
// - Handle invalid menu choices gracefully (print an error, do not crash).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include <iostream>
#include <vector>
#include <string>
#include <limits>

// =============================================================================
// FUNCTION IMPLEMENTATIONS
// =============================================================================

// Displays the To-Do List application menu
void displayMenu() {
    std::cout << "\n============================\n";
    std::cout << "     TO-DO LIST MENU\n";
    std::cout << "============================\n";
    std::cout << "1. Add task\n";
    std::cout << "2. View tasks\n";
    std::cout << "3. Delete task\n";
    std::cout << "4. Quit\n";
    std::cout << "Enter your choice (1-4): ";
}

// -----------------------------------------------------------------------------
// FEATURE 1 — Add a Task
// -----------------------------------------------------------------------------
// Prompts the user for a task description and adds it to the list.
void addTask(std::vector<std::string>& tasks) {
    std::string taskDescription;
    std::cout << "Enter task: ";
    std::getline(std::cin, taskDescription);

    if (taskDescription.empty()) {
        std::cout << "Error: Task description cannot be empty.\n";
        return;
    }

    tasks.push_back(taskDescription);
    std::cout << "Task added: \"" << taskDescription << "\"" << std::endl;
}

// -----------------------------------------------------------------------------
// FEATURE 2 — View All Tasks
// -----------------------------------------------------------------------------
// Displays all current tasks numbered from 1, or a friendly message if empty.
void viewTasks(const std::vector<std::string>& tasks) {
    if (tasks.empty()) {
        std::cout << "Your to-do list is empty!\n";
        return;
    }

    std::cout << "Your Tasks:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << (i + 1) << ". " << tasks[i] << std::endl;
    }
}

// -----------------------------------------------------------------------------
// FEATURE 3 — Delete a Task
// -----------------------------------------------------------------------------
// Shows the tasks and removes the user-specified task number.
void deleteTask(std::vector<std::string>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks available to delete.\n";
        return;
    }

    // Show the list of tasks with their numbers
    viewTasks(tasks);

    int taskNumber;
    std::cout << "Enter task number to delete: ";
    std::cin >> taskNumber;

    // Handle invalid input type or out-of-range task number
    if (std::cin.fail() || taskNumber < 1 || taskNumber > static_cast<int>(tasks.size())) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Error: Invalid task number.\n";
        return;
    }

    // Clear leftover newline character after reading the integer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string removedTask = tasks[taskNumber - 1];
    tasks.erase(tasks.begin() + (taskNumber - 1));
    std::cout << "Task \"" << removedTask << "\" has been removed." << std::endl;
}

// =============================================================================
// MAIN FUNCTION
// =============================================================================
int main() {
    std::vector<std::string> tasks;
    int choice = 0;

    while (true) {
        displayMenu();
        std::cin >> choice;

        // Handle non-integer input gracefully
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid choice. Please enter a number between 1 and 4.\n";
            continue;
        }

        // Clear the trailing newline character from the buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choice == 1) {
            addTask(tasks);
        } else if (choice == 2) {
            viewTasks(tasks);
        } else if (choice == 3) {
            deleteTask(tasks);
        } else if (choice == 4) {
            std::cout << "Goodbye!" << std::endl;
            break;
        } else {
            std::cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        }
    }

    return 0;
}