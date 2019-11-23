#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Parenthesis {
public: 
	bool chkParenthesis(string A, int n) { 
			stack<char> sc;
			for (auto ele : A) 
			{ 
				switch (ele){ 
				case '(': sc.push(ele); break; case ')': 
			{ 
			if (sc.empty() || sc.top() != '(') 
			return false;
			else 
				sc.pop(); 
				}
					break; 
default: return false; 
				} 
			}
		return true;
	} 
};


int main(){
	Parenthesis s;
	bool ret = s.chkParenthesis("(()()())", 8);
	cout << ret << endl;
	return 0;
}