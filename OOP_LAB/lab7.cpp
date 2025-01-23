#include <iostream>
#include <string>
using namespace std;

const int MAX_EMPLOYEES = 10;  // Maximum number of employees that can be stored

// Base class SalaryData
class SalaryData {
private:
    // Salaries for grades
    const float gradeSalaries[5] = {250000, 200000, 150000, 100000, 50000};

protected:
    // Method to get the salary for a specific grade
    float getSalaryByGrade(int grade) {
        if (grade >= 1 && grade <= 5)
            return gradeSalaries[grade - 1];
        else
            return 0;  // Invalid grade
    }
};

// Derived class CalculateDeduction from SalaryData
class CalculateDeduction : public SalaryData {
protected:
    int no_of_offDays;
    int shortleavehr;
    int employeenoOfOffDays;
    int employeenoOfHours;

public:
    // Constructor to initialize deduction-related members
    CalculateDeduction(int offDays, int shortLeaveTime)
        : employeenoOfOffDays(offDays), employeenoOfHours(shortLeaveTime) {
        no_of_offDays = 2;  // 2 days allowed without deduction
        shortleavehr = 15;  // 15 hours allowed without deduction
    }

    // Method to calculate salary deduction based on offDays and short leave hours
    float calculateSalaryDeduction(int grade) {
        float salary = getSalaryByGrade(grade);

        // Deduct 2% for every extra off day above allowed limit
        if (employeenoOfOffDays > no_of_offDays) {
            int extraOffDays = employeenoOfOffDays - no_of_offDays;
            salary -= salary * (extraOffDays * 0.02);  // 2% deduction for each extra day
        }

        // Deduct 1% if short leave exceeds allowed hours
        if (employeenoOfHours > shortleavehr) {
            salary -= salary * 0.01;  // 1% deduction
        }

        return salary;
    }
};

// FinalSalary class derived from CalculateDeduction
class FinalSalary : public CalculateDeduction {
private:
    string name;
    int employeeId;
    int grade;
    int offDays;
    int shortLeaveTime;
    float salary;

public:
    // Constructor to initialize the data members
    FinalSalary(string empName, int empId, int empGrade, int empOffDays, int empShortLeaveTime)
        : CalculateDeduction(empOffDays, empShortLeaveTime), name(empName), employeeId(empId),
          grade(empGrade), offDays(empOffDays), shortLeaveTime(empShortLeaveTime), salary(0.0f) {
        // Calculate and set the salary after deductions
        setSalary(calculateSalaryDeduction(grade));
    }

    // Setter to update the salary
    void setSalary(float calculatedSalary) {
        salary = calculatedSalary;
    }

    // Getter to retrieve the final salary
    float getSalary() {
        return salary;
    }

    // Method to display the employee details
    void displaySalaryDetails() {
        cout << "Employee Name: " << name << endl;
        cout << "Employee ID: " << employeeId << endl;
        cout << "Grade: " << grade << endl;
        cout << "Final Salary: $" << salary << endl;
    }
};

// Function to display the menu
void displayMenu() {
    cout << "------ Salary Calculation System ------" << endl;
    cout << "1. Add Employee and Calculate Salary" << endl;
    cout << "2. Display All Employee Details" << endl;
    cout << "3. Exit" << endl;
    cout << "--------------------------------------" << endl;
    cout << "Enter your choice: ";
}

int main() {
    FinalSalary* employees[MAX_EMPLOYEES] = {nullptr};  // Array to store employee objects
    int employeeCount = 0;  // Number of employees added so far
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1: {
            // Check if we can add more employees
            if (employeeCount >= MAX_EMPLOYEES) {
                cout << "Maximum number of employees reached. Cannot add more." << endl;
                break;
            }

            // Input employee details
            string name;
            int id, grade, offDays, shortLeaveTime;
            cout << "Enter Employee Name: ";
            cin.ignore();  // Clear input buffer
            getline(cin, name);  // Get the full name with spaces
            cout << "Enter Employee ID: ";
            cin >> id;
            cout << "Enter Grade (1 to 5): ";
            cin >> grade;
            cout << "Enter Number of Off Days: ";
            cin >> offDays;
            cout << "Enter Short Leave Time (in hours): ";
            cin >> shortLeaveTime;

            // Create a new employee object and store it in the array
            employees[employeeCount] = new FinalSalary(name, id, grade, offDays, shortLeaveTime);
            employeeCount++;  // Increment the employee count

            cout << "Employee added and salary calculated successfully!" << endl;
            break;
        }

        case 2:
            // Display details of all employees
            if (employeeCount == 0) {
                cout << "No employees added yet." << endl;
            } else {
                for (int i = 0; i < employeeCount; i++) {
                    cout << "\nEmployee " << (i + 1) << " Details:" << endl;
                    employees[i]->displaySalaryDetails();
                }
            }
            break;

        case 3:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;

    } while (choice != 3);

    // Clean up dynamically allocated memory
    for (int i = 0; i < employeeCount; i++) {
        delete employees[i];
    }

    return 0;
}

