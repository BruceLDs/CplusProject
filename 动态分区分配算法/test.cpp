#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
/*
共512k, 申请300K，申请100K，释放300K，申请150K，申请30K，申请40K，申请60K，释放30K。
*/
void FreeSpace(vector<int> a){

}
void FF(vector<int> a, int* arr, int n){//首次适应算法
	for (int i = 0; i < n; i++){
		if (arr[i] > 0){
			cout << "申请" << arr[i] << "k空间" << endl;
			int count = 0;
			for (int j = 0; j < a.size(); j++){
				if (a[j] == 0){
					count++;
					if (count == arr[i]){
						
					}

				}
				else{

				}
			}
		}
		else{
			cout << "释放" << -arr[i] << "k空间" << endl;

		}
	}
}
void NF(vector<int> a, int* arr, int n){//循环首次适应算法

}
void BF(vector<int> a, int* arr, int n){//最佳适应算法

}
void WF(vector<int> a, int* arr, int n){//最坏适应算法

}
void test(){
	int k = 0;
	while (k > 0 && k < 5){
		cout << "**********************************" << endl;
		cout << "*******1.首次适应算法      *********" << endl;
		cout << "*******2.循环首次适应算法********" << endl;
		cout << "*******3.最佳适应算法      *********" << endl;
		cout << "*******4.最坏适应算法      *********" << endl; 
		cout << "**********************************" << endl;
		vector<int> a;
		a.resize(512, 0);//0表示空闲区， 1表示已分配区
		int arr[] = { 300, 100, -300, 150, 30, 40, 60 - 30 };
		cin >> k;
		switch (k){
		case 1:FF(a, arr, sizeof(arr) / sizeof(arr[0])); 
			FreeSpace(a);break;
		case 2:NF(a, arr, sizeof(arr) / sizeof(arr[0])); 
			FreeSpace(a); break;
		case 3:BF(a, arr, sizeof(arr) / sizeof(arr[0])); 
			FreeSpace(a); break;
		case 4:WF(a, arr, sizeof(arr) / sizeof(arr[0])); 
			FreeSpace(a); break;
		default:cout << "退出系统！" << endl; break;
		}
	}
	system("pause");
}
int main(){
	test();
	return 0;
}
