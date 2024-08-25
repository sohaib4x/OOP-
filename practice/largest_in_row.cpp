#include <iostream>
using namespace std;

int main(){
	int matrix[5][3] = {{20,5,6}, {7,8,2}, {10,11,9}, {
	1,2,3}, {0,14,15}};
	
	for(int row = 0; row <5; row++){
		int largest = matrix[row][0];
		for(int col = 1; col<3; col++){
		
		if(matrix[row][col]> largest){
		
		largest = matrix[row][col];
	}
	}
		cout<<"the largest element in row "<<row + 1<<" = "<<largest<<endl;	
		
	}
}
