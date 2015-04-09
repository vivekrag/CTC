#include <iostream>
#include <cstring>
using namespace std;
bool isSubstring(string s, string t){
	if(s.find(t) != -1)
		return true;
	else
		return false;
}

bool isStringRotation(string s, string t){
	if(s.length() != t.length())
		return false;
	else
		return isSubstring((s+s),t);
}

int main(){
	string s1 = "waterbottle";
	string s2 = "ewaterbottl";
	isStringRotation(s1,s2)?cout << "yes" : cout << "no";
	return 0;
}