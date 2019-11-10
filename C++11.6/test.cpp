#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include<assert.h>
using namespace std;
#if 0
class String
{
public:
	/*
		String()
	:_str(new char[1])
	{
	*_str = '\0';
	}
	String(char* str)
	:_str(new char[strlen(str) + 1])
	{
	strcpy(_str, str);
	}
	*/

	String(char* str = "")//ȱʡ���죬�����޲κʹ���
		:_str(new char[strlen(str) + 1])
	{
		strcpy(_str, str);
	}

	/*
		String(const String& str)
	:_str(new char[strlen(str._str) + 1])
	{
	strcpy(_str, str._str);
	}
	*/

	String(const String& str)
		:_str(nullptr)
	{
		String tmp(str._str);
		swap(_str, tmp._str);
	}

	String& operator=(const String& str)//��ֵ���������
	{
	if (this != &str)
	{
	delete[] _str;
	_str = new char[strlen(str._str) + 1];
	strcpy(_str, str._str);
	}
	return *this;
	}
	const char* c_str() const
	{
		return _str;
	}

	~String()
	{
		if (_str)
			delete[] _str;
	}

private:
	char* _str;
};

void testString1()
{
	String s;
	/*
	string s2;//�Աȿ��string��
	cout << s.c_str() << endl;
	cout << s2.c_str() << endl;
	cout << (int*)s.c_str() << endl;
	cout << (int*)s2.c_str() << endl;
	cout << s2.capacity() << endl;
	cout << s2.size() << endl;
	*/
	
	char* str = new char[10];
	strcpy(str, "hello");
	String s3(str);
	delete[] str;
}

void testString2()
{
	String s1("hello");
	String s2 = s1;  // ��������
    s2 = s1; // ��ֵ�����
	cout << s1.c_str() << endl;
	cout << s2.c_str() << endl;
}

int main()
{
	//testString1();
	testString2();
	return 0;
}
#endif
class String{
public:
	typedef char* iterator;
	//typefef ;
	String(const char* str = "")//����
	{
		_size = strlen(str);
		_capacity = _size;
		_str = new char[_size + 1];
		strcpy(_str, str);
	}
	String(const String& s)//����
		: _str(nullptr)
		, _size(0)
		, _capacity(0)
	{
		String tmp(s._str);
		Swap(tmp);
	}
	void Swap(String& str)//����
	{
		swap(_str, str._str);
		swap(_size, str._size);
		swap(_capacity, str._capacity);
	}
	String& operator=(String s)//��ֵ
	{
			Swap( s );
			return *this;
	}
	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}
	// ������
	iterator begin()
	{
		return _str; 
	}
	iterator end()
	{
		return _str + _size; 
	}
	const iterator c_begin()
	{
		return _str;
	}
	const iterator c_end()
	{
		return _str + _size;
	}
	// �޸�
	void PushBack(char c)
	{
		//�������
		if (_size == _capacity)
			Reserve(_capacity * 2);
		_str[_size++] = c;
		_str[_size] = '\0';
	}
	String& operator+=(char c)
	{
		PushBack(c);
		return *this;
	}
	void Append(const char* str)
	{
		int sz = strlen(str);
		if (_size + sz > _capacity)
			Reserve(_size + sz);
		strcpy(_str + _size, str);
		_size += sz;
	}
	String& operator+=(const char* str)
	{
		Append(str);
		return *this;
	}
	void Clear()
	{
		_size = 0;
		_str[_size] = '\0';
	}
	const char* c_str()const
	{
		return _str;
	}
	size_t Size()const{
		return _size;
	}
	size_t Capacity()const{
		return _capacity;
	}
	bool Empty()const{
		if (_size == 0)
			return true;
		return false;
	}
		void Resize(size_t newSize, char c = '\0')//�޸�_size
	{
			if (newSize > _size)
			{
				// ���newSize���ڵײ�ռ��С������Ҫ���¿��ٿռ�
				if (newSize > _capacity)
				{
					Reserve(newSize);
				}
				memset(_str + _size, c, newSize - _size);
			}
			_size = newSize;
			_str[newSize] = '\0';
		}
	void Reserve(size_t newCapacity)//����
	{
		// ������������ھ��������򿪱ٿռ�
		if (newCapacity > _capacity)
		{
			char* str = new char[newCapacity + 1];
			strcpy(str, _str);
			// �ͷ�ԭ���ɿռ�,Ȼ��ʹ���¿ռ�
			delete[] _str;
			_str = str;
			_capacity = newCapacity;
		}
	}
	char& operator[](size_t index)
	{
		assert(index < _size);
		return _str[index];
	}
	const char& operator[](size_t index)const
	{
		assert(index < _size);
		return _str[index];
	}
	bool operator<(const String& s)
	{
		if (_size >s. _size)
			return true;
		else
			return false;
	}
	bool operator<=(const String& s)
	{
		if (_size <= s._size)
			return true;
		else
			return false;
	}
	bool operator==(const String& s)
	{
		if (_size == s._size)
			return true;
		return false;
	}
	// ����c��string�е�һ�γ��ֵ�λ��
	size_t Find(char c, size_t pos = 0) const
	{
		for (int i = pos; i != _size; i++){
			if (c == _str[i])
				return i;
		}
		return npos;
	}
	// �����Ӵ�s��string�е�һ�γ��ֵ�λ��
	size_t Find(const char* s, size_t pos = 0) const
	{
		char* start = strstr(_str + pos, s);
		if (start == nullptr)
			return npos;
		else
			return start - _str;

	}
	// ��posλ���ϲ����ַ�c/�ַ���str�������ظ��ַ���λ��
	String& Insert(size_t pos, char c)
	{
		assert(pos >= 0 && pos <= _size);
		if (_size == _capacity){
			size_t newC = _capacity == 0 ? 15 : 2 * _capacity;
			Reserve(newC);
		}
		size_t end = _size + 1; 
		while (end > pos){
			_str[end] = _str[end - 1];
			end--;
		}
		_str[pos] = c;
		_size++;
		return *this;
	}
	String& Insert(size_t pos, const char* str)
	{
		assert(pos <= _size);
		int sz = strlen(str);
		if (_size + sz > _capacity)
			Reserve(_size + sz);
		size_t end = _size + sz;
		while(end > pos + sz - 2){
			_str[end] = _str[end - sz];
			--end;
		}
		while (*str){
			_str[pos] = *str++;
			pos++;
		}
		_size += sz;
		return *this;
	}
	// ɾ��posλ���ϵ�Ԫ�أ������ظ�Ԫ�ص���һ��λ��
	String& Erase(size_t pos, size_t len){
		assert(pos < _size);
		if (pos + len < _size){
		size_t start = pos + len;
		//��ǰ�����ƶ�
		while (start <= _size){
			_str[start - len] = _str[start];
			start++;
		}
		}
		else{
			_size = pos;
			_str[_size] = '\0';
		}
		return *this;
	}
