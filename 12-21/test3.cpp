#include <thread>
#include <vector>
#include <iostream>
#include <memory>
#include <mutex>
using namespace std;
void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left >= right) return;
	int mid = left + ((right - left) >> 1);
	// [left, mid]
	// [mid+1, right]
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
			tmp[index++] = a[begin1++];
		else
			tmp[index++] = a[begin2++];
	}
	while (begin1 <= end1)
		tmp[index++] = a[begin1++];
	while (begin2 <= end2)
		tmp[index++] = a[begin2++];
	memcpy(a + left, tmp + left, sizeof(int)*(right - left + 1));
}

//template <class T>
//class SmartPtr{
//public:
//	SmartPtr(T* ptr)
//		: _ptr(ptr)
//	{
//	}
//	~SmartPtr()
//	{
//		if (_ptr){
//			free(_ptr);
//			cout << "free(): " << endl;
//			_ptr = nullptr;
//		}
//	}
//private:
//	T* _ptr;
//};
//
//void MergeSort(int* a, int n)
//{
//	int* tmp = (int*)malloc(sizeof(int)*n);
//	//智能指针
//	SmartPtr<int> sp(tmp);
//	_MergeSort(a, 0, n - 1, tmp);
//	// 这里假设处理了一些其他逻辑
//	vector<int> v(1000000000, 10);
//	/*free(tmp);
//	cout << "free(tmp)" << endl;*/
//	
//}
//int main()
//{
//	try{
//		int a[5] = { 4, 5, 2, 3, 1 };
//		MergeSort(a, 5);
//	}
//	catch (exception& e){
//		cout << e.what() << endl;
//	}
//	catch (...){
//		cout << "未知异常" << endl;
//	}
//	return 0;
//}

//智能指针： 1. 实现RAII   2. 实现指针的操作
template <class T>
class SmartPtr{
public:
	SmartPtr(T* ptr)
		: _ptr(ptr)
	{
	}
	~SmartPtr()
	{
		if (_ptr){
			delete _ptr;
			cout << "delete" << endl;
			_ptr = nullptr;
		}
	}

	//实现指针的功能: 解引用
	T& operator*(){
		return *_ptr;
	}
	T* operator->(){
		return _ptr;
	}

private:
	T* _ptr;
};

class A
{
public:
	int _a = 1;
	int _b = 2;
	int _c = 3;

	~A(){
		cout << "~A()" << endl;
	}
};

template <class T>
class AutoPtr{
public:
	AutoPtr(T* ptr)
		: _ptr(ptr)
	{
	}
	~AutoPtr()
	{
		if (_ptr){
			delete _ptr;
			cout << "delete" << endl;
			_ptr = nullptr;
		}
	}

	//管理权转移
	AutoPtr(AutoPtr<T>& ap)
		:_ptr(ap._ptr)
	{
		ap._ptr = nullptr;
	}

	AutoPtr<T>& operator=(AutoPtr<T>& ap){
		if (this != &ap){
			if (_ptr)
				delete _ptr;
			//管理权转移
			_ptr = ap._ptr;
			ap._ptr = nullptr;
		}
		
		return *this;
	}


	//实现指针的功能: 解引用
	T& operator*(){
		return *_ptr;
	}
	T* operator->(){
		return _ptr;
	}

private:
	T* _ptr;
};

//int main(){
//	//int* pi = new int(2);
//	//cout << *pi << endl;
//	//*pi = 3;
//	//cout << *pi << endl;
//
//	////智能指针
//	//cout << "smartPtr:" << endl;
//	//SmartPtr<int> sp(new int(10));
//	//cout << *sp << endl;
//	//*sp = 20;
//	//cout << *sp << endl;
//
//	//delete pi;
//
//	/*A* pa = new A();
//	pa->_a = 10;
//	pa->_b = 20;
//
//	SmartPtr<A> sp2(new A());
//	(*sp2)._a = 10;
//	sp2.operator->()->_b = 100;
//	cout << sp2->_a << endl;
//	cout << sp2->_b << endl;*/
//
//	/*SmartPtr<A> sp3(new A());
//	sp3->_a = 20;
//	cout << sp3->_a << endl;
//	SmartPtr<A> copy(sp3);
//
//	copy->_a = 100;
//	SmartPtr<A> copy2(copy);
//	copy2->_b = 1;*/
//
//	auto_ptr<A> sp3(new A());
//	sp3->_a = 20;
//	cout << sp3->_a << endl;
//	auto_ptr<A> copy(sp3);
//	//指针悬空
//	//sp3->_a = 1;
//
//	copy->_a = 100;
//	auto_ptr<A> copy2(copy);
//	//指针悬空
//	//copy->_a = 1;
//	copy2->_b = 1;
//
//	AutoPtr<A> sp4(new A());
//	sp4->_a = 10;
//	AutoPtr<A> copy3(sp4);
//	copy3->_a = 100;
//	AutoPtr<A> copy4(copy3);
//	copy4->_b = 1;
//	return 0;
//}

