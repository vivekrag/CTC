#include "Stack.h"
#include <iostream>
#include <string.h>

using namespace std;

int reverseString(char str[]){
	int len = strlen(str);
	Stack s(len);
	for(int i = 0; i < len; i++){
		if(!s.full())
		s.push(str[i]);
	}
	for(int i = 0; i < len; i++){
		if(!s.empty())
		str[i] = s.pop();
	}
	return 0;
}

int main(){
	char str[] = "Niranjan Mohan";
	reverseString(str);
	cout << "Reverse of String is " << str;
	return 0;
}