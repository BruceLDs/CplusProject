#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
int lengthOfLastWord(string s) {
	int res = 0;

	if (s.length() == 0)
		return 0;

	for (int i = s.length() - 1; i >= 0; i--)
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