//template <class T>
//class UniquePtr{
//public:
//	UniquePtr(T* ptr)
//		: _ptr(ptr)
//	{
//	}
//	~UniquePtr()
//	{
//		if (_ptr){
//			delete _ptr;
//			cout << "delete" << endl;
//			_ptr = nullptr;
//		}
//	}
//
//	
//	//实现指针的功能: 解引用
//	T& operator*(){
//		return *_ptr;
//	}
//	T* operator->(){
//		return _ptr;
//	}
//
//private:
//
//	//防拷贝: 声明为delete函数
//	UniquePtr(UniquePtr<T>& ap) = delete;
//	UniquePtr<T>& operator=(UniquePtr<T>& ap) = delete;
//
//	//防拷贝：只声明不实现
//	/*UniquePtr(UniquePtr<T>& ap);
//	UniquePtr<T>& operator=(UniquePtr<T>& ap);*/
//
//	T* _ptr;
//};
//
//int main(){
//	unique_ptr<A> up(new A());
//	up->_a = 10;
//	unique_ptr<A> up2(new A());
//	//防拷贝
//	/*unique_ptr<A> copy(up);
//	up2 = up;*/
//
//	UniquePtr<A> up3(new A());
//	/*UniquePtr<A> copy(up3);
//	UniquePtr<A> up4(new A());
//	up4 = up3;*/
//	return 0;
//
//
//}

//int main(){
//	shared_ptr<A> sp(new A()); 
//	cout << sp.use_count() << endl;  // 1
//	shared_ptr<A> copy(sp);
//	cout << copy.use_count() << endl;  // 2
//	shared_ptr<A> sp2(new A());
//	cout << sp2.use_count() << endl; // 1
//
//	sp2 = sp;
//	cout << sp2.use_count() << endl;  // 3
//	return 0;
//}

//template <class T>
//class SharedPtr{
//public:
//	SharedPtr(T* ptr)
//		:_ptr(ptr)
//		, _pcount(new int(1))
//	{}
//
//	SharedPtr(SharedPtr<T>& sp)
//		:_ptr(sp._ptr)
//		, _pcount(sp._pcount)
//	{
//		++(*_pcount);
//	}
//
//	SharedPtr<T>& operator=(SharedPtr<T>& sp){
//		//if (this != sp){
//		if (_ptr != sp._ptr){
//			if (--(*_pcount) == 0){
//				delete _pcount;
//				delete _ptr;
//			}
//
//			_ptr = sp._ptr;
//			_pcount = sp._pcount;
//			++(*_pcount);
//		}
//		return *this;
//	}
//
//	~SharedPtr()
//	{
//		if (--(*_pcount) == 0){
//			if (_ptr){
//				delete _ptr;
//				delete _pcount;
//				cout << "delete _ptr" << endl;
//			}
//		}
//		
//	}
//	T& operator*(){
//		return *_ptr;
//	}
//
//	T* operator->(){
//		return _ptr;
//	}
//
//	int useCount(){
//		return *_pcount;
//	}
//private:
//	T* _ptr;
//	int* _pcount;
//};

template <class T, class Deletor>
class SharedPtr{
public:
	SharedPtr(T* ptr, Deletor deletor)
		:_ptr(ptr)
		, _pcount(new int(1))
		, _mtx(new mutex())
		, _delete(deletor)
	{}

	SharedPtr(SharedPtr<T>& sp)
		:_ptr(sp._ptr)
		, _pcount(sp._pcount)
		, _mtx(sp._mtx)
	{
		addRef();
	}

