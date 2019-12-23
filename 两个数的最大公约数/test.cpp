#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int MaxComNum(int a, int b){
	int temp;
	//temp总是小于等于两数中最小的那个
	temp = (a > b) ? b : a;
	while (temp > 0)
	{
		if (a%temp == 0 && b%temp == 0)
			break;  //一旦找到满足条件的temp就跳出循环  
		temp--;
	}
	return (temp);
}
int main(){
	cout << MaxComNum(15, 10) << endl;
	return 0;
}