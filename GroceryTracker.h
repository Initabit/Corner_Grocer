/*
 * Developer: David Anderson
 * Date: 4/19/2026
 * Project: Project Three Corner Grocer
 * Description: Item tracker for groceries, providing a search, list, and histogram function based on user input. 
  */

#ifndef GROCERY_TRACKER_H
#define GROCERY_TRACKER_H

#include <map>
#include <string>

/**
 * Class: GroceryTracker
 * Purpose: Manages grocery item data, handles file ingestion, 
 * and provides frequency analysis.
 */
class GroceryTracker {
private:
    // Map to store item names (standardized to lowercase) and their frequencies
    std::map<std::string, int> itemFrequencyMap;

    // Helper function to standardize strings for case-insensitive operations
    std::string toLowerCase(std::string text);

    // Internal methods for handling data persistence
    void loadInitialData(const std::string& inputFileName);
    void createBackupFile(const std::string& outputFileName);

public:
    // Constructor initializes the program and creates the backup file
    GroceryTracker(const std::string& inputFileName);

    // Public methods corresponding to the menu options
    void getSpecificItemFrequency(); // Option 1
    void displayAllFrequencies();   // Option 2
    void displayHistogram();        // Option 3
};

#endif