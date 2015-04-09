#include <iostream>
using namespace std;

void twoSorted(int a[], int b[], int lenA, int lenB){
	int lastA=lenA-1;
	int lastB=lenB-1;
	int c = lenA+lenB-1;
	while(lastA>=0 && lastB>=0){
	 if(a[lastA]>b[lastB]){
		a[c]=a[lastA];
		c--;
		lastA--;
	 }else{
	 	a[c]=b[lastB];
	 	c--;
	 	lastB--;
	 }	
	}
	while(lastA >=0){
		a[c]=a[lastA];
		c--;
		lastA--; 
	}
	for(int i=0; i<(lenA+lenB); i++)
		cout << a[i] << " ";
}

int main(int argc, char const *argv[])
{
	int a[50] = {11,21,31,41,52,66,78};
	int b[10] = {10,22,30,40,53,67};
	twoSorted(a,b,7,6);
	return 0;
	}