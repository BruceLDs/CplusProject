#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stack>
using namespace std;
class Solution
{
public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		while (!stack1.empty()){
			stack2.push(stack1.top());
			stack1.pop();
		}
		int temp = stack2.top();
		stack2.pop();
		while (!stack2.empty()){
			stack1.push(stack2.top());
			stack2.pop();
		}
		return temp;
	}
private:
	stack<int> stack1;
	stack<int> stack2;
};

int main(){
	Solution s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	return 0;
}