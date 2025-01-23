#include <iostream>
using namespace std;

class Laptop {
private:
    string brand;
    string model;
    int serial_no;
    string color;
    float price;
    int ram;
    float screen_size;

public:
    // Constructor with default parameter values
    Laptop(string brand = "HP", string model = "Core i7", int serial_no = 965, string color = "silver", 
           float price = 170000, int ram = 16, float screen_size = 15.6) {
        this->brand = brand;
        this->model = model;
        this->serial_no = serial_no;
        this->color = color;
        this->price = price;
        this->ram = ram;
        this->screen_size = screen_size; 
    }

    void ram_upgradation() {
        int increase;
        cout << "\nEnter how many GB you want to increase RAM: ";
        cin >> increase;
        ram += increase;
    }

    void display() {
    	
        cout << "\nBrand: " << brand << "\nModel: " << model << "\nSerial No: " << serial_no 
             << "\nColor: " << color << "\nPrice: " << price << "\nRAM: " << ram 
             << " GB\nScreen Size: " << screen_size << " inches" << endl;
    }
};

int main() {
    Laptop lap;  
    lap.display(); //Display values of laptop 
    lap.ram_upgradation(); // Ram upgrade function
    lap.display(); //calling display after ram upgradation.

    return 0;
}

