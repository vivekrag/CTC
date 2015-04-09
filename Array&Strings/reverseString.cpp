#include <iostream>
#include <cstring>
using namespace std;

void reverse(const char* p){
	int len = strlen(p);
	for(int i = len-1; i>=0; i--){
		cout << p[i];
	}
}

int main(){
	char str[] = "123456789";
	const char* p = "vivek"; 
	reverse(p);
	return 0;
}

// void reverse(string str){
// 	int len = str.length();
// 	for(int i = len-1; i>=0; i--){
// 		cout << str[i];
// 	}
// }

// int main(){
// 	string str = "123456789";
// 	reverse(str);
// 	return 0;
//}