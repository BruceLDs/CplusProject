#define  _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
using namespace std;

bool isPalindrome(int x) {
	if (x < 0)
		return false;
	string s;
	while (x){
		s += x % 10;
		x /= 10;
	}
	int left = 0;
	int right = s.size() - 1;
	while (left < right){
		if (s[left] == s[right]){
			left++;
			right--;
		}
		else
			return false;
	}

	return true;
}

int main(){
	int k = 10;
	bool ret = isPalindrome(k);
	cout << ret << endl;
	return 0;
}
