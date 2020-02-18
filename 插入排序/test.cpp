#include<iostream>
using namespace std;
//稳定性：稳定
//时间复杂度：O(n ^ 2)
//空间复杂度：O(1)
//适合场景：接近有序的序列，时间复杂度接近于O(n)
void test(int* a, int sz){
	//只有一个元素，相当于有序
	if (sz < 2)
		return;
	//进行插入排序
	for (int i = 1; i < sz; i++){
		int pos = i - 1;//指向前一个位置
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
		//end为有序元素的下一个坐标
		int end = i + 1;
		//记录当前值
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