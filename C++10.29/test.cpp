//#include<iostream>
//using namespace std;
/*
//�ڶ��ϴ�������
class HeapOnly
{
public:
	//��̬��Ա��ͨ������ֱ�ӵ���
	static HeapOnly* CreateObject()
	{
		return new HeapOnly;
	}
private:
	// 1.ֻ����,��ʵ�֡���Ϊʵ�ֿ��ܻ���鷳�����㱾����Ҫ
	// 2.������˽��
	HeapOnly() {
		cout << "HeapOnly( )" << endl;
	}
	//��������ֻ��������ʵ��
	HeapOnly(const HeapOnly& h);
	//or
	//HeapOnly(const HeapOnly& h) = delete;
};
*/
/*
//��ջ�ϴ������󣬽�new�Ĺ������ε�
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
// ����ģʽ
// �ŵ㣺��
// ȱ�㣺���ܻᵼ�½�����������������ж�����������ʵ������˳��ȷ����
class Singleton
{
public:
	static Singleton* GetInstance()
	{
		return &m_instance;
	}
private:
	// ���캯��˽��
	Singleton(){
		cout << "Singleton()" << endl;
	};
	// C++98 ������
	Singleton(Singleton const& i);
	//Singleton& operator=(Singleton const& i);
	// or
	// C++11
	//Singleton(Singleton const& i) = delete;
	//Singleton& operator=(Singleton const& i) = delete;
	static Singleton m_instance;//����ʹ�þ�̬��Ա����Ϊ��̬��Ա������
};
Singleton Singleton::m_instance; // �ڳ������֮ǰ����ɵ�������ĳ�ʼ��
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
// ����
// �ŵ㣺��һ��ʹ��ʵ������ʱ���������󡣽��������޸��ء��������ʵ������˳�����ɿ��ơ�
// ȱ�㣺����
#include <iostream>
#include <mutex>
#include <thread>
using namespace std;
class Singleton
{
public:
	static Singleton* GetInstance() {
		// ע������һ��Ҫʹ��Double-Check�ķ�ʽ���������ܱ�֤Ч�ʺ��̰߳�ȫ
		if (nullptr == m_pInstance)//���Ч��
		{
				m_mtx.lock();//����
			if (nullptr == m_pInstance)//��֤�̰߳�ȫ
			{
				m_pInstance = new Singleton();
			}
			m_mtx.unlock();//����
		}
		return m_pInstance;
	}
	// ʵ��һ����Ƕ����������,delete = ���� + �ͷ�
	//������ҪǶ��һ���ڲ���
	class CGarbo {
	public:
		~CGarbo(){
			if (Singleton::m_pInstance)
				delete Singleton::m_pInstance;
		}
	};
	// ����һ����̬��Ա�������������ʱ��
	//ϵͳ���Զ������������������Ӷ��ͷŵ�������
	static CGarbo Garbo;
private:
	// ���캯��˽��
	Singleton(){
		cout << "Singleton( )" << endl;
	};
	// ������
	Singleton(Singleton const& s);
	//Singleton& operator=(Singleton const& s);
	static Singleton* m_pInstance; // ��������ָ��
	static mutex m_mtx; //������
};

Singleton* Singleton::m_pInstance = nullptr;//��ʼ��������������
Singleton::CGarbo Garbo;
mutex Singleton::m_mtx;

void func(int n) {
	cout << Singleton::GetInstance() << endl;
}
// ���̻߳�������ʾ����GetInstance()�����Ͳ�����������
int main()
{
	//���̻߳���
	thread t1(func, 10);
	thread t2(func, 10);
	t1.join();
	t2.join();
}

*/
