#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<set>
using namespace std;
void test(){
	set<int> s;
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(4);
	s.insert(3);
	set<int>::iterator it = s.begin();
	while (it != s.end()){
		cout << *it << endl;
		it++;
	}
	cout << "--------------------------------------------------------" << endl;
	cout << s.count(3) << endl;
	it = s.find(3);
	cout << *it << endl;
}
void test1(){
	multiset<int> s;
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(4);
	s.insert(3);
	set<int>::iterator it = s.begin();
	while (it != s.end()){
		cout << *it << endl;
		it++;
	}
	cout << "--------------------------------------------------------" << endl;
	cout << s.count(3) << endl;
	it = s.find(3);
	cout << *it << endl;
}
void  test3(){
	unordered_map<int, char> mp;
	mp.insert(make_pair(1, 'a'));
	mp.insert(make_pair(2, 'b'));
	mp.insert(make_pair(3, 'c'));
	mp.insert(make_pair(2, 'd'));
	mp.insert(make_pair(5, 'b'));
	for (auto& p : mp)
		cout << p.first << " ---> " << p.second << endl;
	
}
void test4(){
	unordered_set<int>s;
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(4);
	s.insert(5);
	unordered_set<int>::iterator it = s.begin();
	while (it != s.end()){
		cout << *it << endl;
		it++;
	}
}
int main(){
	//test();
	//cout << "--------------------------------------------------------" << endl;
	//test1();
	test3();
	test4();
	return 0;
}
