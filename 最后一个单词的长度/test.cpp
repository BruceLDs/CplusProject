#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
//c语言解法
int lengthOfLastWord1(char * s){
	if (!s || s == "")
		return 0;
	int len = strlen(s);
	int i, j;
	for (i = len - 1; i >= 0 && s[i] == ' '; i--);
	for (j = i; j >= 0 && s[j] != ' '; j--);
	return i - j;
}

//c++解法
int lengthOfLastWord(string s) {
	int res = 0;
	if (s.size() == 0)
		return 0;
	for (int i = s.size() - 1; i >= 0; i--)
	{
		if (s[i] != ' ')
			res++;
		else
		{
			if (res)
				break;
		}
	}
	return res;
}
int main(){
	string s = "Hello World";
	int ret = lengthOfLastWord(s);
	cout << ret << endl;
	return 0;
}