#define  _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
using namespace std;

int main(){
	string s;
	while (cin >> s){
		int arr[256] = { 0 };
		int i = 0;
		string ret;
		while (i < s.size()){
			if (arr[s[i]] == 0){
				ret += s[i];
				arr[s[i]] = 1;
			}
			i++;
		}
		cout << ret << endl;
	}
	return 0;
}