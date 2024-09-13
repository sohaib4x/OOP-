#include <iostream>
using namespace std;

int find_max(int*, int); //function prototype

int main() {
    int arr[5] = {4, 5, 10, 3, 20};
    int size = 5;
    
    int max_value = find_max(arr, size); //function calling
    
    cout << "largest element = " << max_value << endl; //print largest element
    
    return 0;
}

int find_max(int *arr, int size) { //function definition with pointer parameter *arr and value parameter size
    int *max = arr;     // *max is assigned to base address of array
    int *ptr = arr + 1;  // arr + 1 bcz we're gonna start comparing from 2nd element

    while (ptr < arr+5) {  // will continue till it reaches the bounds of array
        if (*ptr > *max) { // checking the maximum
            max = ptr;  
        }
        ptr++;
    }
    
    return *max;  
}