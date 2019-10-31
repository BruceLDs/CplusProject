#define  _CRT_SECURE_NO_WARNINGS
#include <string>
#include <list>
#include <iostream>
using namespace std;
//typedef basic_string<char> string;
//构造
/*
default (1)
string();
copy (2)
string (const string& str);
substring (3)
string (const string& str, size_t pos, size_t len = npos);
from c-string (4)
string (const char* s);
from sequence (5)
string (const char* s, size_t n);
fill (6)
string (size_t n, char c);
range (7)
template <class InputIterator>
string  (InputIterator first, InputIterator last);
*/
void testString1()
{
	string s;
	string s2("hello world");
	string copy(s2);
	string s3(s2, 0, 5);  // hello
	string s4("hello world", 2);  // he
	string s5(10, 'a'); // "aaaaaaaaaa"

	char str1[] = "china";
	char str2[] = "中国";
	/*cout << sizeof(str1) << endl;
	cout << sizeof(str2) << endl;
	cout << str1 << endl;
	cout << str2 << endl;*/
	char str3[5];
	cout << str3 << endl;

	str3[0] = -42;
	str3[1] = -48;
	str3[2] = -71;
	str3[3] = -5;
	str3[4] = 0;
	cout << str3 << endl;
}

void testIterator()
{

	string s2("hello world");
	/*
	迭代器：一种容器内容的访问机制, 可读可写的接口
	使用方式：类似于指针的使用方式
	begin迭代器： 指向容器的第一个元素的位置
	end迭代器： 指向容器的最后一个元素的下一个位置
	左闭右开： [begin, end)
	*/
	string::iterator it = s2.begin();
	while (it != s2.end())
	{
		//*it = 'a';
		cout << *it << " ";
		++it;
	}
	cout << endl;

	string::reverse_iterator rit = s2.rbegin();
	while (rit != s2.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	//for循环
	for (int i = 0; i < s2.size(); ++i)
	{
		cout << s2[i] << " ";
	}
	cout << endl;
	//范围for
	for (const auto& ch : s2)
	{
		cout << ch << " ";
	}
	cout << endl;

	//const 迭代器
	const string s3("hello");
	string::const_iterator s3it = s3.begin();
	while (s3it != s3.end())
	{
		//*s3it = 'a';
		cout << *s3it << " ";
		++s3it;
	}
	cout << endl;

	string::const_reverse_iterator s3rit = s3.rbegin();
	while (s3rit != s3.rend())
	{
		//*s3it = 'a';
		cout << *s3rit << " ";
		++s3rit;
	}
	cout << endl;



	/*list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	list<int>::iterator lit = l.begin();
	while (lit != l.end())
	{
	cout << *lit << " ";
	++lit;
	}
	cout << endl;*/
}
int main()
{
	//testString1();
	testIterator();
	return 0;
}