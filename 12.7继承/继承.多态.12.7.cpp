#include <iostream>
#include <string>
using namespace std;
//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//	int num = 10;
//protected:
//	string _name = "peter"; // 姓名
//	int _age = 18; // 年龄
//	int _stuid = 0; // 学号
//private:
//	int _i;
//};
//
//class Student : public Person
//{
//public:
//	void setId(int _stuid)
//	{
//		_stuid = _stuid;
//	}
//	void Print()
//	{
//		Person::Print();  //调用父类同名函数
//		cout << num << endl;
//		cout << Person::num << endl;
//		cout << "Student print()" << endl;
//		cout << _stuid << endl;  //3
//		cout << Person::_stuid << endl;  //父类
//	}
//protected:
//	int _stuid = 3; // 学号
//};
//
//class Teacher : public Person
////class Teacher : protected Person
////class Teacher : private Person
//{
//public:
//	void printPrivate()
//	{
//		//cout << _i << endl;
//	}
//	void PrintProtected()
//	{
//		cout << _name << _age << endl;
//	}
//	int num = 20;
//protected:
//	int _jobid; // 工号
//};
//
//class Professer : public Teacher
//{
//public:
//	void print()
//	{
//		cout << _jobid << endl;
//		cout << _name << _age << endl;
//	}
//};
////int main()
////{
////	//Student s;
////	Teacher t;
////	//s.Print();
////	//t.Print();
////	return 0;
////}
//
//void test()
//{
//	Student s;
//	//公有继承，is-a
//	//切片
//	//赋值
//	Person p = s;
//	Person& rs = s;
//	Person* ps = &s;
//
//	Person pobj;
//	//不支持非类对象到子类对象的强制转换
//	//s = (Student) pobj;
//
//	
//	Student* pp = (Student*) &pobj;
//	Student* ppp = (Student*)ps;
//}
//
//void test2()
//{
//	Person p;
//	cout << sizeof(Person) << endl;
//	cout << sizeof(Student) << endl;
//	Student s;
//	s.setId(10);
//	s.Print();
//	s.Person::Print();
//	s.num; //子类的成员
//	s.Person::num; //父类成员
//}
//
//int main()
//{
//	//test();
//	test2();
//
//	return 0;
//}

//class Person
//{
//public:
//	Person(int age = 18)
//		:_age(age)
//	{
//		cout << "Person()" << endl;
//	}
//
//	Person(const Person& p)
//	{
//		cout << "Person(const Person&)" << endl;
//	}
//
//	Person& operator=(const Person& p)
//	{
//		cout << "Person& operator=(const Person&)" << endl;
//		return *this;
//	}
//
//	~Person() //底层： destructor
//	{
//		cout << "~Person()" << endl;
//	}
//protected:
//	int _age;
//};
//
//class Student : public Person
//{
//public:
//	Student(int age = 18, int id = 2019)
//		:_id(id)
//		, Person(age)
//		//, _age(age)
//	{
//		cout << "Student(int age, int id)" << endl;
//	}
//
//	Student(const Student& s)
//		:Person(s)
//		,_id(s._id)
//	{
//		cout << "Student(const Student&)" << endl;
//	}
//
//	Student& operator=(const Student& s)
//	{
//		Person::operator=(s);
//		cout << "Student& operator=(const Student&)" << endl;
//		return *this;
//	}
//
//	~Student()  //底层： destructor, 父类析构和子类析构构成一个同名隐藏
//	{
//		//Person::~Person();  一定不要显式调用父类析构
//		cout << "~Student()" << endl;
//	}
//
//protected:
//	int _id;
//};
//
//void testStudent()
//{
//	Student s; //自动调用子类构造， 子类构造自动调用父类默认构造
//	/*cout << "拷贝构造：" << endl;
//	Student copy(s);
//	cout << "operator=" << endl;
//	s = copy;*/
//
//}

//int main()
//{
//	testStudent();
//	return 0;
//}

//class NoH final
//{
//public:
//	NoH()
//	{
//		cout << "NoH" << endl;
//	}
//};
//
//class Drive : public NoH
//{};
//
//void test()
//{
//	Drive d;
//
//}
//
//
//int main()
//{
//	test();
//	return 0;
//}

