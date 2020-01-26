#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

//为解决溢出问题
int myAtoi(string str) {
	if (str.size() == 0)
		return 0;
	int i = 0;
	while (i < str.size())
	{
		if (str[i] != ' ')
			break;
		i++;
	}
	if ((str[i] > '9' || str[i] < '0') && str[i] != '-' && str[i] != '+')
		return 0;
	string s;
	if (str[i] == '-' || str[i] == '+'){
		s += str[i];
		i++;
	}	
	while (i < str.size()){
		if (str[i] >= '0' && str[i] <= '9')
			s += str[i];
		i++;
	}
	int k = 0;
	i = s.size() - 1;
	int key = 1;
	while (i >= 0){
		int res = s[i] - '0';
		if (s[i] == '-'){
			k *= (-1);
			break;
		}
		else if (s[i]== '+'){
			break;
		}
		k += res * key;
		key *= 10;
		i--;
	}
	if (k > INT_MAX)
		return INT_MAX;
	else if (k < INT_MIN)
		return INT_MIN;
	return k;
}


int main(){
	string str = "-42";
	int ret = myAtoi(str);
	cout << ret << endl;
	return 0;
}