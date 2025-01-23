#include <iostream>
using namespace std;

class A {
public:
    int *ptr;
    int size;

    // Constructor with input
    A(int size) {
        this->size = size;
        ptr = new int[size];
        cout << "Enter values:" << endl;
        for (int i = 0; i < size; i++) {
            cin >> ptr[i];
        }
    }

    // Default constructor
    A(int size, bool initialize) {
        this->size = size;
        ptr = new int[size];
        if (initialize) {
            for (int i = 0; i < size; i++) {
                ptr[i] = 0; // Initialize with zeros or any default value
            }
        }
    }

    // Overloaded + operator
    A operator+(A &obj) {
        A temp(size, true); // Create temp without asking for input
        for (int i = 0; i < size; i++) {
            temp.ptr[i] = ptr[i] + obj.ptr[i];
        }
        return temp;
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << ptr[i] << " ";
        }
        cout << endl;
    }

    ~A() {
        delete[] ptr; // Free the dynamically allocated memory
    }
};

int main() {
    A obj1(4), obj2(4);

    A obj3 = obj1 + obj2; // No input required for obj3
    obj3.print();
}

