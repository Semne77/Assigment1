#include "makearray.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// Constructor for the 'makearray' class
makearray::makearray() : size(0) {}

// Read integers from a file and populate the array
void makearray::readFromFile() {
    ifstream inputFile;
    inputFile.open("numbers1.txt");

    if (!inputFile) {
        cerr << "Error: Could not open the file." << endl;
        return;
    }

    string line;

    while (getline(inputFile, line)) {
        stringstream iss(line);
        string token;

        while (getline(iss, token, ',')) {
            int number;
            if (istringstream(token) >> number) {
                if (size < 120) {
                    intArray[size] = number;
                    //cout << number << endl;
                    size++;
                } else {
                    cerr << "Error: Array is full." << endl;
                }
            }
        }
    }

    inputFile.close();
}

// Search for a number in the array and print the result
void makearray::inArray(int num) {
    for (int i = 0; i < size; i++) {
        if (intArray[i] == num) {
            cout << to_string(num) + " found at index " + to_string(i) << endl;
            return; // Exit the function if the number is found
        }
    }
    cout << to_string(num) + " not found in the array." << endl;
}

// Modify the value at a given index in the array
void makearray::modifyValueAtIndex(int index, int newValue) {
    try {
        if (index >= 0 && index < size) {
            int oldValue = intArray[index];
            intArray[index] = newValue;
            cout << "Value at index " + to_string(index) + " changed from " + to_string(oldValue) + " to " + to_string(newValue) << endl;
        } else {
            throw out_of_range("Error: Invalid index.");
        }
    } catch (const exception& e) {
        cerr << e.what() << endl; // Print error message if index is out of range
    }
} 

// Add an integer to the end of the array
void makearray::addToArray(int add) {
    try {
        if (size < 120) {
            intArray[size] = add;
            size++;
            cout << "Added " + to_string(add) + " to the end of the array." << endl;
        } else {
            throw overflow_error("Error: Array is full.");
        }
    } catch (const exception& e) {
        cerr << e.what() << endl; // Print error message if the array is full
    }
}

// Replace the value at a given index with zero
void makearray::replaceZero(int index) {
    if (index >= 0 && index < size) {
        intArray[index] = 0;
    } else {
        cerr << "Error: Invalid index." << endl;
    }
}

// Print the current contents of the array
void makearray::printArray() {
    cout << "Current Array:" << endl;
    for (int i = 0; i < size; i++) {
        cout << intArray[i] << " ";
    }
    cout << endl;
}

int main() {
    makearray arrayObj; // Create an instance of the 'makearray' class
    arrayObj.readFromFile(); // Read data from a file into the 'intArray'

    string userInput; // Variable to store user's command

    while (true) { // Start an infinite loop
        cout << "Enter a command (inArray, modify, add, replace, print, end): ";
        cin >> userInput; // Read the user's command

        if (userInput == "end") {
            break; // Exit the loop and end the program if the user enters "end"
        } else if (userInput == "inArray") {
            int numToFind;
            cout << "Enter a number to find: ";
            cin >> numToFind; // Read the number to search for in the array
            arrayObj.inArray(numToFind); // Call the 'inArray' function to search for the number
        } else if (userInput == "modify") {
            int index, newValue;
            cout << "Enter index and new value separated by a blank space: ";

            try {
                if (cin >> index >> newValue) {
                    // If user enters valid integers for index and newValue
                    arrayObj.modifyValueAtIndex(index, newValue); // Modify the value at the specified index
                } else {
                    throw invalid_argument("Invalid input. Please enter valid integers.");
                    // If user enters non-integer values, throw an exception
                }
            } catch (const invalid_argument& e) {
                cerr << e.what() << endl; // Print an error message for invalid input
                cin.clear(); // Clear error state
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Flush input buffer
            }
        } else if (userInput == "add") {
            int add;
            cout << "Enter a value to add: ";

            try {
                if (cin >> add) {
                    // If user enters a valid integer for 'add'
                    arrayObj.addToArray(add); // Add the value to the end of the array
                } else {
                    throw invalid_argument("Invalid input. Please enter a valid integer.");
                    // If user enters a non-integer value, throw an exception
                }
            } catch (const invalid_argument& e) {
                cerr << e.what() << endl; // Print an error message for invalid input
                cin.clear(); // Clear error state
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Flush input buffer
            }
        } else if (userInput == "replace") {
            int index;
            cout << "Enter index to replace with zero: ";
            cin >> index; // Read the index to replace with zero
            arrayObj.replaceZero(index); // Call the 'replaceZero' function to perform the replacement
        } else if (userInput == "print") {
            arrayObj.printArray(); // Call the 'printArray' function to display the current array
        } else {
            cout << "Invalid command. Try again." << endl; // Inform the user of an invalid command
        }
    }

    return 0; // End the program
}