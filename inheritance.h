#ifndef EMPLOYEE_H  // Include guards to prevent multiple inclusion
#define EMPLOYEE_H

#include <string>

// Abstract base class Employee
class Employee {
private:
    std::string name;  // Private member variable to store the employee's name

public:
    // Constructor to initialize the name when an Employee object is created
    Employee(const std::string& _name);

    // Pure virtual functions, making this class abstract, as they have no implementation here
    // These functions need to be implemented by derived classes
    virtual double calculateSalary() = 0;
    virtual double calculateHealthCareContributions() = 0;
    virtual int calculateVacationDays() = 0;

    // Function to display employee details
    void displayEmployeeInfo();
};

// Derived class Professional, inheriting from Employee
class Professional : public Employee {
private:
    int vacationDays;     // Private member variable to store vacation days
    int monthlySalary;    // Private member variable to store monthly salary

public:
    // Constructor for Professional, initializing name, vacationDays, and monthlySalary
    Professional(const std::string& _name, int _vacationDays, int _monthlySalary);

    // Implementing the pure virtual functions from the base class
    double calculateSalary();
    double calculateHealthCareContributions();
    int calculateVacationDays();
};

// Derived class Nonprofessional, inheriting from Employee
class Nonprofessional : public Employee {
private:
    double hourlyRate;    // Private member variable to store hourly rate
    double hoursWorked;   // Private member variable to store hours worked

public:
    // Constructor for Nonprofessional, initializing name, hourlyRate, and hoursWorked
    Nonprofessional(const std::string& _name, double _hourlyRate, double _hoursWorked);

    // Implementing the pure virtual functions from the base class
    double calculateSalary();
    double calculateHealthCareContributions();
    int calculateVacationDays();
};

#endif // EMPLOYEE_H