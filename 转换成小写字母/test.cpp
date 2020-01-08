#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	string toLowerCase(string str) {
		string s = str;
		string::iterator it = s.begin();
		while (it != s.end()){
			if (*it >= 'A' && *it <= 'Z')
				*it += 32;
			it++;
		}
		str = s;
		return str;
	}
};

int main(){
	Solution s;
	string s1 = "AbchhdHHK";
	cout << s1 << endl;
	cout << s.toLowerCase(s1) << endl;
	return 0;
}