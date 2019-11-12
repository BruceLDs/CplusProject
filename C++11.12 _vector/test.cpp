#include <iostream>
#include <assert.h>
#include <string>
using namespace std;
template <class T>
class Vector
{
public:
	typedef T* iterator;
	typedef const T* const_iterator;

	Vector()
		:_start(nullptr)
		, _finish(nullptr)
		, _eos(nullptr)
	{}

	void PushBack(const T& val)
	{
		////容量
		//if (_finish == _eos)
		//{
		//	size_t newC = _start == nullptr ? 1 : 2 * Capacity();
		//	Reserve(newC);
		//}

		//*_finish = val;
		//++_finish;
		Insert(end(), val);
	}

	size_t Capacity()const
	{
		return _eos - _start;
	}

	void Reserve(size_t n)
	{
		int sz = Size();
		if (n > Capacity())
		{
			//开空间
			T* tmp = new T[n];

			//浅拷贝
			//memcpy(tmp, _start, sizeof(T)* sz);

			//深拷贝
			for (int i = 0; i < sz; ++i)
				tmp[i] = _start[i];  //T类型赋值运算符重载：深拷贝

			//释放原有的空间
			delete[] _start;

			_start = tmp;
			_finish = _start + sz;
			_eos = _start + n;
		}
	}

	size_t Size() const
	{
		return _finish - _start;
	}

	T& operator[](size_t pos)
	{
		assert(pos < Size());
		return _start[pos];
	}

	const T& operator[](size_t pos) const
	{
		assert(pos < Size());
		return _start[pos];
	}

	iterator begin()
	{
		return _start;
	}

	iterator end()
	{
		return _finish;
	}

	const_iterator begin() const
	{
		return _start;
	}

	const_iterator end() const
	{
		return _finish;
	}

	void Insert(iterator pos, const T& val)
	{
		//增容，迭代器失效
		int len = pos - _start;
		assert(pos >= begin() && pos <= end());
		if (_finish == _eos)
		{
			size_t newC = _start == nullptr ? 1 : 2 * Capacity();
			Reserve(newC);
		}
		//更新
		pos = _start + len;
		//元素移动
		iterator end = _finish;
		while (end > pos)
		{
			*end = *(end - 1);
			--end;
		}

		*pos = val;
		++_finish;
	}

	//迭代器失效
	iterator Erase(iterator pos)
	{
		assert(pos >= begin() && pos < end());
		iterator begin = pos + 1;
		//元素的移动
		while (begin < _finish)
		{
			*(begin - 1) = *begin;
			++begin;
		}

		--_finish;
		//返回被删除元素的下一个位置
		return pos;
	}

	void Resize(size_t n, const T& val = T())
	{
		if (n <= Size())
		{
			_finish = _start + n;
		}
		else
		{
			if (n > Capacity())
				Reserve(n);
			//赋值： [_finish ~ _start + n)
			while (_finish != _start + n)
			{
				*_finish = val;
				++_finish;
			}
		}
	}

	void PopBack()
	{
		Erase(end() - 1);
	}

	template <class InputIterator>
	Vector(InputIterator first, InputIterator last)
	{
		while (first != last)
		{
			PushBack(*first);
			++first;
		}
	}

	Vector(const Vector<T>& vec)
		:_start(new T[vec.Size()])
		, _finish(_start + vec.Size())
		, _eos(_start + vec.Capacity())
	{
		for (int i = 0; i < vec.Size(); ++i)
			_start[i] = vec[i];
	}

	Vector<T>& operator=(Vector<T> vec)
	{
		Swap(vec);
		return *this;
	}

	void Swap(Vector<T>& vec)
	{
		swap(_start, vec._start);
		swap(_finish, vec._finish);
		swap(_eos, vec._eos);
	}

	~Vector()
	{
		if (_start)
		{
			delete[] _start;
			_start = _finish = _eos = nullptr;
		}
	}


private:
	iterator _start;
	iterator _finish;
	iterator _eos;
};

template <class T>
void PrintVec(const Vector<T>& vec)
{
	for (size_t i = 0; i < vec.Size(); ++i)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
}

template <class T>
void PrintVecIterator(const Vector<T>& vec)
{
	Vector<T>::const_iterator vit = vec.begin();
	while (vit != vec.end())
	{
		cout << *vit << " ";
		++vit;
	}
	cout << endl;
}

template <class T>
void PrintVecFor(const Vector<T>& vec)
{
	for (const auto& v : vec)
		cout << v << " ";
	cout << endl;
}

void TestVec1()
{
	Vector<int> v;
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(4);
	PrintVec(v);
}

void TestVec2()
{
	Vector<string> v;
	v.PushBack("1");
	v.PushBack("2");
	v.PushBack("3");
	v.PushBack("4");
	v.Insert(v.begin() + 1, "0");

	PrintVecIterator(v);
	PrintVecFor(v);
}

void TestVec3()
{
	Vector<int> v;
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(4);
	//v.PushBack(5);
	Vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
			it = v.Erase(it);
		else
			++it;
	}
}

void TestVec4()
{
	/*Vector<Vector<int>> v;
	v.PushBack(Vector<int>());
	v.PushBack(Vector<int>());
	v.Resize(100);
	v.Resize(10);*/
	Vector<int> v;
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(4);
	v.PushBack(5);
	v.Resize(6);  // 赋值
	v.Resize(10, 10); // 增容，赋值
	v.Resize(2);

}

void TestVec5()
{
	Vector<int> v;
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(4);
	v.PushBack(5);
	v.PushBack(6);
	PrintVecFor(v);
	cout << "V.Erase()" << endl;
	v.PopBack();
	PrintVecFor(v);
	v.PopBack();
	PrintVecFor(v);
	v.PopBack();
	PrintVecFor(v);
	v.PopBack();
	PrintVecFor(v);
	v.PopBack();
	PrintVecFor(v);
	v.PopBack();
	PrintVecFor(v);
	/*v.PopBack();
	PrintVecFor(v);*/
}

void TestVec6()
{
	int arr[] = { 1, 2, 3, 4, 5, 6 };
	Vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));

	string str("abcdefghi");
	Vector<char> v2(str.begin(), str.end());

	Vector<char> v3(v2.begin(), v2.end());

}

void TestVec7()
{
	Vector<int> v;
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(4);
	v.PushBack(5);
	v.PushBack(6);
	Vector<int> copy(v);
	PrintVecFor(v);
	PrintVecFor(copy);
	Vector<int> v3;
	v3.PushBack(2);
	v3 = v;

}

int main()
{
	//TestVec1();
	//TestVec2();
	//TestVec3();
	//TestVec4();
	//TestVec5();
	//TestVec6();
	TestVec7();
	return 0;
}
