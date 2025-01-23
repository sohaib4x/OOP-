#include <iostream>
using namespace std;

class Phone_payments {
private:
    double phone_price;
    double monthly_payment;
    int total_months;
    double remaining_amount;

public:
    Phone_payments(double phone_price = 0, double monthly_payment = 0, int total_months = 0, double remaining_amount = 0) {
        cout << "Enter the price of your phone: ";
        cin >> phone_price;
        this->phone_price = phone_price;
        this->monthly_payment = (phone_price / 100) * 20;
        this->total_months = total_months;
        this->remaining_amount = phone_price;
    }

    void make_payment() {
        char choice;
        cout << "\nHave you paid your installment this month? (y/n): ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            if (remaining_amount > 0) {
                remaining_amount -= monthly_payment;
                total_months++;
                if (remaining_amount < 0) {
                    remaining_amount = 0; 
                }
                cout << "Payment received. Remaining amount = " << remaining_amount << endl;
            } else {
                cout << "The phone is already paid off!" << endl;
            }
        } else {
            // Adding 2% of the original price to the remaining amount
            remaining_amount += (phone_price / 100) * 2;
            cout << "Payment not made. New remaining amount: " << remaining_amount << endl;
        }
    }

    void display_status() const {
        cout << "Total months paid: " << total_months << endl;
        cout << "Remaining amount: " << remaining_amount << endl;
    }

    double get_remaining_amount() const {
        return remaining_amount;
    }
};

int main() {
    Phone_payments phone;

    while (phone.get_remaining_amount() >= 0) {
        phone.make_payment();
        phone.display_status();
        
        //Check if remaining amount is less than or equal to zero
        if (phone.get_remaining_amount() <= 0) {
            cout <<"The phone is fully paid off. Exiting the loop." << endl;
            break;
        }
    }

    return 0;
}
