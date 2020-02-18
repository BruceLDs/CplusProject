#include<iostream>
using namespace std;
//�ȶ��ԣ��ȶ�
//ʱ�临�Ӷȣ�O(n ^ 2)
//�ռ临�Ӷȣ�O(1)
//�ʺϳ������ӽ���������У�ʱ�临�ӶȽӽ���O(n)
void test(int* a, int sz){
	//ֻ��һ��Ԫ�أ��൱������
	if (sz < 2)
		return;
	//���в�������
	for (int i = 1; i < sz; i++){
		int pos = i - 1;//ָ��ǰһ��λ��
		while(a[i] < a[pos]){
			pos--;
		}
		pos++;
		int temp = a[i];
		int j = i;
		while (j >= pos){
			a[j] = a[j - 1];
			j--;
		}
		a[pos] = temp;
	}
}
void InsertSort(int* a, int sz){
	for (int i = 0; i < sz - 1; i++){
		//endΪ����Ԫ�ص���һ������
		int end = i + 1;
		//��¼��ǰֵ
		int tmp = a[end];
		while (end > 0 && a[end - 1] > tmp)
		{
			a[end] = a[end - 1];
			--end;
		}
		a[end] = tmp;
	}
}
int main(){
	int a[] = { 5, 2, 4, 6, 1, 3 };
	//test(a, 6);
	InsertSort(a, 6);
	for (auto& e : a)
		cout << e << "  ";
	cout << endl;
	return 0;
}