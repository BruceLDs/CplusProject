#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
vector<int> plusOne(vector<int>& digits) {
	if (digits[digits.size() - 1] < 9){
		digits[digits.size() - 1] += 1;
		return digits;
	}
	int i = digits.size() - 1;
	while (i >= 0){
		if (digits[i] == 9){
			digits[i] = 0;
		}
		else{
			digits[i] += 1;
			break;
		}
		i--;
	}
	if (0 > i){
		vector<int>::iterator it = digits.begin();
		digits.insert(it, 1);
	}
	return digits;
}

int main(){
	vector<int> digits = { 1, 9, 9, 8, 9 };
	for (auto& e : digits)
		cout << e;
	cout << endl;
	vector<int> ret = plusOne(digits);
	for (auto& e : ret)
		cout << e;
	cout << endl;
	return 0;
}