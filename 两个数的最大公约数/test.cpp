#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int MaxComNum(int a, int b){
	int temp;
	//temp����С�ڵ�����������С���Ǹ�
	temp = (a > b) ? b : a;
	while (temp > 0)
	{
		if (a%temp == 0 && b%temp == 0)
			break;  //һ���ҵ�����������temp������ѭ��  
		temp--;
	}
	return (temp);
}
int main(){
	cout << MaxComNum(15, 10) << endl;
	return 0;
}