	SharedPtr<T>& operator=(SharedPtr<T>& sp){
		//if (this != sp){
		if (_ptr != sp._ptr){
			if (subRef() == 0){
				delete _pcount;
				delete _ptr;
			}

			_ptr = sp._ptr;
			_pcount = sp._pcount;
			addRef();
			
		}
		return *this;
	}

	~SharedPtr()
	{
		
		if (subRef() == 0){
			if (_ptr){
				/*delete _ptr;
				delete _pcount;
				cout << "delete _ptr" << endl;*/
				//定制删除器
				_delete(_ptr);
			}
		}

	}
	T& operator*(){
		return *_ptr;
	}

	T* operator->(){
		return _ptr;
	}

	int useCount(){
		return *_pcount;
	}

	int addRef(){
		_mtx->lock();
		++(*_pcount);
		_mtx->unlock();
		return *_pcount;
	}

	int subRef(){
		_mtx->lock();
		--(*_pcount);
		_mtx->unlock();
		return *_pcount;
	}
private:
	T* _ptr;
	int* _pcount;
	mutex* _mtx;
	Deletor _delete;
};

//int main(){
//	SharedPtr<int> sp(new int(1));
//	SharedPtr<int> sp2(new int(2));
//	cout << sp.useCount() << endl;  // 1
//	cout << sp2.useCount() << endl;  // 1
//	SharedPtr<int> copy(sp);
//	cout << sp.useCount() << endl;  // 2
//	cout << copy.useCount() << endl;  // 2
//	sp2 = sp;
//	cout << sp.useCount() << endl; // 3
//	cout << sp2.useCount() << endl; // 3
//	copy = sp;
//
//	return 0;
//}
//mutex mtx;
//void fun(SharedPtr<int>& sp, int n){
//	for (int i = 1; i <= n; ++i){
//		mtx.lock();
//		++(*sp);
//		mtx.unlock();
//		SharedPtr<int> copy(sp);
//	}
//}
//
//
//void fun2(shared_ptr<int> sp, int n){
//	for (int i = 0; i < n; ++i){
//		++(*sp);
//		shared_ptr<int> copy(sp);
//	}
//}
//
//void test1(){
//	int n = 10000;
//	SharedPtr<int> sp(new int(0));
//	thread t1(fun, sp, n);
//	thread t2(fun, sp, n);
//	t1.join();
//	t2.join();
//	cout << *sp << endl;  // 0
//	cout << sp.useCount() << endl;  // 1
//}
//
//void test2(){
//	int n = 10000;
//	shared_ptr<int> sp(new int(0));
//	thread t1(fun2, sp, n);
//	thread t2(fun2, sp, n);
//	t1.join();
//	t2.join();
//	cout << *sp << endl;  // 0
//	cout << sp.use_count() << endl;  // 1
//}
//
//int main(){
//	test1();
//	//test2();
//	return 0;
//}

//template <class T>
//class ListNode{
//public:
//	weak_ptr<ListNode<T>> _next;
//	weak_ptr<ListNode<T>> _prev;
//	~ListNode()
//	{
//		cout << "~ListNode()" << endl;
//	}
//};
//
//void test3(){
//	shared_ptr<ListNode<int>> sp(new ListNode<int>());
//	shared_ptr<ListNode<int>> sp2(new ListNode<int>());
//	cout << sp.use_count() << endl;  // 1
//	cout << sp2.use_count() << endl; // 1
//	sp->_next = sp2;
//	sp2->_prev = sp;
//	cout << sp.use_count() << endl;  // 2
//	cout << sp2.use_count() << endl; // 2
//
//}
//
//int main(){
//	test3();
//	return 0;
//}
class B
{
public:
	~B()
	{
		cout << "~B()" << endl;
	}
};

template <class T>
class DeleteArray{
public:
	void operator()(T* ptr){
		delete[] ptr;
	}
};

template <class T>
class FreeDelete{
public:
	void operator()(T* ptr){
		free(ptr);
	}
};
void test4(){
	shared_ptr<int> sp(new int[10], DeleteArray<int>());
	shared_ptr<int> sp2((int*)malloc(100), FreeDelete<int>());
	shared_ptr<B> sp3(new B[10], DeleteArray<B>());
	shared_ptr<B> sp4((B*)malloc(100), FreeDelete<B>());
}

int main(){
	test4();
	return 0;
}