#include<iostream>
using namespace std;
int main ()
{
    int roll_number;
    string name;
    char section;

    cout<< "Enter roll number : ";
    cin>>roll_number;
    cout<<endl;
    cout<<"Enter name : ";
    cin>>name;
    cout<<endl;
    cout<<"Enter section : ";
    cin>>section;
    cout<<endl;

    cout<<"Name is : " << name << endl <<"Roll number : " << roll_number <<endl
	 << "Section is : " << section<<endl ;
       
    return 0;
}