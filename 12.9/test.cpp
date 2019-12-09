#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
/*
class Person {
public:
	virtual ~Person() { cout << "~Person()" << endl; }
};
class Student : public Person {
public:
		virtual ~Student() { cout << "~Student()" << endl; }
};
// 只有派生类Student的析构函数重写了Person的析构函数，下面的delete对象调用析构函数，才能构成
//多态，才能保证p1和p2指向的对象正确的调用析构函数。
int main()
{
	Person* p1 = new Person;
	Person* p2 = new Student;
	delete p1;
	delete p2;
	system("pause");
	return 0;
}
*/
class Car
{
public:
	virtual void Drive(){
		cout << "Car" << endl;
	}
};
class Benz :public Car
{
public:
	virtual void Drive() override{ 
		cout << "Benz-舒适" << endl; 
	}
};
void test(){
	Car* pc = new Benz;
	pc->Drive();
	system("pause");
}
int main(){
	test();
	return 0;
}