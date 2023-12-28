#include "inheritance.h"  // Include the header file containing class declarations
#include <iostream>

// Implementation of Employee class constructor
Employee::Employee(const std::string& _name) : name(_name) {}

// Function to display employee information
void Employee::displayEmployeeInfo() {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Weekly Salary: $" << calculateSalary() << std::endl;
    std::cout << "Health Care Contributions: $" << calculateHealthCareContributions() << std::endl;
    std::cout << "Vacation Days Earned: " << calculateVacationDays() << " days" << std::endl;
}

// Implementation of Professional class constructor
Professional::Professional(const std::string& _name, int _vacationDays, int _monthlySalary)
    : Employee(_name), vacationDays(_vacationDays), monthlySalary(_monthlySalary) {}

// Function to calculate weekly salary for professional employees
double Professional::calculateSalary() {
    return monthlySalary;
}

// Function to calculate health care contributions for professional employees
double Professional::calculateHealthCareContributions() {
    return calculateSalary() * 0.10;
}

// Function to calculate vacation days earned for professional employees
int Professional::calculateVacationDays() {
    return vacationDays;
}

// Implementation of Nonprofessional class constructor
Nonprofessional::Nonprofessional(const std::string& _name, double _hourlyRate, double _hoursWorked)
    : Employee(_name), hourlyRate(_hourlyRate), hoursWorked(_hoursWorked) {}

// Function to calculate weekly salary for nonprofessional employees
double Nonprofessional::calculateSalary() {
    return hourlyRate * hoursWorked;
}

// Function to calculate health care contributions for nonprofessional employees
double Nonprofessional::calculateHealthCareContributions() {
    return calculateSalary() * 0.05;
}

// Function to calculate vacation days earned for nonprofessional employees
int Nonprofessional::calculateVacationDays() {
    return static_cast<int>(hoursWorked / 40);
}

/**
 * @brief The main function for managing employee creation and information display.
 *
 * This function provides a text-based menu for creating and displaying information about employees.
 * It allows the user to create both professional and nonprofessional employees, enter their details,
 * and view their information.
 *
 * @return An integer indicating the exit status of the program.
 */
int main() {
    int choice;              // User's menu choice
    std::string name;        // Employee's name
    int vacationDays, monthlySalary; // Variables for professional employee
    double hourlyRate, hoursWorked; // Variables for nonprofessional employee

    while (true) {
        std::cout << "Menu:\n";
        std::cout << "1. Create Professional Employee\n";
        std::cout << "2. Create Nonprofessional Employee\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";

        // Get the user's choice from the menu
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        Professional profEmployee("", 0, 0); // Initialize a professional employee object
        Nonprofessional nonprofEmployee("", 0.0, 0.0); // Initialize a nonprofessional employee object

        switch (choice) {
            case 1:
                std::cout << "Enter Professional Employee's Name: ";
                std::cin >> name;
                std::cout << "Enter Number of Vacation Days: ";
                if (!(std::cin >> vacationDays)) {
                    std::cout << "Invalid input. Please enter a number.\n";
                    break;
                }
                std::cout << "Enter Monthly Salary in $: ";
                if (!(std::cin >> monthlySalary)) {
                    std::cout << "Invalid input. Please enter a number.\n";
                    break;
                }
                profEmployee = Professional(name, vacationDays, monthlySalary);
                std::cout << "Professional Employee Information:\n";
                profEmployee.displayEmployeeInfo();
                break;

            case 2:
                std::cout << "Enter Nonprofessional Employee's Name: ";
                std::cin >> name;
                std::cout << "Enter Hourly Rate in $: ";
                if (!(std::cin >> hourlyRate)) {
                    std::cout << "Invalid input. Please enter a number.\n";
                    break;
                }
                std::cout << "Enter Hours Worked: ";
                if (!(std::cin >> hoursWorked)) {
                    std::cout << "Invalid input. Please enter a number.\n";
                    break;
                }
                nonprofEmployee = Nonprofessional(name, hourlyRate, hoursWorked);
                std::cout << "Nonprofessional Employee Information:\n";
                nonprofEmployee.displayEmployeeInfo();
                break;

            case 3:
                std::cout << "Exiting program.\n";
                return 0;

            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
