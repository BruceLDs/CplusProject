#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);
	int arr[256] = { 0 };
	for (int i = 0; i < str2.size(); i++){
		arr[str2[i]]++;
	}
	string ret;
	for (int j = 0; j < str1.size(); j++){
		if (arr[str1[j]] == 0)
			ret += str1[j];
	}
	cout << ret << endl;
	return 0;
}