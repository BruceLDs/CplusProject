#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
typedef void(*vfptr) ();
class Base
{
public:
	virtual void Func1()
	{
		cout << "Base::Func1()" << endl;
	}
	virtual void Func2()
	{
			cout << "Base::Func2()" << endl;
	}
	void Func3()
	{
		cout << "Base::Func3()" << endl;
	}
private:
	int _b = 1;
};
class Base1
{
public:
	virtual void Func1()
	{
		cout << "Base::Func1()" << endl;
	}
	virtual void Func2()
	{
		cout << "Base::Func2()" << endl;
	}
private:
	int _b = 1;
};
class Derive : public Base
{
public:
	virtual void Func1()
	{
		cout << "Derive::Func1()" << endl;
	}
	virtual void Func2()
	{
		cout << "Base::Func2()" << endl;
	}
private:
	int _d = 2;
};
class Derive1 : public Base1
{
public:
	virtual void Func1()
	{
		cout << "Derive::Func1()" << endl;
	}
	virtual void Func2()
	{
		cout << "Base::Func2()" << endl;
	}
private:
	int _d = 2;
};
void print(vfptr* Vftable){
	cout << Vftable << endl ;
}
int main()
{
	Base b;
	cout << "Base虚表" << endl;
	print((vfptr*)(*(int*)(&b)));
	Base1 b1;
	cout << "Base1虚表" << endl;
	print((vfptr*)(*(int*)(&b1)));
	Derive d;
	cout << "Derive虚表" << endl;
	print((vfptr*)(*(int*)(&d)));
	Derive1 d1;
	cout << "Derive1虚表" << endl;
	print((vfptr*)(*(int*)(&d1)));
	return 0;
}
