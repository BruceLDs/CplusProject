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
	m.insert(pair<string, string>("peach", "����"));
	m.insert(make_pair("banan", "�㽶"));
	m["apple"] = "ƻ��";
	cout << m.size() << endl;
	for (auto& p : m)
		cout << p.first << " ---> " << p.second << endl;
	auto ret = m.insert(make_pair("peach", "��ɫ"));
	if (ret.second)
		cout << "<peach, ��ɫ>����map��, �Ѿ�����" << endl;
	else
		cout << "��ֵΪpeach��Ԫ���Ѿ����ڣ�" << ret.first->first << "--->" << ret.first->second << " ����ʧ��" << endl;
	m.erase("apple");
	if (1 == m.count("apple"))
		cout << "apple����" << endl;
	else
		cout << "apple������" << endl;
}
int main(){
	//test();
	//test1();
	TestMap();
	return 0;
}