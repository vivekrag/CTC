#include <iostream>
#include <cstring>

using namespace std;

void replaceSpace1(char str[])
{
	int len = strlen(str);
	int count = 0;
	for(int i=0; i<strlen(str); i++){
		if(str[i] == ' ')
			count++;
	}
	int newLen = len + (count*2);
	str[newLen] = '\0';
	for(int i=len-1; i>=0; i--){
		if(str[i] == ' '){
			str[newLen-1] = '0';
			str[newLen-2] = '2';
			str[newLen-3] = '%';
			newLen=newLen-3;
		}
		else{
			str[newLen-1] = str[i];
			newLen--;
		}
	}
	cout << str;
}

void replaceSpace2(string str){
	int len = str.length();
	string newStr = "";
	int j = 0;
	for(int i=0; i<len; i++){
		if(str[i] == ' '){
			newStr += '%';
			newStr += '2';
			newStr += '0';
		}
		else{
			newStr += str[i];
		}
	};
	cout << newStr;
}

int main(){
	char c[100] = "vivek raghuvanshi is a good boy";
	cout << c << endl;
	replaceSpace1(c);
	cout << endl;
	string s = "vivek raghuvanshi is a good boy";
	cout << s << endl;
    replaceSpace2(s);
	return 0;
}