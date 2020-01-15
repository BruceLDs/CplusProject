#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

bool canConstruct(string ransomNote, string magazine) {
	int cnt[26] = { 0 };
	for (int i = 0; i < magazine.length(); i++)
		cnt[magazine[i] - 'a']++;
	for (int i = 0; i < ransomNote.length(); i++)
	if (--cnt[ransomNote[i] - 'a'] < 0) 
		return false;
	return true;
}

int main(){
	string ransomNote = "aa";
	string magazine = "aab";
	bool ret = canConstruct(ransomNote, magazine);
	cout << ret << endl;
	return 0;
}