private:
    friend ostream& operator<<(ostream& _cout, const String& s);
	char* _str;
	size_t _capacity;
	size_t _size;
	static int npos;
};
int String::npos = 0;
char* Strstr(char* dest, char* src){
	char* pdest = dest;
	char* psrc = src;
	while (*pdest){
		if (*pdest == *psrc){
			char* mdest = pdest;
			char* msrc = psrc;
			while (*mdest && *msrc){
				if (*mdest != *msrc)
				break;
				mdest++;
				msrc++;
			}
			if (*msrc == '\0')
				return pdest;
		}
		pdest++;
	}
	return nullptr;
}
void TestString()
{
	String s1("hello st");
	s1.PushBack(' ');
	s1.PushBack('i');
	s1.Append("n");
	s1 += 'g';
	cout << s1.c_str() << endl;
	cout << s1.Size() << endl;
	cout << s1.Capacity() << endl;
	//// ���õ�������ӡstring�е�Ԫ��
	String::iterator it = s1.begin();
	while (it != s1.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	// ������Կ���һ����ֻҪ֧�ֵĻ�����iterator����֧�ַ�Χfor
	for (auto ch : s1)
		cout << ch << " ";
	cout << endl;
}
void TestString1(){
	String s("Hello string");
	String s1;
	s1 = s;
	cout << s1.c_str() << endl;
	//s1.Resize(20);
	//cout << s1.c_str() << endl;
	//cout << s1<< "end"<<endl;
	/*s1.Insert(3, 'c');
	cout << s1.c_str() << endl;*/
	s1.Insert(3, "aaa");
	/*s1.Erase(7, 2);*/
	cout << s1.c_str() << endl;

}
void TestString2(){
	char* str1 = "abcd";
	char* str2 = "bc";
	cout << Strstr(str1, str2) << endl;
}
int main(){
	//TestString();
	TestString1();
	//TestString2();
	return 0;
}