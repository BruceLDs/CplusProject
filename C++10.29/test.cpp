//#include<iostream>
//using namespace std;
/*
//在堆上创建对象
class HeapOnly
{
public:
	//静态成员可通过类名直接调用
	static HeapOnly* CreateObject()
	{
		return new HeapOnly;
	}
private:
	// 1.只声明,不实现。因为实现可能会很麻烦，而你本身不需要
	// 2.声明成私有
	HeapOnly() {
		cout << "HeapOnly( )" << endl;
	}
	//防拷贝，只声明，不实现
	HeapOnly(const HeapOnly& h);
	//or
	//HeapOnly(const HeapOnly& h) = delete;
};
*/
/*
//在栈上创建对象，将new的功能屏蔽掉
class StackOnly
{
public:
	static StackOnly CreateObject()
	{
		return StackOnly();
	}
private:
	StackOnly() {
		cout << "StackOnly()" << endl;
	}
};
*/
/*
class StackOnly2
{
public:
	StackOnly2() {}
private:
	void* operator new(size_t size);
	//void operator delete(void* p);
};
*/
/*
// 饿汉模式
// 优点：简单
// 缺点：可能会导致进程启动慢，且如果有多个单例类对象实例启动顺序不确定。
class Singleton
{
public:
	static Singleton* GetInstance()
	{
		return &m_instance;
	}
private:
	// 构造函数私有
	Singleton(){
		cout << "Singleton()" << endl;
	};
	// C++98 防拷贝
	Singleton(Singleton const& i);
	//Singleton& operator=(Singleton const& i);
	// or
	// C++11
	//Singleton(Singleton const& i) = delete;
	//Singleton& operator=(Singleton const& i) = delete;
	static Singleton m_instance;//必须使用静态成员，因为静态成员属于类
};
Singleton Singleton::m_instance; // 在程序入口之前就完成单例对象的初始化
int main(){
//HeapOnly* H = HeapOnly::CreateObject();
//StackOnly s = StackOnly::CreateObject();
//StackOnly2 p ;
/*Singleton* p = Singleton::GetInstance();
Singleton* p1 = Singleton::GetInstance();
return 0;
}
*/

/*
// 懒汉
// 优点：第一次使用实例对象时，创建对象。进程启动无负载。多个单例实例启动顺序自由控制。
// 缺点：复杂
#include <iostream>
#include <mutex>
#include <thread>
using namespace std;
class Singleton
{
public:
	static Singleton* GetInstance() {
		// 注意这里一定要使用Double-Check的方式加锁，才能保证效率和线程安全
		if (nullptr == m_pInstance)//提高效率
		{
				m_mtx.lock();//加锁
			if (nullptr == m_pInstance)//保证线程安全
			{
				m_pInstance = new Singleton();
			}
			m_mtx.unlock();//解锁
		}
		return m_pInstance;
	}
	// 实现一个内嵌垃圾回收类,delete = 析构 + 释放
	//所以需要嵌入一个内部类
	class CGarbo {
	public:
		~CGarbo(){
			if (Singleton::m_pInstance)
				delete Singleton::m_pInstance;
		}
	};
	// 定义一个静态成员变量，程序结束时，
	//系统会自动调用它的析构函数从而释放单例对象
	static CGarbo Garbo;
private:
	// 构造函数私有
	Singleton(){
		cout << "Singleton( )" << endl;
	};
	// 防拷贝
	Singleton(Singleton const& s);
	//Singleton& operator=(Singleton const& s);
	static Singleton* m_pInstance; // 单例对象指针
	static mutex m_mtx; //互斥锁
};

Singleton* Singleton::m_pInstance = nullptr;//初始化，不创建对象
Singleton::CGarbo Garbo;
mutex Singleton::m_mtx;

void func(int n) {
	cout << Singleton::GetInstance() << endl;
}
// 多线程环境下演示上面GetInstance()加锁和不加锁的区别。
int main()
{
	//多线程环境
	thread t1(func, 10);
	thread t2(func, 10);
	t1.join();
	t2.join();
}

*/
