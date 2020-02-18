#include<iostream>
using namespace std;
//稳定性：稳定
//时间复杂度：O(n ^ 2)
//空间复杂度：O(1)
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
int main(){
	int a[] = { 5, 2, 4, 6, 1, 3 };
	test(a, 6);
	for (auto& e : a)
		cout << e << "  ";
	cout << endl;
	return 0;
}