#define  _CRT_SECURE_NO_WARNINGS
/*
//求1+2+3+...+n
//要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C) 
#include<iostream>
using namespace std;
class Solution {
public:
	int Sum_Solution(int n) {
		int sum = 0;
		int tmp = func(n, sum);
		return tmp;
	}
	int func(int n, int &sum)
	{
		n&&func(n - 1, sum);
		sum += n;
		return sum;
	}
};
int main(){
	Solution s;
	cout << s.Sum_Solution(10) << endl;
	return 0;
}
*/

#include<stdio.h>
#include<assert.h>
#include<string.h>

int main()
{
	FILE *pf = fopen("test.txt", "w");
	assert(pf != NULL);
	char ch[10] = "hellogao";
	fwrite(&ch, sizeof(char), strlen(ch), pf);

	long int size = ftell(pf);
	printf("%d\n", size);

	//rewind(pf);//将文件指针，拉回文件其实位置

	char ch2;
	while (fread(&ch2, sizeof(char), 1, pf) > 0)
	{
		putchar(ch2);
	}

	//SEEK_END 文件的尾巴    SEEK_SET设置文件指针为文件开始的位置
	//
	//fseek(pf,3,SEEK_SET);//logao
	//fseek(pf,-12,SEEK_CUR);//SEEK_CUR   当前文件指针的位置

	/*char ch2;
	while(fread(&ch2,sizeof(char),1,pf) > 0)
	{
	putchar(ch2);
	}*/
	fclose(pf);
	pf = NULL;
	return 0;
}

#if 0
void CopyMp4(char *destPath, const char *srcPath)
{
	FILE *fr = fopen(srcPath, "rb");

	FILE *fw = fopen(destPath, "wb");
	char ch;

	assert(fr != NULL && fw != NULL);
	//fread 读取成功的字节数
	while (fread(&ch, sizeof(char), 1, fr)  > 0)
	{
		fwrite(&ch, sizeof(char), 1, fw);
	}

	fclose(fr);
	fclose(fw);
	fr = NULL;
	fw = NULL;
}

int main()
{
	char *srcPath = "E:\\视频.mp4";

	char *destPath = "D:\\视频2.mp4";
	CopyMp4(destPath, srcPath);

	return 0;
}


typedef struct Student
{
	char name[20];
	int age;
}Student;
//size_t fwrite( const void *buffer, size_t size, size_t count, FILE *stream );

//Reads data from a stream.
//size_t fread( void *buffer, size_t size, size_t count, FILE *stream );

int main()
{
	//Student stu1 = {"zhansan",19};
	Student stu2 = { 0 };

	FILE *pf = fopen("test.txt", "rb");//如果没有文件  会新建文件
	assert(pf != NULL);
	//要写的数据  ， 每次写的数据大小，次数，写到哪里
	fread(&stu2, sizeof(Student), 1, pf);

	printf("%s,%d\n", stu2.name, stu2.age);

	fclose(pf);
	pf = NULL;

}
#endif
#if 0
int main()
{
	Student stu1 = { "zhansan", 19 };
	Student stu2 = { 0 };

	FILE *pf = fopen("test.txt", "wb");//如果没有文件  会新建文件
	assert(pf != NULL);
	//要写的数据  ， 每次写的数据大小，次数，写到哪里
	fwrite(&stu1, sizeof(Student), 1, pf);

	fclose(pf);
	pf = NULL;

}
#endif
#if 0
typedef struct Student
{
	char name[20];
	int age;
}Student;
//int sprintf( char *buffer, const char *format [, argument] ... );
//int sscanf( const char *buffer, const char *format [, argument ] ... );
int main()
{
	Student stu1 = { "zhansan", 19 };
	Student stu2 = { 0 };
	char buff[100];

	sprintf(buff, "%s %d", stu1.name, stu1.age);

	sscanf(buff, "%s %d", stu2.name, &stu2.age);

	printf("%s,%d\n", stu2.name, stu2.age);

	return 0;
}


typedef struct Student
{
	char name[20];
	int age;
}Student;
//写文件
//int fprintf( FILE *stream, const char *format [, argument ]...);
//int fscanf( FILE *stream, const char *format [, argument ]... );
int main()
{
	Student stu1 = { "zhansan", 19 };
	Student stu2 = { 0 };

	FILE *pf = fopen("test.txt", "r");//如果没有文件  会新建文件
	assert(pf != NULL);
	//以格式化的形式 进行写
	//fprintf(pf,"%s %d",stu1.name,stu1.age);
	//读
	fscanf(pf, "%s %d", stu2.name, &stu2.age);

	printf("%s,%d\n", stu2.name, stu2.age);

	fclose(pf);
	pf = NULL;
}
#endif

#if 0
//char *fgets( char *string, int n, FILE *stream );
//                     读取出来放的位置             从哪里读
int main()
{
	FILE *pf = fopen("test.txt", "r");//如果没有文件  会新建文件
	char buff[100];
	assert(pf != NULL);

	while (fgets(buff, strlen(buff), pf) != NULL)
	{
		printf("%s", buff);
	}

	fclose(pf);
	pf = NULL;
}



//写文件  int fputs( const char *string, FILE *stream );
int main()
{
	FILE *pf = fopen("test.txt", "w");//如果没有文件  会新建文件
	assert(pf != NULL);

	fputs("hello 61", pf);//如果原来文件有内容 覆盖掉
	fputs("hello 62", pf);
	fputs("hello 63", pf);
	fclose(pf);
	pf = NULL;
	return 0;
}

#endif


#if 0
//int fgetc( FILE *stream ); 读文件
int main()
{
	FILE *pf = fopen("test.txt", "r");//如果没有文件  会新建文件
	assert(pf != NULL);

	/*int ch = 0;
	ch = fgetc(pf);
	printf("%c ",ch);
	ch = fgetc(pf);
	printf("%c ",ch);
	ch = fgetc(pf);
	printf("%c ",ch);*/
	int ch = 0;
	while ((ch = fgetc(pf)) != EOF)//EOF
	{
		//printf("%c ",ch);
		putchar(ch);
	}

	fclose(pf);
	pf = NULL;
	return 0;
}

//写文件
int main()
{
	FILE *pf = fopen("test.txt", "w");//如果没有文件  会新建文件
	assert(pf != NULL);

	fputc('b', pf);
	fputc('i', pf);
	fputc('t', pf);

	fclose(pf);
	pf = NULL;
	return 0;
}
#endif
