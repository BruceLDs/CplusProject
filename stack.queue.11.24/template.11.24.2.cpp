#include <iostream>
using namespace std;

template <class T>
void Copy(T* dest, T* src, size_t sz)
{
	memcpy(dest, src, sizeof(T)* sz);
}

template <class T>
void Copy2(T* dest, T* src, size_t sz)
{
	for (int i = 0; i < sz; ++i)
	{
		dest[i] = src[i];
	}
}

template <class T>
void Copy3(T* dest, T* src, size_t sz, int flag)
{
	if (flag)
	{
		memcpy(dest, src, sizeof(T)* sz);
	}
	else
	{
		for (int i = 0; i < sz; ++i)
		{
			dest[i] = src[i];
		}
	}

}
 //plain old data POD: 内置类型
bool isPODType(const char* datatype)
{
	static char* typeArr[] = { "int", "float", "char", "double" };
	for (int i = 0; i < sizeof(typeArr) / sizeof(typeArr[0]); ++i)
	{
		if (strcmp(typeArr[i], datatype) == 0)
			return true;
	}
	return false;
}

template <class T>
void Copy4(T* dest, T* src, size_t sz)
{
	if (isPODType(typeid(T).name()))
	{
		memcpy(dest, src, sizeof(T)* sz);
	}
	else
	{
		for (int i = 0; i < sz; ++i)
		{
			dest[i] = src[i];
		}
	}
}


void testMemCpy()
{
	string strArr[] = { "1", "2", "3" };
	string strCopyArr[3];

	int arr[] = { 1, 2, 3 };
	int copy[3];
	//Copy(strCopyArr, strArr, 3);
	//Copy2(strCopyArr, strArr, 3);
	//Copy3(strCopyArr, strArr, 3, 1);
	Copy4(strCopyArr, strArr, 3);
	Copy4(copy, arr, 3);
}

//int main()
//{
//
//	//testArray();
//	//testString();
//	//Data<char, int> data1;  //实例化
//	//Data<int, int> data2; //直接使用特化
//	//Data<int, char> data3; //偏特化
//	//Data<int*, int*> data4;
//	//cout << Sum<501>::RET << endl;
//	return 0;
//}

//int main()
//{
//	testMemCpy();
//	return 0;
//}

//struct FalseType
//{
//	static bool getType()
//	{
//		return false;
//	}
//};
//
//struct TrueType
//{
//	static bool getType()
//	{
//		return true;
//	}
//};
//
//template<class T>
//struct TypeTraits
//{
//	typedef FalseType isPodType;
//};
//
//template<>
//struct TypeTraits<char>
//{
//	typedef TrueType isPodType;
//};
//template<>
//struct TypeTraits<int>
//{
//	typedef TrueType isPodType;
//};
//template<>
//struct TypeTraits<float>
//{
//	typedef TrueType isPodType;
//};
//template<>
//struct TypeTraits<double>
//{
//	typedef TrueType isPodType;
//};

//template <class T>
//void Copy5(T* dest, T* src, size_t sz)
//{
//	if (TypeTraits<T>::isPodType::getType())
//	{
//		memcpy(dest, src, sizeof(T)* sz);
//	}
//	else
//	{
//		for (int i = 0; i < sz; ++i)
//		{
//			dest[i] = src[i];
//		}
//	}
//}

//void testTypeTraits()
//{
//	string strArr[] = { "1", "2", "3" };
//	string strCopyArr[3];
//
//	int arr[] = { 1, 2, 3 };
//	int copy[3];
//
//	Copy5(strCopyArr, strArr, 3);
//	Copy5(copy, arr, 3);
//}


struct FalseType
{};

struct TrueType
{};

template<class T>
struct TypeTraits
{
	typedef FalseType isPodType;
};

template<>
struct TypeTraits<char>
{
	typedef TrueType isPodType;
};
template<>
struct TypeTraits<int>
{
	typedef TrueType isPodType;
};
template<>
struct TypeTraits<float>
{
	typedef TrueType isPodType;
};
template<>
struct TypeTraits<double>
{
	typedef TrueType isPodType;
};

template <class T>
void _Copy(T* dest, T* src, size_t sz, TrueType)
{
	memcpy(dest, src, sizeof(T)* sz);
}

template <class T>
void _Copy(T* dest, T* src, size_t sz, FalseType)
{
	for (int i = 0; i < sz; ++i)
	{
		dest[i] = src[i];
	}
}

template <class T>
void _Copy(T* dest, T* src, size_t sz)
{
	_Copy(dest, src, sz, TypeTraits<T>::isPodType());
}

void testTypeTraits2()
{
	string strArr[] = { "1", "2", "3" };
	string strCopyArr[3];

	int arr[] = { 1, 2, 3 };
	int copy[3];

	_Copy(strCopyArr, strArr, 3);
	_Copy(copy, arr, 3);
}



//int main()
//{
//	testTypeTraits2();
//	return 0;
//}