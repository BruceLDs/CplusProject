#include<iostream>
using namespace std;
//交换函数模板
template <typename T>
void _swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}
//加法函数模板
template <typename T>

T add(const T& a, const T& b)
{
	return a + b;
}

template <typename T, class T2>
T add(const T& a, const T2& b)
{
	return a + b;
}
int add(const int& a, const int& b)
{
	return a + b;
}

class A
{
public:
	A(int a = 0)
		:_a(a)
	{}
private:
	int _a;
};

//int main()
//{
//	int a = 1, b = 2;
//	char c = 'a', d = 'b';
//	double e = 1.1, f = 2.2;
//	//隐式实例化
//	_swap(a, b);  // swap(int, int)
//	_swap(c, d);  // swap(char, char)
//	_swap(e, f); // swap(double, double)
//	A ao = 10;
//	A bo = 20;
//	_swap(ao, bo); // swap(A, A)
//	
//	const double& rd = a;
//	add((double)a, e);
//	cout << a << " " << e << endl;
//	add(a, (int)e);
//	//显式实例化
//	add<int>(a, e);
//	add<double>(a, e);
//	return 0;
//}

//int main()
//{
//	int a = 1, b = 2;
//	//非模板函数与模板函数共存，优先匹配非模板函数
//	add(a, b);
//	double c = 1.2;
//	//非模板函数与模板函数共存，优先匹配非模板函数, 
//	//如果不能完全匹配，实例化可以生成更加匹配的函数，则走实例化
//	add(a, c);
//	//如果声明显式实例化，一定会进行实例化
//	add<int>(a, b);
//	return 0;
//}
//类模板
typedef int DataType;
template <class DataType>
class SeqList
{
public:
	SeqList(int num = 10)
		:_data(new DataType[num])
		, _size(num)
		, _capacity(num)
	{
	}
	//浅拷贝
	SeqList<DataType>& operator=(const SeqList<DataType>& sq)
	{
		if (this != &sq)
		{
			_data = sq._data;
			_size = sq._size;
			_capacity = sq._capacity;
		}
		return *this;
	}

	void Display()
	{
		for (int i = 0; i != _size; ++i)
		{
			cout << _data[i] << endl;
		}
	}
	// a[i]
	DataType& operator[](size_t pos);
	/*{
	return _data[pos];
	}*/

	~SeqList()
	{
		if (_data)
		{
			delete[] _data;
			_data = nullptr;
			_size = _capacity = 0;
		}
	}

	size_t Size()
	{
		return _size;
	}

private:
	DataType* _data;
	size_t _size;
	size_t _capacity;
};

template <class DataType>
DataType& SeqList<DataType>::operator[](size_t pos)
{
	return _data[pos];
}

int main()
{
	//类模板： 
	// 类名 != 类型
	// 类名    类名<类型>
	SeqList<int> sl;
	SeqList<int> sl2;
	SeqList<char> sc;
	SeqList<float> sf;
	for (int i = 0; i != sl.Size(); ++i)
	{
		//sl[i] <---> sl.operator[](i)
		sl[i] = i;
		sl.operator[](i) = i;
		cout << sl[i] << endl;
	}
	sl2 = sl;
	return 0;
}