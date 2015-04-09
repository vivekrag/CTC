#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
bool isAnagram1(string s, string t){
	if(s.length() != t.length())
		return false;
	sort(&s[0], &s[0]+s.length());
	sort(&t[0], &t[0]+s.length());
	if(s==t)
		return true;
	else
		return false;
}

bool isAnagram2(string s, string t){
	if(s.length() != t.length())
		return false;
	int* count;
	count = new int[256];
	for(int i = 0; i<256; i++){
		count[i] = 0;
	}
	//memset(count, 0, sizeof(count));
	for(int i = 0; i < s.length(); i++){
		++count[(int)s[i]];
		--count[(int)t[i]];
	}
	for(int i = 0; i<256; i++){
		if(count[i] != 0)
			return false;
	}
	delete [] count;
	return true;
}

int main(){
	string s = "vivek";
	string t = "ekivv";
	cout<< isAnagram1(s,t);
	cout << endl;
	cout << isAnagram2(s,t);
	return 0;
}