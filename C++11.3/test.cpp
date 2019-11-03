#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//只能在堆上创建对象的类
// 1. 构造私有化
// 2. 提供一个公有的static接口创建对象
// 3. 防拷贝

class HeapOnly
{
public:
	static HeapOnly* getHeapOnly()
	{
		//HeapOnly* pa = new HeapOnly;
		//// copy : 栈上
		//HeapOnly copy(*pa);
		return new HeapOnly;
	}

private:
	HeapOnly()
	{
		cout << "HeapOnly()" << endl;
	}
	//防拷贝： 只声明不实现
	//HeapOnly(const HeapOnly& h);
	//防拷贝：C++11 删除函数的声明
	HeapOnly(const HeapOnly& h) = delete;
};

//A ga;

//int main()
//{
//	//A a;
//	HeapOnly* pa = HeapOnly::getHeapOnly();
//	// copy : 栈上
//	//HeapOnly copy(*pa);
//	return 0;
//}

/*
只能在栈上创建对象的类
: 1. 构造函数私有化
2. 提供一个公有的static接口创建对象
*/

class StackOnly
{
public:
	static StackOnly getStackOnly()
	{
		return StackOnly();
	}
private:
	StackOnly()
	{
		cout << "StackOnly()" << endl;
	}
};

/*
只能在栈上创建对象的类
： 1. 只声明不实现 operator new函数
*/

class StackOnly2
{
private:
	/*void* operator new(size_t size);*/
	// C++11： delete函数
	void* operator new(size_t size) = delete;
};

//StackOnly2 gs;
//int main()
//{
//	//StackOnly* ps = new StackOnly;
//	////StackOnly s;
//	//StackOnly s = StackOnly::getStackOnly();
//	StackOnly2 s;
//	StackOnly2* ps = new StackOnly2;
//	return 0;
//}

/*
饿汉： 对象在第一次使用之前已经存在
1. 构造函数私有化
2. 提供一个static公有接口返回对象
3. 定义一个static自身成员
4. 防拷贝:拷贝构造只声明不实现

*/

//class Singleton
//{
//public:
//	static Singleton* getInstance()
//	{
//		return &_instance;
//	}
//private:
//	Singleton()
//	{
//		cout << "Singleton()" << endl;
//	}
//
//	//防拷贝
//	Singleton(const Singleton& s);
//
//	static Singleton _instance;
//	
//};
//Singleton Singleton::_instance;

//int main()
//{
//	Singleton* ps = Singleton::getInstance();
//	Singleton* ps1 = Singleton::getInstance();
//	Singleton* ps2 = Singleton::getInstance();
//	Singleton* ps3 = Singleton::getInstance();
//	/*Singleton copy(*ps2);
//	Singleton s;*/
//	return 0;
//}


#include <thread>
#include <mutex>
/*
懒汉：对象第一次使用的时候创建
1. 构造函数私有
2. 防拷贝
3. 提供公有的static接口，接口第一次调用时创建对象
4. 定义一个static的指针
5：线程安全：双检查
*/

class Singleton
{
public:

	static Singleton* getInstance()
	{
		//双检查
		//外部检查：提高效率
		if (_pInstance == nullptr)
		{
			_mtx.lock();
			//内部检查：保证线程安全
			if (_pInstance == nullptr)
			{

				cout << "create obj" << endl;
				_pInstance = new Singleton;

			}
			_mtx.unlock();
		}
		return _pInstance;
	}
	//析构递归调用
	//~Singleton()
	//{
	//	if (_pInstance)
	//	{
	//		delete _pInstance; // delete：析构+释放
	//		_pInstance = nullptr;
	//	}
	//}
	class Garba{
	public:
		~Garba()
		{
			if (_pInstance)
			{
				delete _pInstance;
				_pInstance = nullptr;
			}
		}
	};

private:
	Singleton()
	{
		cout << "Singleton()" << endl;
	}
	//防拷贝
	Singleton(const Singleton* s);



	static Singleton* _pInstance;
	static mutex _mtx;
	static Garba _gc;
};

Singleton* Singleton::_pInstance = nullptr;
mutex Singleton::_mtx;
Singleton::Garba Singleton::_gc;





void fun(int n)
{
	for (int i = 0; i < n; ++i)
	{
		Singleton* ps = Singleton::getInstance();
	}
}



//int main()
//{
//	/*Singleton* ps = Singleton::getInstance();
//	Singleton* ps1 = Singleton::getInstance();
//	Singleton* ps2 = Singleton::getInstance();
//	Singleton* ps3 = Singleton::getInstance();*/
//
//	int n;
//	cin >> n;
//	thread t1(fun, n);
//	thread t2(fun, n);
//	thread t3(fun, n);
//	thread t4(fun, n);
//
//	t1.join();
//	t2.join();
//	t3.join();
//	t4.join();
//	/*fun(n);
//	fun(n);*/
//	return 0;
//}

int main()
{
	/*char* pc = new char[0xffffffff];
	cout << (int*)pc << endl;*/
	return 0;
}