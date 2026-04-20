/*
 * Developer: David Anderson
 * Date: 4/19/2026
 * Project: Project Three Corner Grocer
 * Description: Item tracker for groceries, providing a search, list, and histogram function based on user input. 
  */

#include "GroceryTracker.h"
#include <iostream>

using namespace std;

int main() {
    // Instantiate tracker; this triggers file ingestion and backup creation
    GroceryTracker tracker("input_file.txt");
    int userChoice = 0;

    // Main loop for the user menu
    while (userChoice != 4) {
        cout << "\n********** Corner Grocer Inventory System **********" << endl;
        cout << "1. Search for an item" << endl;
        cout << "2. Display all items (numeric)" << endl;
        cout << "3. Display histogram" << endl;
        cout << "4. Exit program" << endl;
        cout << "Please enter your choice (1-4): ";

        // Input validation to prevent crashes from non-numeric input
        if (!(cin >> userChoice)) {
            cout << "Invalid input. Please enter a valid number (1-4)." << endl;
            cin.clear();           // Clear error flags
            cin.ignore(100, '\n'); // Discard bad input
            continue;
        }

        switch (userChoice) {
            case 1:
                tracker.getSpecificItemFrequency();
                break;
            case 2:
                tracker.displayAllFrequencies();
                break;
            case 3:
                tracker.displayHistogram();
                break;
            case 4:
                cout << "Closing program. Thank you!" << endl; // Option 4 
                break;
            default:
                cout << "Invalid selection. Choose 1, 2, 3, or 4." << endl;
        }
    }

    return 0;
}