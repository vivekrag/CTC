#include <iostream>

using namespace std;

// Using Extra Matrix O(N*2) Space and Time
void rotateMatrix1(int Matrix[][3], int n){
	int output[n][n];
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			output[j][n-1-i] = Matrix[i][j];
		}	
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++)
		cout << output[i][j] << " ";
	cout << endl;
	}	
}
// Using Same Matrix O(N*2) Time and O(1) Space
void swap(int &a, int &b){
	int t = a;
	a = b;
	b = t;
}

void rotateMatrixRight(int Matrix[][3], int n){
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++)
			swap(Matrix[i][j],Matrix[j][i]);	
	}	
	for(int j=0; j<n/2; j++){
		for(int i=0; i<n; i++)
			swap(Matrix[i][j],Matrix[i][n-1-j]);	
	}
}

void rotateMatrixLeft(int Matrix[][3], int n){
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++)
			swap(Matrix[i][j],Matrix[j][i]);	
	}	
	for(int i=0; i<n/2; i++){
		for(int j=0; j<n; j++)
			swap(Matrix[i][j],Matrix[n-1-i][j]);	
	}
}

int main(){
	int mat[][3] = {{1,2,3,},{4,5,6},{7,8,9}};
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++)
			cout << mat[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	rotateMatrixLeft(mat,3);
	rotateMatrixRight(mat,3);
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++)
			cout << mat[i][j] << " ";
		cout << endl;
	}
	return 0;
}