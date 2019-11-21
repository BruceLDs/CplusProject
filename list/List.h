#include<iostream>
using namespace std;

template <class T>
struct ListNode
{
	T _val;
	ListNode<T>* _next;
	ListNode<T>* _prev;
	ListNode(const T& val = T())
		: _prev(nullptr)
		, _next(nullptr)
		, _val(val)
	{}
};
template <class T, class Ref, class Ptr>
struct ListIterator
{
	typedef ListNode<T> Node;
	typedef ListNode<T>* pNode;
	typedef ListIterator<T, Ref, Ptr> Self;
	pNode _node;
	
	ListIterator(pNode node)
		:_node(node)
	{}
	//�����ã� �ɶ���д
	Ref operator*()
	{
		return _node->_data;
	}
	// ptr->_year; �ɶ���д
	Ptr operator->()
	{
		return &operator*();
		//return &_node->_data;
	}

	//������ǰ��++
	Self& operator++()
	{
		_node = _node->_next;
		return *this;
	}

	Self operator++(int)
	{
		Self tmp(*this);
		_node = _node->_next;
		return tmp;
	}

	Self& operator--()
	{
		_node = _node->_prev;
		return *this;
	}

	Self operator--(int)
	{
		Self tmp(*this);
		_node = _node->_prev;
		return tmp;
	}

	//!= 
	bool operator!=(const Self& it)
	{
		return _node != it._node;
	}

	bool operator==(const Self& it)
	{
		return _node == it._node;
		//return !*this != it;
	}
};

template <class T>
class List {
public:
	typedef  ListNode<T> Node;
	typedef Node* pNode;
	List()
	{
		CreatHead();
	}
	void CreatHead(){
		_head = new Node;
		_head->_next = _head;
		_head->_prev = _head;
	}
	void Push_Back(T x){
		pNode NewNode = new Node;
		NewNode->_val = x;
		pNode tail = _head->_prev;
		tail->_next = NewNode;
		NewNode->_prev = tail;
		NewNode->_next = _head;
		_head->_prev = NewNode;
	}
private:
	pNode _head;
};