#include <iostream>
#include <iomanip>
using namespace std;

class SavingsAccount {
private:
    double savingsBalance;  // Private member for savings balance
    static double annualInterestRate;  // Static member for annual interest rate

public:
    // Constructor to initialize savings balance
    SavingsAccount(double balance) : savingsBalance(balance) {}

    // Static member function to modify the annual interest rate
    static void modifyInterestRate(double newRate) {
        annualInterestRate = newRate;
    }

    // Function to calculate monthly interest and update the balance
    void calculateMonthlyInterest() {
        double monthlyInterest = (savingsBalance * annualInterestRate) / 12;
        savingsBalance += monthlyInterest;
    }

    // Function to display the current balance
    void displayBalance() const {
        cout << fixed << setprecision(2) << "Current Balance: $" << savingsBalance << endl;
    }
};

// Initialize static member
double SavingsAccount::annualInterestRate = 0.03;  // Default value of 3%

int main() {
    // Create two SavingsAccount objects
    SavingsAccount saver1(2000.00);
    SavingsAccount saver2(3000.00);

    // Display initial balances
    cout << "Initial Balances:" << endl;
    saver1.displayBalance();
    saver2.displayBalance();

    // Calculate and display monthly interest
    cout << "\nCalculating monthly interest at 3%:" << endl;
    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();
    saver1.displayBalance();
    saver2.displayBalance();

    // Modify the interest rate to 4%
    SavingsAccount::modifyInterestRate(0.04);
    cout << "\nChanging interest rate to 4% and calculating next month's interest:" << endl;
    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();
    saver1.displayBalance();
    saver2.displayBalance();

    return 0;
