#include <iostream>
using namespace std;

void toh(int n, char a, char b, char c){
	if(n==1){
		cout << "Move disk " << a  << " to disk " << c <<endl;
	}
	else{
		toh(n-1, a, c, b);
		toh(1, a, b, c);
		toh(n-1, b, a, c);
	}
}

int main(int argc, char const *argv[])
{
	int n = 3;
	toh(n, 'A', 'B', 'C');	
	return 0;
}`