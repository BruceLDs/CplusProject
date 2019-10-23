#define  _CRT_SECURE_NO_WARNINGS
#include"Data.h"
void testData(){
	Data d;//实例化
	//this指针指向当前调用函数的对象
	//this可以为空
	//只存在成员函数中
	d.SetData(2019, 10, 22);//this指针指向当前调用函数的对象
	d.Display();
	Data d2;
	d2.SetData(2020, 10, 22);
	d2.Display();
}
//没有显示定义构造的时候，编译器会默认生成
//默认构造函数
//			1.无参构造
//			2.编译器默认生成的
//			3.全缺省构造函数
void TestDate1()
{
	Date1 d1; // 调用无参构造函数
	Date1 d2(2015, 1, 1); // 调用带参的构造函数
	// 注意：如果通过无参构造函数创建对象时，对象后面不用跟括号，否则就成了函数声明
	// 以下代码的函数：声明了d3函数，该函数无参，返回一个日期类型的对象
		//Date1 d3();//函数声明
		Date1();
}
int main(){
	testData();
	TestDate1();
	cout << "   Hello C++  "    << endl;
	return 0;
}