#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<list>
#include<stack>
using namespace std;
//O(n^2)算法
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
	vector<int> printListFromTailToHead1(list<int> head) {
		stack<int> st;
		vector<int> a;
		list<int>::iterator it = head.begin();
		while (it != head.end()){
			st.push(*it);
			it++; 
		}
		while (!st.empty()){
			a.push_back(st.top());
			st.pop();
		}
		return a;
	}
	void test(){
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
		//	vector<int> a = printListFromTailToHead(head);
			vector<int> a = printListFromTailToHead1(head);
			cout << "打印返回的逆置数组： " << endl;
			for (auto& e : a)
				cout << e << " -> ";
			cout << endl;
	}
int main(){
	test();
	return 0;
}