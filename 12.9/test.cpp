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
// ֻ��������Student������������д��Person�����������������delete��������������������ܹ���
//��̬�����ܱ�֤p1��p2ָ��Ķ�����ȷ�ĵ�������������
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
		cout << "Benz-����" << endl; 
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