#include <iostream>

using namespace std;

void deleteRowColumn(int matrix[][3], int m, int n){
	bool* row = new bool[m];
	bool* column = new bool[n];
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(matrix[i][j]==0){
				row[i] = true;
				column[j] = true;
			}
		}
	}
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++)
			if(row[i]||column[j])
				matrix[i][j]=0;
	}		
}

int main(){
	int mat[][3] = {{0,2,3,},{4,5,0},{7,8,9}};
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++)
			cout << mat[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	deleteRowColumn(mat,3,3);
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++)
			cout << mat[i][j] << " ";
		cout << endl;
	}
return 0;
}	