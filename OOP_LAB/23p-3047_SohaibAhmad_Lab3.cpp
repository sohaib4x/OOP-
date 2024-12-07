#include <iostream>
using namespace std;

//Define a structure to store student information
struct Student_type {
    string studentFname = "N/A"; 
    string studentLname = "N/A"; 
    int test_score = 0;          
    char grade = '-';             
    
};

// Function to input student data
void student_data(Student_type students[]) {
    for(int i = 0; i < 5; i++) {
        cout << "Enter first name of student " << i + 1 << ": ";
        cin >> students[i].studentFname; // Input first name
        
        cout << "Enter last name of student " << i + 1 << ": ";
        cin >> students[i].studentLname; // Input last name
        
        cout << "Enter test score of student " << i + 1 << ": ";
        cin >> students[i].test_score; // Input test score
    }
}

//Function to assign grades based on test scores
void student_grade(Student_type students[]) {
    for(int i = 0; i < 5; i++) {
        //Calculating and assigning grades based on the test score
        if(students[i].test_score >= 80)
            students[i].grade = 'A';
        else if(students[i].test_score >= 70)
            students[i].grade = 'B';
        else if(students[i].test_score >= 60)
            students[i].grade = 'C';
        else if(students[i].test_score >= 50)
            students[i].grade = 'D';
        else
            students[i].grade = 'F'; 
    }
}

//Function to find the highest test score among students
int highest_testscore(Student_type students[]) {
    int maximum = students[0].test_score; // Initialize maximum with the first student's score
    for(int i = 0; i < 5; i++) {
        if(students[i].test_score > maximum) {
            maximum = students[i].test_score; 
        }
    }
    return maximum; //Return the highest score
}

//Function to print the highest scorer
void highest_scorer(Student_type students[], int maximum) {
    cout << "Maximum Scorer(s):" << endl;
    for(int i = 0; i < 5; i++) {
        if(students[i].test_score == maximum) {
            // Print the name of the student(s) with the highest score
            cout << students[i].studentFname << " " << students[i].studentLname << endl;
        }
    }
}

//Main function
int main() {
    Student_type students[5]; // Array to hold information of 5 students
    
    student_data(students); //Calling input student data function
    student_grade(students); //Calling grade function
    
    int highest_score = highest_testscore(students); // Get highest score
    
    highest_scorer(students, highest_score); // Display the highest scorer

    return 0; 
}