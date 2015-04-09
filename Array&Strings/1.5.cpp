#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
using namespace std;

// string compressString1(string in){
// 	std::string out = "";
// 	int len = in.length();
// 	for(int i=0; i<len; i++){
// 		int count = 1;
// 		out += in[i];
// 		for(int j=i+1; j<len; j++){
// 			if(in[i] == in[j])
// 				count++;
// 			else
// 				break;
// 		}
// 		ostringstream s;
// 		out += std::to_string(count);
// 		i = i + (count-1);
// 	}
// 	return out;
// }

int checkLength(string str){

	return 0;
}

// string compressString3(string str){
// 	int size = checkLength(str);
// 	int len = str.length();
// 	// if(size >= str.length())
// 	// 	return str;
// 	//std::stringstream ss;
// 	std::string res;
// 	int count = 1;
// 	char last = str[0];
// 	for(int i=1; i<len; i++){
// 		if(last == str[i])
// 			count++;
// 		else{
// 			//ss << last << count;
// 			res += last + to_string(count);
// 			count = 1;
// 			last = str[i];
// 		}
// 	}
// 	// ss << last << count;
// 	//std::string str1 = ss.str();
// 	res += last + to_string(count);
// 	return res;
// }

// time comlexity O(N) and space complexity O(N)

string compressString3(string str){
	int size = checkLength(str);
	int len = str.length();
// 	// if(size >= str.length())
// 	// 	return str;
 	std::stringstream ss;
// 	//std::string res;
	int count = 1;
	char last = str[0];
	for(int i=1; i<len; i++){
		if(last == str[i])
			count++;
		else{
			ss << last << count;
			//res += last + to_string(count);
			count = 1;
			last = str[i];
		}
	}
	ss << last << count;
	std::string res = ss.str();
	//res += last + to_string(count);
	return res;
}

int main(){
	string in = "abcfffffmmaaa";
	cout << in << endl;
    cout << compressString3(in);
	return 0;
}