//class B;
//class A
//{
//	friend class B;
//private:
//	int _a;
//};
//
//class C : public A
//{
//private:
//	int _c;
//};
//
//class B
//{
//public:
//	void printA(A& a)
//	{
//		cout << a._a << endl;
//		C c;
//		//cout << c._c << endl;
//	}
//};

//class A
//{
//public:
//	int getA()
//	{
//		return _a;
//	}
//	void addA()
//	{
//		++_a;
//		
//	}
////private:
//	static int _a;
//};
//
//int A::_a = 0;
//
//class B : public A
//{
//};
//
//class C : public B
//{
//};
//
//void test()
//{
//	A a;
//	B b;
//	C c;
//	a.addA();
//	cout << a.getA() << endl;
//	b.addA();
//	cout << b.getA() << endl;
//	c.addA();
//	cout << c.getA() << endl;
//}
//int main()
//{
//	test();
//	return 0;
//}

//class Person
//{
//protected:
//	int _id = 0;
//};
//
//class Teacher : virtual public Person
//{
//protected:
//	int _jobid = 1;
//};
//
//class Student : virtual public Person
//{
//protected:
//	int _stuid = 2;
//};
//
//class Assitant : public Student, public Teacher
//{
//public:
//	int getId()
//	{
//		//return Student::_id;
//		//return Teacher::_id;
//		return _id;
//	}
//protected:
//	int _aid = 3;
//};
//
//void test()
//{
//	Assitant ass;
//	cout << ass.getId() << endl;
//}
//
//int main()
//{
//	test();
//	return 0;
//}

//class A
//{
//public:
//	int _a;
//};
//
//class B : virtual public A
//{
//public:
//	A a;
//	int _b;
//};
//
//class C : virtual public A
//{
//public:
//	int _c;
//};
//
//class D : public B, public C
//{
//public:
//	int _d;
//};
//
//void test()
//{
//	D d;
//	d.B::_a = 1;
//	d._b = 2;
//	d.C::_a = 3;
//	d._c = 4;
//	d._d = 5;
//}
//
//int main()
//{
//	test();
//	return 0;
//}

//class A
//{};
//class B :public A
//{};
//
//class Person
//{
//public:
//	//协变，返回值类型构成父子关系的指针或者引用
//	//virtual: 虚函数
//	virtual A& buy()
//	{
//		cout << "全价票" << endl;
//		return A();
//	}
//};
//
//class Student : public Person
//{
//public:
//	virtual B& buy()
//	{
//		cout << "student半价票" << endl;
//		return B();
//	}
//};
//
//class Teacher : public Person
//{
//public:
//	virtual B& buy()
//	{
//		cout << "teacher全价票" << endl;
//		return B();
//	}
//};



class Person
{
public:
	//协变，返回值类型构成父子关系的指针或者引用
	//virtual: 虚函数
	virtual void buy()
	{
		cout << "全价票" << endl;
		
	}
	virtual ~Person()
	{
		cout << "~Person()" << endl;
	}
};

class Student : public Person
{
public:
	void buy()
	{
		cout << "student半价票" << endl;	
	}

	~Student()
	{
		cout << "~Student()" << endl;
	}
};

class Teacher : public Person
{
public:
	void buy()
	{
		cout << "teacher全价票" << endl;
		
	}
	~Teacher()
	{
		cout << "~Teacher()" << endl;
	}
};

void Fun(Person& p)
{
	p.buy();
}

void test()
{
	Student s;
	//非多态：值拷贝
	Person ps = s;
	//ps.buy();
	//多态：引用执行虚函数
	Person& rs = s;
	//rs.buy();
	Person* pss = &s;
	//多态：指针执行虚函数
	//pss->buy();
	Teacher t;
	//多态：引用执行虚函数
	Person& rt = t;
	//rt.buy();
	Fun(ps);
	Fun(s);
	Fun(t);

}

void TestVirtual()
{
	Person* ps = new Student;
	Person* pt = new Teacher;

	delete ps;
	delete pt;

}

int main()
{
	//test();
	TestVirtual();
	return 0;
}
