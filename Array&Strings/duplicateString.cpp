#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;

// running time O(n) and running space O(n)
bool isUnique1(string s){
	int len = s.length();
	bool* check = new bool[len];
	for(int i = 0; i < len; i++){
		int val = (int) s[i];
		if(check[val] || check[val+32])
			return false;
		else{ 
			 check[val] = true;
			 check[val+32] = true;
		}
	}
	return true;
}
// reduces the space used to a factor of 8 by using a bit vector

bool isUnique2(string s){
	int len = s.length();
	int check = 0;
	for(int i = 0; i<len; i++){
		int val = (int)(s[i] - 'a');
		if(check & (1 << val))
			return false;
		else
			check |= (1 << val);
	}
	return true;
}

bool isUnique3(string s)
{
    int check[8];
    memset(check, 0, sizeof(check));
    int len = s.length();
    for(int i=0; i<len; ++i)
    {
        int v = (int)s[i];
        int ix = v/32;
        int shift = v%32;
        if(check[ix] & (1<<shift)) return false;
        check[ix] |= (1<<shift);
    }
    return true;
}

int main(){
	string u = "abcdef";
	cout << isUnique3(u) << endl;
    isUnique3(u) ? cout << "unique" : cout << "not unique";
	return 0;
}