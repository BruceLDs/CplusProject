#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
string reverseOnlyLetters(string S) {
	if (S.size() == 0)
		return S;
	string s;
	s.resize(S.size());
	int i = 0;

	while (i < S.size()){
		if ((S[i] >= 'a' && S[i] <= 'z') || (S[i] >= 'A' && S[i] <= 'Z'))
			s += S[i];
		i++;
	}
	i = 0;
	int right = s.size() - 1;
	string s1 = S;
	while (i < S.size()){
		if ((S[i] >= 'a' && S[i] <= 'z') || (S[i] >= 'A' && S[i] <= 'Z')){
			s1[i] = s[right];
			right--;
		}
		else
			s[i] = S[i];
		i++;
	}
	return s1;
}

int main(){
	string s = "ab-cd";
	string ret = reverseOnlyLetters(s);
	cout << ret << endl;
	return 0;
}