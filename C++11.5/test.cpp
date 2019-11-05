#include<iostream>
#include<string>
using namespace std;


void testString()
{
	string s("hello world");
	string::iterator sit = s.begin();
	cout << s << endl;
	// �������� �ɶ���д
	// operator[]: �ɶ���д
	// ��Χfor: �ɶ���д
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

	// reserve: ֻ����������������������� ����ı�size
	//�������ݵĴ��������Ч��
	//string�����߼�����ʼ��С 15�� ��һ��2���� ʣ�� 1.5��
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
	//��С���������������ıȽ϶࣬�Ż��С
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
	//�ں�����в���
	string s;
	s.append("012");//���
	cout << s << endl;
	string s2("345");
	s.append(s2);
	cout << s << endl;
	string s3("1234567");
	s.append(s3, 5, 2);//��s3�ĵ�5��λ�����2��Ԫ��
	cout << s << endl;
	//������Ȼ�ľ���һ��������
	char str[] = { "8910" };
	s.append(str, str + sizeof(str) / sizeof(str[0]));
	cout << s << endl;
	*/

	/*
		//insert(pos, string) : ��posλ��ǰ������µ��ַ���
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
	//��ֵs1.assign(s2);
	string s1("123");
	cout << s1 << endl;
	string s2("4");
	s1.assign(s2);
	//s1 = s2;
	cout << s1 << endl;
	//���ַ����ַ���
	string s;
	s += '0';
	cout << s << endl;
	s += "123";
	cout << s << endl;
	s += string("456");
	cout << s << endl;
	s.erase(0, 2);//ɾ��
	cout << s << endl;
	s.erase(s.begin());//ͷɾ
	cout << s << endl;
	s.erase(s.begin() + 1, s.end() - 1);//ɾ�����䣨a , b��������
	cout << s << endl;
	*/
	/*
		string s("01234");
	cout << s << endl;
	string s2("56789");
	s.replace(3, 1, s2);  //�ӵ�����λ�ã�һ���ַ���s2�滻һ���ַ�3
	cout << s << endl;
	swap(s, s2);//�����ַ���
	cout << s << endl;
	cout << s2 << endl;
	int a = 10, b = 20;
	swap(a, b);
	cout << s.substr(2, 2) << endl;//�ӵ�2��λ��ȡ2���ַ�
	string http("http://www.cplusplus.com/reference/string/string/?kw=string");
	size_t pos = http.find("://", 0);
	pos += 3;
	size_t end = http.find("/", pos);
	cout << http.substr(pos, end - pos) << endl;
	string fi("test.cpp.tar.gz.txt");
	size_t fpos = fi.rfind('.');//�������rfind
	cout << fi.substr(fpos + 1,fi.size() - fpos - 1)<<endl;
	*/

	//string s1("123");
	//string s2("45");
	//cout << (s1 < s2) << endl;
	//cout << (s1 > s2) << endl;
	//cout << (s1 == s2) << endl;
	

	string s1;
	string s2;
	/*cin: �����ո�/���н���
		getline: �������н���*/
	cin >> s1;
	getline(cin, s2);
	cout << s1 << endl;
	cout << s2 << endl;

	/*
	���죺������ �ַ�����ʼ��
	��������begin  end
	������ size, resize, reserve
	Ԫ�ط��ʣ� operator[]
	�޸ģ�operator+=   pop_back, swap
	���������� c_str, find, substr, <,>,<=, >=,==, !=, >>, <<, getline
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