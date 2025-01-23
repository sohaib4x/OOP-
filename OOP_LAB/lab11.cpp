#include <iostream>
#include <string>
using namespace std;

class Salary {
    private:
        int basic_salary;
        int medical_allowance;
        int gross_salary;

    public:
        Salary(int basic, int allowance) {
            basic_salary = basic;
            medical_allowance = allowance;
            computeGrossSalary();
        }

        void computeGrossSalary() {
            gross_salary = basic_salary + medical_allowance;
        }

        int getBasicSalary() {
            return basic_salary;
        }

        int getGrossSalary() {
            return gross_salary;
        }

        int getMedicalAllowance() {
            return medical_allowance;
        }
};

class Employee {
    private:
        string name;
        int id;
        Salary salaryDetails;

    public:
        Employee(string empName, int empId, int basic, int allowance)
            : name(empName), id(empId), salaryDetails(basic, allowance) {}

        void displayEmployeeDetails() {
            cout << "Employee Name: " << name << endl;
            cout << "Employee ID: " << id << endl;
            cout << "Basic Salary: " << salaryDetails.getBasicSalary() << endl;
            cout << "Medical Allowance: " << salaryDetails.getMedicalAllowance() << endl;
            cout << "Gross Salary: " << salaryDetails.getGrossSalary() << endl;
        }
};

int main() {
    Employee employee1("Ali", 1234, 2500000, 500000);
    employee1.displayEmployeeDetails();

    return 0;
}
