#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<list>
using namespace std;
	vector<int> printListFromTailToHead(list<int> head) {
		vector<int> arr;
		list<int>::iterator cur = head.begin();
		while (cur != head.end()){
			arr.push_back(*cur);
			cur++;
		}
		reverse(arr.begin(), arr.end());
		return arr;
	}

int main(){
	list<int> head;
	head.push_back(1);
	head.push_back(2);
	head.push_back(3);
	head.push_back(4);
	head.push_back(5);
	head.push_back(6);
	head.push_back(7);
	head.push_back(8);
	head.push_back(9);
	cout << "打印head ：" << endl;
	for (auto& e : head)
		cout << e << " -> ";
	cout << endl;
	vector<int> a = printListFromTailToHead(head);
	cout << "打印返回的逆置数组： " << endl;
	for (auto& e : a)
		cout << e << " -> ";
	cout << endl;
	return 0;
}