
#include <queue>
#include <iostream>
#include <functional>
#include <vector>
#include <deque>
#include <list>
using namespace std;

void testPriorityQueue()
{
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(3);
	pq.push(10);
	pq.push(1);
	pq.push(100);
	pq.push(-1);
	while (!pq.empty())
	{
		cout << pq.top() << endl;
		pq.pop();
	}
}

//int main()
//{
//	testPriorityQueue();
//	return 0;
//}

template <class T, class Container>
class Stack
{
public:
	void push(const T& val)
	{
		_con.push_back(val);
	}

	void pop()
	{
		_con.pop_back();
	}

	T& top()
	{
		return _con.back();
	}

	bool empty()
	{
		return _con.empty();
	}

	size_t size()
	{
		return _con.size();
	}
private:
	Container _con;
};

template <class T, class Container>
class Queue
{
public:
	void push(const T& val)
	{
		_con.push_back(val);
	}
	void pop()
	{
		_con.pop_front();
	}
	T& front()
	{
		return _con.front();
	}
	T& back()
	{
		return _con.back();
	}
	bool empty()
	{
		return _con.empty();
	}
	size_t size()
	{
		return _con.size();
	}

private:
	Container _con;
};

void testStack()
{
	Stack<int, list<int>> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	while (!st.empty())
	{
		cout << st.top() << endl;
		st.pop();
	}
}

void testqueue()
{
	queue<int, deque<int>> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	while (!q.empty())
	{
		cout << q.front() << endl;
		q.pop();
	}
}

void testQueue()
{
	Queue<int, list<int>> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	while (!q.empty())
	{
		cout << q.front() << endl;
		q.pop();
	}
}

/*
	//push()  ---> push_back, 向上调整
	//pop()  ---> pop_back  向下调整
	//top() ---> front
	满足：随机访问
*/
void testpriorityqueue()
{
	priority_queue<int, vector<int>> pq;
	priority_queue < int, deque<int>> pq2;
	//priority_queue<int, list<int>> pq3;

	pq.push(1);
	pq2.push(2);
	//pq3.push(3);
		
}

struct Date
{
	Date(int year = 2000)
	:_year(year)
	{}

	bool operator>(const Date& date) const
	{
		return _year > date._year;
	}

	bool operator<(const Date& date) const
	{
		return _year < date._year;
	}
	int _year = 2000;
	int _month = 1;
	int _day = 1;
};

//仿函数类：重载"()"运算符的一个类
template <class T>
struct Greater
{
	bool operator()(const T& a, const T& b) 
	{
		return a > b;
	}
};

template <class T>
struct Less
{
	bool operator()(const T& a, const T& b)
	{
		return a < b;
	}
};


//默认实现大堆
//仿函数：自定义优先级，不需要修改代码，增加代码的灵活性
template <class T, class Container = vector<T>, class Compare = Greater<T>>
class PriorityQueue
{
public:
	void push(const T& val)
	{
		_con.push_back(val);
		//向上调整
		shiftUp(_con.size() - 1);
	}

	void shiftUp(size_t child)
	{
		size_t parent = (child - 1) >> 1;
		while (child > 0)
		{
			//if (_con[child] > _con[parent])
			if (_com(_con[child], _con[parent]))
			{
				swap(_con[child], _con[parent]);
				child = parent;
				parent = (child - 1) >> 1;
			}
			else
				break;
		}
	}
	void pop()
	{
		swap(_con[0], _con[_con.size() - 1]);
		_con.pop_back();
		//向下调整
		shiftDown(0);
	}
	void shiftDown(size_t parent)
	{
		size_t child = 2 * parent + 1;
		while (child < _con.size())
		{
			/*if (child + 1 < _con.size()
				&& _con[child + 1] > _con[child])*/
			if (child + 1 < _con.size()
				&& _com(_con[child + 1], _con[child]))
				++child;
			//if (_con[child] > _con[parent])
			if (_com(_con[child], _con[parent]))
			{
				swap(_con[child], _con[parent]);
				parent = child;
				child = 2 * parent + 1;
			}
			else
				break;
		}
	}
	T& top()
	{
		return _con.front();
	}
	size_t size()
	{
		return _con.size();
	}
	bool empty()
	{
		return _con.empty();
	}
private:
	Container _con;
	Compare _com;
};



void testPriorityQueue2()
{
	PriorityQueue<int> pq;
	pq.push(1998);
	pq.push(2001);
	pq.push(2019);
	pq.push(2008);
	while (!pq.empty())
	{
		int ret = pq.top();
		cout << pq.top() << endl;
		pq.pop();
	}
}

void testFun()
{
	Greater<int> g;
	int a = 1;
	int b = 2;
	bool ret = g.operator()(a, b);
	ret = g(a, b);
}

void testFun2()
{
	priority_queue<int, vector<int>, Greater<int>> pq;
	pq.push(1);
	pq.push(2);
	pq.push(3);
	pq.push(4);
	while (!pq.empty())
	{
		int ret = pq.top();
		cout << pq.top() << endl;
		pq.pop();
	}
}

void testPriorityQueue3()
{
	PriorityQueue<Date, vector<Date>, Less<Date>> pq;
	pq.push(1998);
	pq.push(2001);
	pq.push(2019);
	pq.push(2008);
	while (!pq.empty())
	{
		Date ret = pq.top();
		cout << pq.top()._year << endl;
		pq.pop();
	}
}
//int main()
//{
//	//testStack();
//	//testqueue();
//	//testQueue();
//	//testpriorityqueue();
//	//testPriorityQueue2();
//	//testFun();
//	//testFun2();
//	testPriorityQueue3();
//	return 0;
//}
//#include "add.h"
//int main()
//{
//	int a = 1, b = 2;
//	int ret = add(a, b);
//	return 0;
//}