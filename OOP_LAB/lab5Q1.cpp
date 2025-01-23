#include <iostream>
using namespace std;

class GenerateRollNumber {
private: 
    string name;
    int rollNo; 
    static int counter;  

public:
    GenerateRollNumber(string n) : name(n) {
        rollNo = 1000 + ++counter;  // Increment counter and assign roll number
    }

    void display() const {
        cout << "Name: " << name << endl;
        cout << "Roll Number: 23p-" << rollNo << endl;
    }
};

int GenerateRollNumber::counter = 0;  // Initialize counter to 0

int main() {
    string name1, name2, name3;

    cout << "Enter name for student 1: ";
    cin >> name1;
    GenerateRollNumber student1(name1);  // Create student1 object

    cout << "Enter name for student 2: ";
    cin >> name2;
    GenerateRollNumber student2(name2);  // Create student2 object
    
    cout << "Enter name for student 3: ";
    cin >> name3;
    GenerateRollNumber student3(name3);  // Create student3 object

    cout << "\nStudent Details:\n";
    student1.display();
    student2.display();
    student3.display();

    return 0;
}
