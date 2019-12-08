#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class TestBase{
public:
	TestBase(int i)
	:m_a(i)
	{
	}
	int m_a;
};
class Test :public TestBase{
public:
	Test(int a, int b) :
		TestBase(a),
	    m_a(b)
	{
	}
	int m_a;
};
void test(){
	Test t(5, 6);
	cout << t.m_a << endl;
	t.m_a = 4;
	cout << t.m_a << endl;


}
int main(){
	test();
	system("pause");
	return 0;
}