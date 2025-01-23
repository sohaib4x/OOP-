#include <iostream>
#include <string>
using namespace std;

// Base class: Employee
class Employee {
protected:
    string employee_name;

public:
    // Constructor
    Employee(string name) {
        employee_name = name;
    }

    // Getter for employee name
    string getName() {
        return employee_name;
    }

    // Setter for employee name
    void setName(string name) {
        employee_name = name;
    }

    // Virtual method for calculating salary
    virtual double calcSalary() = 0;  // Pure virtual function

    // Virtual method for displaying employee type
    virtual void displayEmployeeType() = 0;
};

// Derived class: HourlyEmployee
class HourlyEmployee : public Employee {
private:
    double hourly_rate;
    int hours_worked;

public:
    // Constructor
    HourlyEmployee(string name, double rate, int hours) : Employee(name) {
        hourly_rate = rate;
        hours_worked = hours;
    }

    // Override the calcSalary method
    double calcSalary() override {
        return hours_worked * hourly_rate;
    }

    // Override the displayEmployeeType method
    void displayEmployeeType() override {
        cout << "Employee Type: Hourly Employee" << endl;
        cout << "Name: " << employee_name << endl;
        cout << "Hourly Rate: " << hourly_rate << endl;
        cout << "Hours Worked: " << hours_worked << endl;
        cout << "Calculated Salary: " << calcSalary() << endl;
    }
};

// Derived class: SalariedEmployee
class SalariedEmployee : public Employee {
private:
    double annual_salary;

public:
    // Constructor
    SalariedEmployee(string name, double salary) : Employee(name) {
        annual_salary = salary;
    }

    // Override the calcSalary method
    double calcSalary() override {
        return annual_salary / 12;  // Monthly salary
    }

    // Override the displayEmployeeType method
    void displayEmployeeType() override {
        cout << "Employee Type: Salaried Employee" << endl;
        cout << "Name: " << employee_name << endl;
        cout << "Annual Salary: " << annual_salary << endl;
        cout << "Calculated Monthly Salary: " << calcSalary() << endl;
    }
};

// Function to display the menu
void displayMenu() {
    cout << "------ Employee Salary System ------" << endl;
    cout << "1. Enter Hourly Employee" << endl;
    cout << "2. Enter Salaried Employee" << endl;
    cout << "3. Display Hourly Employee Details" << endl;
    cout << "4. Display Salaried Employee Details" << endl;
    cout << "5. Exit" << endl;
    cout << "Choose an option: ";
}

int main() {
    int choice;
    int hourlyCount = 0, salariedCount = 0;
    int maxEmployees = 10;  // Initial size for dynamic memory allocation

    // Dynamic arrays for storing employee pointers
    HourlyEmployee** hourlyEmployees = new HourlyEmployee*[maxEmployees];
    SalariedEmployee** salariedEmployees = new SalariedEmployee*[maxEmployees];

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                if (hourlyCount < maxEmployees) {
                    // Input for Hourly Employee
                    string hourlyEmployeeName;
                    double hourlyRate;
                    int hoursWorked;

                    cout << "Enter Hourly Employee Name: ";
                    cin.ignore();  // To ignore leftover newline from previous input
                    getline(cin, hourlyEmployeeName);
                    cout << "Enter Hourly Rate: ";
                    cin >> hourlyRate;
                    cout << "Enter Hours Worked: ";
                    cin >> hoursWorked;

                    // Dynamically create an HourlyEmployee object
                    hourlyEmployees[hourlyCount] = new HourlyEmployee(hourlyEmployeeName, hourlyRate, hoursWorked);
                    cout << "Hourly Employee Salary Calculated: " << hourlyEmployees[hourlyCount]->calcSalary() << endl;
                    hourlyCount++;
                } else {
                    cout << "No more space for hourly employees!" << endl;
                }
                break;
            }
            case 2: {
                if (salariedCount < maxEmployees) {
                    // Input for Salaried Employee
                    string salariedEmployeeName;
                    double annualSalary;

                    cout << "Enter Salaried Employee Name: ";
                    cin.ignore();  // To ignore leftover newline from previous input
                    getline(cin, salariedEmployeeName);
                    cout << "Enter Annual Salary: ";
                    cin >> annualSalary;

                    // Dynamically create a SalariedEmployee object
                    salariedEmployees[salariedCount] = new SalariedEmployee(salariedEmployeeName, annualSalary);
                    cout << "Salaried Employee Monthly Salary Calculated: " << salariedEmployees[salariedCount]->calcSalary() << endl;
                    salariedCount++;
                } else {
                    cout << "No more space for salaried employees!" << endl;
                }
                break;
            }
            case 3: {
                // Display all Hourly Employee Details
                if (hourlyCount > 0) {
                    cout << "----- Hourly Employees -----" << endl;
                    for (int i = 0; i < hourlyCount; i++) {
                        cout << "Employee #" << i + 1 << ":" << endl;
                        hourlyEmployees[i]->displayEmployeeType();
                        cout << "--------------------------" << endl;
                    }
                } else {
                    cout << "No hourly employee data available." << endl;
                }
                break;
            }
            case 4: {
                // Display all Salaried Employee Details
                if (salariedCount > 0) {
                    cout << "----- Salaried Employees -----" << endl;
                    for (int i = 0; i < salariedCount; i++) {
                        cout << "Employee #" << i + 1 << ":" << endl;
                        salariedEmployees[i]->displayEmployeeType();
                        cout << "--------------------------" << endl;
                    }
                } else {
                    cout << "No salaried employee data available." << endl;
                }
                break;
            }
            case 5:
                cout << "Exiting the system..." << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }

        cout << endl;  // Add some space between iterations
    } while (choice != 5);

    // Deallocate the memory
    for (int i = 0; i < hourlyCount; i++) {
        delete hourlyEmployees[i];
    }
    for (int i = 0; i < salariedCount; i++) {
        delete salariedEmployees[i];
    }
    delete[] hourlyEmployees;
    delete[] salariedEmployees;

    return 0;
}

