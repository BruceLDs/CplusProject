#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//ֻ���ڶ��ϴ����������
// 1. ����˽�л�
// 2. �ṩһ�����е�static�ӿڴ�������
// 3. ������

class HeapOnly
{
public:
	static HeapOnly* getHeapOnly()
	{
		//HeapOnly* pa = new HeapOnly;
		//// copy : ջ��
		//HeapOnly copy(*pa);
		return new HeapOnly;
	}

private:
	HeapOnly()
	{
		cout << "HeapOnly()" << endl;
	}
	//�������� ֻ������ʵ��
	//HeapOnly(const HeapOnly& h);
	//��������C++11 ɾ������������
	HeapOnly(const HeapOnly& h) = delete;
};

//A ga;

//int main()
//{
//	//A a;
//	HeapOnly* pa = HeapOnly::getHeapOnly();
//	// copy : ջ��
//	//HeapOnly copy(*pa);
//	return 0;
//}

/*
ֻ����ջ�ϴ����������
: 1. ���캯��˽�л�
2. �ṩһ�����е�static�ӿڴ�������
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
ֻ����ջ�ϴ����������
�� 1. ֻ������ʵ�� operator new����
*/

class StackOnly2
{
private:
	/*void* operator new(size_t size);*/
	// C++11�� delete����
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
������ �����ڵ�һ��ʹ��֮ǰ�Ѿ�����
1. ���캯��˽�л�
2. �ṩһ��static���нӿڷ��ض���
3. ����һ��static�����Ա
4. ������:��������ֻ������ʵ��

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
//	//������
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
�����������һ��ʹ�õ�ʱ�򴴽�
1. ���캯��˽��
2. ������
3. �ṩ���е�static�ӿڣ��ӿڵ�һ�ε���ʱ��������
4. ����һ��static��ָ��
5���̰߳�ȫ��˫���
*/

class Singleton
{
public:

	static Singleton* getInstance()
	{
		//˫���
		//�ⲿ��飺���Ч��
		if (_pInstance == nullptr)
		{
			_mtx.lock();
			//�ڲ���飺��֤�̰߳�ȫ
			if (_pInstance == nullptr)
			{

				cout << "create obj" << endl;
				_pInstance = new Singleton;

			}
			_mtx.unlock();
		}
		return _pInstance;
	}
	//�����ݹ����
	//~Singleton()
	//{
	//	if (_pInstance)
	//	{
	//		delete _pInstance; // delete������+�ͷ�
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
	//������
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