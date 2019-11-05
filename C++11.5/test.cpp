#include<iostream>
#include<string>
using namespace std;


void testString()
{
	string s("hello world");
	string::iterator sit = s.begin();
	cout << s << endl;
	// 迭代器： 可读可写
	// operator[]: 可读可写
	// 范围for: 可读可写
	while (sit != s.end())
	{
		*sit = 'a';
		cout << *sit << " ";
		++sit;
	}
	cout << endl;
	cout << s << endl;
	for (int i = 0; i != s.length(); ++i)
	{
		s[i] = '0';
	}
	cout << s << endl;

	for (auto& ch : s)
	{
		ch = '1';
	}
	cout << s << endl;
}

void testCap()
{
	string s("123");
	cout << s << "end" << endl;
	cout << s.size() << endl;
	cout << s.length() << endl;
	cout << s.max_size() << endl;
	cout << s.capacity() << endl;
	s.resize(10, '1');
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << "end" << endl;
	/*char str[] = "12345\0\0\0\0";
	cout << str << "end" << endl;*/
	s.resize(1);
	cout << s <<"end"<< endl;
	s.resize(20);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << "end" << endl;

	// reserve: 只增加容量，不会减少容量， 不会改变size
	//减少增容的次数，提高效率
	//string增容逻辑：初始大小 15， 第一次2倍， 剩余 1.5倍
	s.reserve(50);
	cout << "s.reserve(50)" << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << "end" << endl;

	s.reserve(40);
	cout << "s.reserve(40)" << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	string s2;
	s2.reserve(100);
	int cap = s2.capacity();
	cout << cap << endl;
	for (int i = 0; i < 100; ++i)
	{
		s2.push_back(i);
		if (cap != s2.capacity())
		{
			cap = s2.capacity();
			cout << cap << " "<< s2.capacity() << endl;
		}
	}
	cout << s2.size() << endl;
	cout << s2.capacity() << endl;

	s2.shrink_to_fit();
	//减小容量，如果量级差的比较多，才会减小
	cout << "s2.shrink_to_fit()" << endl;
	cout << s2.capacity() << endl;

	s2.clear();  // size ---> 0
	cout << s2.size() << endl;
	cout << s2.capacity() << endl;

	s2.shrink_to_fit();
	cout << "s2.shrink_to_fit()" << endl;
	cout << s2.capacity() << endl;
}

void testAcc()
{
	string s("123456");
	cout << s[2] << endl;
	cout << s.at(2) << endl;
	cout << s.back() << endl;
	cout << s.front() << endl;
}

void testModi()
{
	/*
	//在后面进行插入
	string s;
	s.append("012");//添加
	cout << s << endl;
	string s2("345");
	s.append(s2);
	cout << s << endl;
	string s3("1234567");
	s.append(s3, 5, 2);//从s3的第5个位置添加2个元素
	cout << s << endl;
	//数组天然的就是一个迭代器
	char str[] = { "8910" };
	s.append(str, str + sizeof(str) / sizeof(str[0]));
	cout << s << endl;
	*/

	/*
		//insert(pos, string) : 在pos位置前面插入新的字符串
	string s("123");
	cout << s << endl;
	s.insert(0, "0");
	cout << s << endl;
	s.insert(0, "-2-1");
	cout << s << endl;
	string s2("456");
	s.insert(8, s2);
	cout << s << endl;
	s.insert(s.begin() + 4, '+');
	cout << s << endl;
	char str[] = { "78910" };
	//s.append(str, str + sizeof(str) / sizeof(str[0]));
	s.insert(s.end(), str, str + sizeof(str) / sizeof(str[0]));
	cout << s << endl;
	*/

	/*
	//赋值s1.assign(s2);
	string s1("123");
	cout << s1 << endl;
	string s2("4");
	s1.assign(s2);
	//s1 = s2;
	cout << s1 << endl;
	//加字符或字符串
	string s;
	s += '0';
	cout << s << endl;
	s += "123";
	cout << s << endl;
	s += string("456");
	cout << s << endl;
	s.erase(0, 2);//删除
	cout << s << endl;
	s.erase(s.begin());//头删
	cout << s << endl;
	s.erase(s.begin() + 1, s.end() - 1);//删除区间（a , b）开区间
	cout << s << endl;
	*/
	/*
		string s("01234");
	cout << s << endl;
	string s2("56789");
	s.replace(3, 1, s2);  //从第三个位置，一个字符串s2替换一个字符3
	cout << s << endl;
	swap(s, s2);//交换字符串
	cout << s << endl;
	cout << s2 << endl;
	int a = 10, b = 20;
	swap(a, b);
	cout << s.substr(2, 2) << endl;//从第2个位置取2个字符
	string http("http://www.cplusplus.com/reference/string/string/?kw=string");
	size_t pos = http.find("://", 0);
	pos += 3;
	size_t end = http.find("/", pos);
	cout << http.substr(pos, end - pos) << endl;
	string fi("test.cpp.tar.gz.txt");
	size_t fpos = fi.rfind('.');//反向查找rfind
	cout << fi.substr(fpos + 1,fi.size() - fpos - 1)<<endl;
	*/

	//string s1("123");
	//string s2("45");
	//cout << (s1 < s2) << endl;
	//cout << (s1 > s2) << endl;
	//cout << (s1 == s2) << endl;
	

	string s1;
	string s2;
	/*cin: 遇到空格/换行结束
		getline: 遇到换行结束*/
	cin >> s1;
	getline(cin, s2);
	cout << s1 << endl;
	cout << s2 << endl;

	/*
	构造：拷贝， 字符串初始化
	迭代器：begin  end
	容量： size, resize, reserve
	元素访问： operator[]
	修改：operator+=   pop_back, swap
	其他操作： c_str, find, substr, <,>,<=, >=,==, !=, >>, <<, getline
	*/
}

int main()
{
	//testString();
	//testCap();
	//testAcc();
	testModi();
	//Solution s;
	//string str("-2147483648");
//	cout << s.StrToInt(str) << endl;
	return 0;
}