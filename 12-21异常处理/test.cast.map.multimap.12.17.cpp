#include <mutex>
#include <thread>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
mutex mtx;

//template <class Mtx>
//struct lockGuard{
//	lockGuard(Mtx& mtx)
//	:_mtx(mtx)
//	{
//		_mtx.lock();
//	}
//
//	~lockGuard()
//	{
//		cout << "~LockGuard()" << endl;
//		_mtx.unlock();
//	}
//
//	//������
//	lockGuard(const lockGuard<Mtx>& lg) = delete;
//
//private:
//	Mtx& _mtx;
//};
//
//void fun(){
//	int i;
//	cin >> i;
//	//mtx.lock();
//	lockGuard<mutex> lg(mtx);
//	if (i == 9)
//		return;
//	cout << i << endl;
//	//mtx.unlock();
//}

//int main(){
//	thread t1(fun);
//	thread t2(fun);
//	t1.join();
//	t2.join();
//	return 0;
//}

//void testCast(){
//	//��ʽ����ת��
//	int i = 10;
//	char c = i;
//
//	//ǿ������ת��
//	int* pi = &i;
//	int i2 = (int) pi;
//}
//
//class A{
//public:
//	virtual void fun(){
//		cout << "A: fun()" << endl;
//	}
//};
//
//class B : public A{
//public:
//	virtual void fun(){
//		cout << "B: fun()" << endl;
//	}
//};
//
//class C{
//
//};
//
//class D : public C{
//
//};
//
//void testCast2(){
//	int i = 10;
//	// ��̬ת���� ֧���κ���ʽ����ת��, ��֧��ǿ������ת��
//	char c = static_cast<char> (i);
//
//	// ǿ��ת����reinterpret_cast 
//	int* pi = &i;
//	int i2 = reinterpret_cast<int> (pi);
//	//int i3 = static_cast<int> (pi);
//
//	// const_cast: ȥ��������const����
//	const int ci = 20;
//	const int* pci = &ci;
//	int* pci2 = const_cast<int*> (&ci);
//	*pci2 = 30;
//	cout << ci << endl;  
//	cout << *pci2 << endl;
//	cout << *pci << endl;
//	cout << "address:" << endl;
//	cout << pci2 << endl;
//	cout << pci << endl;
//	cout << &ci << endl;
//
//	// dynamic_cast:  ֻ�������̬������ ����ָ��/���� --> ����ָ��/����
//	// 1. ����ת���� ��ת����ָ��/���ñ���ָ���Ϊ�������
//	// 2. ������ת���� nullptr  ��ת����ָ��/���ñ���ָ���Ϊ�������
//	B b;
//	A a = b;
//	A& rb = b;
//	A* pb = &b;
//
//	A aobj;
//	B* pa = (B*)&aobj;
//	B* pa2 = reinterpret_cast<B*> (&aobj);
//	B* pa3 = dynamic_cast<B*> (&aobj);
//	//static_cast: û�����Ͱ�ȫ���
//	B* pa4 = static_cast<B*> (&aobj);
//
//	B* pb1 = dynamic_cast<B*> (pb);  // pb: ָ���������ĸ���ָ��
//
//	
//
//}
//
//class E{
//public:
//	//explicit: ��ֹ���ι��캯������ʽ����ת��
//	explicit E(int a)
//		:_a(a)
//	{
//		cout << "E(int a)" << endl;
//	}
//	E(int a, int b)
//		:_a(a)
//	{}
//	int _a;
//};
//
//int main(){
//	//testCast2();
//	E e = 10;
//	
//	return 0;
//}

void testPair(){
	pair<int, int>  p;
	vector<pair<string, string>> vec;
	vec.push_back(pair<string, string>("����", "xi'an"));
	vec.push_back(pair<string, string>("�й�", "China"));

	for (const auto& e : vec){
		cout << e.first << "--->" << e.second << endl;
	}

}

void testMap(){
	//�޲ι���
	map<int, int>  mp;
	vector<pair<int, int>> vec;
	int n = 10;
	for (int i = 0; i < n; ++i){
		vec.push_back(make_pair(i, i));
	}
	//���������죺 ������������֮�������Ϊpair����
	map<int, int, greater<int>> mp2(vec.begin(), vec.end());
	map<int, int> mp3(mp2.begin(), mp2.end());
	//��������
	map<int, int> copy(mp3);

	for (const auto& p : mp2){
		cout << p.first << "--->" << p.second << endl;
	}
	cout << "rbegin()::" << endl;
	auto it = mp2.rbegin();
	while (it != mp2.rend()){
		cout << it->first << "--->" << it->second << endl;
		++it;
	}

	

}

