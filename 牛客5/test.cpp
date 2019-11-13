#include<iostream>
using namespace std;
int Fib(int n){
	if (n == 1)
		return 0;
	if (n == 2)
		return 1;
	return Fib(n - 1) + Fib(n - 2);
}
int main(){
	int N;
	cin >> N;
	int i = 1;
	int k1 = 0;
	int k2 = 0;
	int temp1 = 0;
	int temp2 = 0;
	while (1){
		 temp1 = Fib(i);
		if (temp1== N){
			cout << 0 << endl;
			break;
		}
		if (temp1 > N && temp2 < N){
			k1 = temp1;
			k2 = temp2;
			break;
		}
		temp2 = temp1;
		i++;
	}
	if ( k1 - N > N - k2)
		cout << N - k2 << endl;
	else
		cout << k1 - N << endl;
	return 0;
}
//ÓÐÐ§À¨ºÅ´®
/*
bool chkParenthesis(string A, int n) {
string s;
int i = 0;
while(i < A.size()){
if(A[i] != '(' && A[i] != ')')
return false;
else if(A[i] == '(')
s.push_back(A[i]);
else if(A[i] == ')')
{
if(s[s.size() - 1] == '(')
s.pop_back();
else
return false;
}
i++;
}
if(s.size() == 0)
return true;
return false;
}
*/