/*
 * Developer: David Anderson
 * Date: 4/19/2026
 * Project: Project Three Corner Grocer
 * Description: Item tracker for groceries, providing a search, list, and histogram function based on user input. 
  */

#include "GroceryTracker.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm> // Required for std::transform for case-insensitive searching functionality

using namespace std;

// Constructor handles startup tasks: loading data and creating frequency.dat
GroceryTracker::GroceryTracker(const string& inputFileName) {
    loadInitialData(inputFileName);
    createBackupFile("frequency.dat");
}

// Converts strings to lowercase to ensure case-insensitive matching
string GroceryTracker::toLowerCase(string text) {
    transform(text.begin(), text.end(), text.begin(), ::tolower);
    return text;
}

// Ingests data and standardizes keys to lowercase for consistency
void GroceryTracker::loadInitialData(const string& inputFileName) {
    ifstream inputFile(inputFileName);
    string item;

    if (inputFile.is_open()) {
        while (inputFile >> item) {
            // Apply lowercase standardization during ingestion
            string lowerItem = toLowerCase(item);
            itemFrequencyMap[lowerItem]++;
        }
        inputFile.close();
    } else {
        cout << "Error: " << inputFileName << " could not be opened." << endl;
    }
}

// Automatically creates the backup file required by the requirements
void GroceryTracker::createBackupFile(const string& outputFileName) {
    ofstream outFile(outputFileName);
    if (outFile.is_open()) {
        for (auto const& [item, count] : itemFrequencyMap) {
            outFile << item << " " << count << endl;
        }
        outFile.close();
    }
}

// Option 1: Case-insensitive search for items in the input file
void GroceryTracker::getSpecificItemFrequency() {
    string searchItem;
    cout << "Enter the item name you wish to look for: ";
    cin >> searchItem;

    // Standardize input for the search
    string lowerSearch = toLowerCase(searchItem);

    // Check map and output specific "not found" message if frequency is 0
    if (itemFrequencyMap.count(lowerSearch) && itemFrequencyMap[lowerSearch] > 0) {
        cout << searchItem << ": " << itemFrequencyMap[lowerSearch] << endl;
    } else {
        cout << "No item found for: " << searchItem << endl;
    }
}

// Option 2: Formatted list of all item frequencies
void GroceryTracker::displayAllFrequencies() {
    cout << "\n--- Full Inventory List ---" << endl;
    for (auto const& [item, count] : itemFrequencyMap) {
        // Use setw(15) to create a clean, organized column layout
        cout << left << setw(15) << item << " " << count << endl;
    }
}

// Option 3: Graphical text-based histogram
void GroceryTracker::displayHistogram() {
    cout << "\n--- Inventory Histogram ---" << endl;
    for (auto const& [item, count] : itemFrequencyMap) {
        cout << left << setw(15) << item << " ";
        // Loop to print one asterisk for each item counted
        for (int i = 0; i < count; ++i) {
            cout << "*";
        }
        cout << endl;
    }
}