//#define  _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//using namespace std;
//int hissoda(int n){
//	int ret = 0;
//	int count = 0;
//	//空瓶为1瓶时
//	if (n == 1)
//		return 0;
//	//空瓶大于1瓶时
//	while (n > 1){
//		int temp = 0;
//		temp = n / 3;
//		count += temp;
//		n = n % 3;
//		n += temp;
//		if (n == 2)
//		{
//			count++;
//			break;
//		}
//	}
//	return count;
//}
//int main(){
//	int i = 0;
//	while (i < 10){
//		int k = 0;
//		cin >> k;
//		int ret = hissoda(k);
//		cout << ret << endl;
//		i++;
//	}
//
//	return 0;
//}
#include<iostream>
#include<vector>
using namespace std;
int hissoda(int n){
	int ret = 0;
	int count = 0;
	//空瓶为1瓶时
	if (n == 1)
		return 0;
	//空瓶大于1瓶时
	while (n > 1){
		int temp = 0;
		temp = n / 3;
		count += temp;
		n = n % 3;
		n += temp;
		if (n == 2)
		{
			count++;
			break;
		}
	}
	return count;
}
int main(){
	vector<int> arr1, arr2;
	arr1.resize(10);
	arr2.resize(10);
	int i = 0;
	while (i < 10){
		cin >> arr1[i];
		if (arr1[i] == 0)
			break;
		arr2[i] = hissoda(arr1[i]);
		i++;
	}
	for (int j = 0; j < i; j++)
		cout << arr2[j] << endl;
	return 0;
}