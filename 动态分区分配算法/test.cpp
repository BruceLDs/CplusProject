#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
/*
��512k, ����300K������100K���ͷ�300K������150K������30K������40K������60K���ͷ�30K��
*/
void FreeSpace(vector<int> a){

}
void FF(vector<int> a, int* arr, int n){//�״���Ӧ�㷨
	for (int i = 0; i < n; i++){
		if (arr[i] > 0){
			cout << "����" << arr[i] << "k�ռ�" << endl;
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
			cout << "�ͷ�" << -arr[i] << "k�ռ�" << endl;

		}
	}
}
void NF(vector<int> a, int* arr, int n){//ѭ���״���Ӧ�㷨

}
void BF(vector<int> a, int* arr, int n){//�����Ӧ�㷨

}
void WF(vector<int> a, int* arr, int n){//���Ӧ�㷨

}
void test(){
	int k = 0;
	while (k > 0 && k < 5){
		cout << "**********************************" << endl;
		cout << "*******1.�״���Ӧ�㷨      *********" << endl;
		cout << "*******2.ѭ���״���Ӧ�㷨********" << endl;
		cout << "*******3.�����Ӧ�㷨      *********" << endl;
		cout << "*******4.���Ӧ�㷨      *********" << endl; 
		cout << "**********************************" << endl;
		vector<int> a;
		a.resize(512, 0);//0��ʾ�������� 1��ʾ�ѷ�����
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
		default:cout << "�˳�ϵͳ��" << endl; break;
		}
	}
	system("pause");
}
int main(){
	test();
	return 0;
}
