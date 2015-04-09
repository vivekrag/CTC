#include <iostream>
#include <cstring>
 
 using namespace std;
string removeDuplicate1(string s){
  if(s.length() < 2)
    return s;
  string str = "";
  int count = 0;
  for(int i = 0; i < s.length(); i++){
    int shift = (int)s[i] - 'a';
    if((count & 1<<shift) == 0){
      str += s[i];
      count |= 1<<shift;
    }
  }
  return str;
}

string removeDuplicate2(string s){
  if(s.length() < 2)
    return s;
  bool check[256];
  string str = "";
  memset(check,0,sizeof(check));
  for(int i = 0; i<s.length(); i++){
    if(!check[(int)s[i]]){
      str += s[i];
      check[(int)s[i]] = true;
    }
  }
  return str;
}

string removeDuplicate3(string s){
  if(s.length() < 2)
    return s;
  string str = "";
  for(int i=0; i<s.length(); i++){
    if(s[i]!='\0'){
      str += s[i];
      for(int j=i+1; j<s.length(); j++){
        if(s[i]==s[j])
          s[j]='\0';
      }
    }
  }
  return str;
}
 
int main()
{
  string p = "vivek raghuvanshi";
  cout << p << endl;
  cout << removeDuplicate3(p);
  return 0;
}