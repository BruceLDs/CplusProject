#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<map>
using namespace std;

void test(){
	map<int, char> mp;
	mp.insert(make_pair(1, 'a'));
	mp.insert(make_pair(2, 'b'));
	mp.insert(make_pair(3, 'b'));
	mp.insert(make_pair(4, 'd'));
	mp.insert(make_pair(1, 'e'));
	for (auto& p : mp)
		cout << p.first << " ---> " << p.second << endl;	
	cout << "-------------------------------------------------------------" << endl;
	//mp.erase(2);
	map<int, char>::iterator it = mp.begin();
	it++;
	mp.erase(it);
	for (auto& p : mp)
		cout << p.first << " ---> " << p.second << endl;
	cout << "-------------------------------------------------------------" << endl;
}
void test1(){
	multimap<int, char> mp;
	mp.insert(make_pair(1, 'a'));
	mp.insert(make_pair(2, 'b'));
	mp.insert(make_pair(3, 'b'));
	mp.insert(make_pair(4, 'd'));
	mp.insert(make_pair(1, 'e'));
	for (auto& p : mp)
		cout << p.first << " ---> " << p.second << endl;
}

void TestMap()
{
	map<string, string> m;
	m.insert(pair<string, string>("peach", "桃子"));
	m.insert(make_pair("banan", "香蕉"));
	m["apple"] = "苹果";
	cout << m.size() << endl;
	for (auto& p : m)
		cout << p.first << " ---> " << p.second << endl;
	auto ret = m.insert(make_pair("peach", "桃色"));
	if (ret.second)
		cout << "<peach, 桃色>不在map中, 已经插入" << endl;
	else
		cout << "键值为peach的元素已经存在：" << ret.first->first << "--->" << ret.first->second << " 插入失败" << endl;
	m.erase("apple");
	if (1 == m.count("apple"))
		cout << "apple还在" << endl;
	else
		cout << "apple被吃了" << endl;
}
int main(){
	//test();
	//test1();
	TestMap();
	return 0;
}