void testMap2(){
	map<string, int> mp;

	mp.insert(make_pair("ab", 100));
	mp.insert(make_pair("abz", 10));
	mp.insert(pair<string, int>("abc", 1));
	mp.insert(make_pair("abb", 20));
	mp.insert(make_pair("abb", 200000));
	cout << ":" << endl;
	for (const auto& p : mp){
		cout << p.first << "---->" << p.second << endl;
	}

	/*cout <<"ab--->: "<< mp["ab"] << endl;
	cout << "abb--->: " << mp["abb"] << endl;*/
	//�޸�
	mp["ab"] = 5;
	cout << ":" << endl;

	for (const auto& p : mp){
		cout << p.first << "---->" << p.second << endl;
	}
	//����
	mp["abcd"] = 19;
	cout << ":" << endl;

	for (const auto& p : mp){
		cout << p.first << "---->" << p.second << endl;
	}

	mp.at("ab") = 50;
	//key: e �����ڣ����쳣
	//mp.at("e") = 40;
	// key: e �����ڣ� ����
	mp["e"] = 40;
}

void testMap3(){
	map<string, int> mp;

	mp.insert(make_pair("ab", 100));
	mp.insert(make_pair("abz", 10));
	mp.insert(pair<string, int>("abc", 1));
	mp.insert(make_pair("abb", 20));
	cout << ":" << endl;
	for (const auto& p : mp){
		cout << p.first << "---->" << p.second << endl;
	}
	cout << ":" << endl;
	mp.insert(mp.begin(), make_pair("ccc", 1));
	for (const auto& p : mp){
		cout << p.first << "---->" << p.second << endl;
	}

	map<string, int> mp2;

	mp2.insert(make_pair("ab", 100));
	mp2.insert(make_pair("abzd", 10));
	mp.insert(mp2.begin(), mp2.end());
	cout << ":" << endl;
	for (const auto& p : mp){
		cout << p.first << "---->" << p.second << endl;
	}
	
	mp.erase(mp.begin());
	cout << "erase: begin():" << endl;
	for (const auto& p : mp){
		cout << p.first << "---->" << p.second << endl;
	}

	mp.erase("abzd");
	cout << "erase abzd:" << endl;
	for (const auto& p : mp){
		cout << p.first << "---->" << p.second << endl;
	}

	mp.erase(mp.begin(), mp.end());
	cout << "erase begin -- end:" << endl;
	for (const auto& p : mp){
		cout << p.first << "---->" << p.second << endl;
	}
}

void testMap4(){
	map<string, int> mp;

	mp.insert(make_pair("ab", 100));
	mp.insert(make_pair("abz", 10));
	mp.insert(pair<string, int>("abc", 1));
	mp.insert(make_pair("abb", 20));
	cout << ":" << endl;
	for (const auto& p : mp){
		cout << p.first << "---->" << p.second << endl;
	}

	/*auto it = mp.find("a");
	if (it != mp.end()){
	cout << "a find" << endl;
	}
	else{
	cout << "a not find" << endl;
	}

	it = mp.find("abb");

	cout << it->first << "---->" << it->second << endl;*/
	cout << mp.count("abb") << endl;
	cout << mp.count("a") << endl;
	
}

void testMap5(){
	//multimap  VS map :
	// 1. mutilmap �е�key�����ظ��� map��key�����ظ�
	// 2. map��[]������ multimapû��[]����
	// 3. �����ӿ�ʹ�÷�������ͬ
	multimap<string, int> mp;
	mp.insert(make_pair("z", 1));
	mp.insert(make_pair("a", 1));
	mp.insert(make_pair("a", 10));
	mp.insert(make_pair("a", 100));
	mp.insert(make_pair("d", 1));
	mp.insert(make_pair("c", 1));
	for (const auto& p : mp){
		cout << p.first << "---->" << p.second << endl;
	}

	
}

void testSet(){
	set<int> s;   // pair<int, int>
	s.insert(10);
	s.insert(10);
	s.insert(10);
	s.insert(10);
	for (const auto& v : s){
		cout << v << endl;
	}
}
int main(){
	//testPair();
	//testMap();
	//testMap2();
	//testMap3();
	//testMap4();
	//testMap5();
	testSet();
	return 0;
}