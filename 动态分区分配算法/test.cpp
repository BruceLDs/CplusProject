////#define  _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<vector>
//using namespace std;
//void menu(vector<int> a);
//typedef struct PcbNode{
//	int val;
//	bool state;//false为空闲，true为已分配
//}PNode;
////空闲为负数，分配为正数
//void FreeSpace(vector<int> a){
//	cout << a.front();
//	vector<int>::iterator cur = a.begin();
//	for (; cur != a.end(); cur++)
//		cout << *cur << endl;
//}
//
////首次适应算法FF
//void FirstFit(vector<PNode> p, vector<int> a){
//	cout << "首次适应算法" << endl;
//	for (int i =0; i < a.size(); i++){   //遍历进程
//		vector<int>::iterator j = a.begin(); 
//		//每次从分区的首地址开始查找
//		for (int j = 0;  j < p.size();  j++){  
//			//当系统内存分区足够大的时候，即分配给进程资源
//			if (a[i] > 0 && p[j].state == false && p[j].val > a[i]){
//				int temp = p[j].val - a[i];
//				p[j].val = a[i];
//				if (j + 1 != p.size())
//					p[j + 1].val += temp;
//				p.push_back()
//			}
//
//			 //当内存分区足够才执行，当前进程大小置0
//			  //存储各个进程所在的分区位置
//				break;   //一个进程分区完后，立即进行下一个进程的判断
//		}
//	}
//	menu(p);
//}
////
//////循环首次适应算法NF
////void NextFit(){
////	cout << "NF" << endl;
////	int i, j, nextPoint = 0;
////	bool isWhile;
////	for (i = 0; i<ProcessNum; i++){
////		isWhile = true;
////		while (isWhile){     //每次都从当前分区的下一个分区开始查找
////			if (LeftFreePartition[nextPoint] >= LeftProcessNeed[i]){
////				LeftFreePartition[nextPoint] -= LeftProcessNeed[i];
////				LeftProcessNeed[i] = 0;
////				NameProcessToPartition[i][nextPoint] = ProcessName[i];
////				nextPoint++;
////				if (nextPoint > PartitionNum - 1){
////					nextPoint = 0;  //当j遍历到分区末尾的时候，返回首位置
////				}
////				isWhile = false;
////			}
////			else{
////				nextPoint++;
////				if (nextPoint > PartitionNum - 1){
////					nextPoint = 0;  //当j遍历到分区末尾的时候，返回首位置
////				}
////				j++;
////				if (j >= PartitionNum){//避免死循环
////					isWhile = false;
////					j = 0;
////				}
////
////			}
////
////		}
////	}
////	display();
////}
////
////
//////最佳适应算法BF
////void BestFit(){
////	//对分区大小进行排序,每次分配完一个进程的内存大小后，重新排序
////	cout << "BF" << endl;
////	initial();
////	int i, j, s, t;
////	sortNeed best[MAXNUMBER];
////	sortNeed temp;
////	for (i = 0; i<PartitionNum; i++){
////		best[i].partitionSize = FreePartition[i];
////		best[i].id = i;
////	}
////
////	for (i = 0; i<ProcessNum; i++){
////		//冒泡排序(每次分配完一个进程后，都需要重新排序)
////		for (s = 0; s < PartitionNum - 1; s++){
////			for (t = s; t < PartitionNum - 1; t++){
////				if (best[s].partitionSize > best[t].partitionSize){
////					temp = best[s];
////					best[s] = best[t];
////					best[t] = temp;
////				}
////			}
////		}
////
////		for (j = 0; j<PartitionNum; j++){
////			if (LeftProcessNeed[i] <= best[j].partitionSize){
////				best[j].partitionSize -= LeftProcessNeed[i];
////				LeftProcessNeed[i] = 0;
////
////				NameProcessToPartition[i][best[j].id] = ProcessName[i];
////				break;
////			}
////		}
////		LeftFreePartition[best[j].id] = best[j].partitionSize;
////	}
////	display();
////}
////
//////最坏适应算法WF
////void WorstFit(){
////	cout << "WF" << endl;
////	initial();
////	int i, j, s, t;
////	sortNeed Worst[MAXNUMBER];
////	sortNeed temp;
////	for (i = 0; i<PartitionNum; i++){
////		Worst[i].partitionSize = FreePartition[i];
////		Worst[i].id = i;
////	}
////
////	for (i = 0; i<ProcessNum; i++){
////		for (s = 0; s<PartitionNum - 1; s++){
////			for (t = s; t<PartitionNum - 1; t++){
////				if (Worst[s].partitionSize < Worst[t].partitionSize){
////					temp = Worst[s];
////					Worst[s] = Worst[t];
////					Worst[t] = temp;
////				}
////			}
////		}
////
////		for (j = 0; j<PartitionNum; j++){
////			if (LeftProcessNeed[i] <= Worst[j].partitionSize){
////				Worst[j].partitionSize -= LeftProcessNeed[i];
////				LeftProcessNeed[j] = 0;
////
////				NameProcessToPartition[i][Worst[j].id] = ProcessName[i];
////				break;
////			}
////			else{
////				cout << "Fail to Partition " << ProcessName[i] << endl;
////				break;
////			}
////		}
////		LeftFreePartition[Worst[j].id] = Worst[j].partitionSize;
////	}
////	display();
////}
//void menu(vector<int> a){
//	vector<PNode> p;
//	p.resize(a.size() + 1);
//	p[0].state = false;
//	p[0].val = 512;
//	int k = 0;
//	cout << "**********************************" << endl;
//	cout << "*******1.首次适应算法      *********" << endl;
//	cout << "*******2.循环首次适应算法********" << endl;
//	cout << "*******3.最佳适应算法      *********" << endl;
//	cout << "*******4.最坏适应算法      *********" << endl;
//	cout << "**********************************" << endl;
//	cin >> k;
//		switch (k){
//		case 1:FirstFit(p, a);
//			FreeSpace(p); break;
//		/*case 2:NF(a, arr); FreeSpace(a); break;
//		case 3:BF(a, arr); FreeSpace(a); break;
//		case 4:WF(a, arr); FreeSpace(a); break;*/
//		default:cout << "退出系统！" << endl; break;
//		}
//}
//void test(){
//		vector<int> a= { 300, 100, -300, 150, 30, 40, 60 , -30 };
//		menu(a);
//	system("pause");
//}
//int main(){
//	test();
//	return 0;
//}
//#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#define MAXNUMBER 10
static int PartitionNum;  //内存中空闲分区的个数
static int ProcessNum; //需要分配的进程个数
static int FreePartition[MAXNUMBER];  //空闲分区对应的内存
static int ProcessNeed[MAXNUMBER];  //需要分配的进程大小

static int LeftFreePartition[MAXNUMBER];
static int LeftProcessNeed[MAXNUMBER];

static char ProcessName[MAXNUMBER];
static char NameProcessToPartition[MAXNUMBER][MAXNUMBER];

typedef struct
{
	int partitionSize;
	int id;
}sortNeed;

void readDataFunction();
void input();
void display();
void FirstFit();
void NextFit();
void BestFit();
void WorstFit();
void selectAlgorithm(int chooceAlgorithm);
void display();


void readDataFunction()
{
	int a[8] = { 300, 100, -300, 150, 30, 40, 60, -30 };
	FreePartition[0] = 512;
	for (int i = 0; i<ProcessNum; i++)
	{
		 ProcessNeed[i] = a[i];
	}
}

void input()
{
	cout << "请选择实现的算法：" << endl;
	cout << "*****  1 - 首次适应算法     *****" << endl;
	cout << "*****  2 - 循环首次适应算法 *****" << endl;
	cout << "*****  3 - 最佳适应算法     *****" << endl;
	cout << "*****  4 - 最坏适应算法     *****" << endl;
	cout << "*****  0 - 结束             *****" << endl;
	int chooseAlgorithm = 5;
	while (chooseAlgorithm)
	{
		cout << "chooseAlgorithm = ";
		cin >> chooseAlgorithm;
		selectAlgorithm(chooseAlgorithm);
	}
}

void initial()
{
	readDataFunction();   //读取原始数据
	for (int i = 0; i<PartitionNum; i++)
	{
		LeftFreePartition[i] = FreePartition[i];
		for (int j = 0; j<ProcessNum; j++)
		{
			NameProcessToPartition[i][j] = NULL;
		}
	}
	for (int i = 0; i<ProcessNum; i++)
	{
		LeftProcessNeed[i] = ProcessNeed[i];
	}
}


void FirstFit()
{
	cout << "***********首次适应算法***********" << endl;
	initial();

	int i, j;
	for (i = 0; i<ProcessNum; i++)   //逐个遍历每个进程
	{
		for (j = 0; j<PartitionNum; j++)
		{
			if (LeftProcessNeed[i] <= LeftFreePartition[j] && LeftFreePartition != 0)  //当系统内存分区足够大的时候，即分配给进程资源
			{
				LeftFreePartition[j] -= LeftProcessNeed[i];   //扣除分配给进程的资源
				LeftProcessNeed[i] = 0;  //当且仅当系统内存分区足够时才执行，即当前进程大小置0

				NameProcessToPartition[i][j] = ProcessName[i];  //存储各个进程所在的分区位置

				break;   //!!!很重要，一个进程分区完后，应该立即break，进行下一个进程的判断
			}
		}
	}

	display();

}

void NextFit()
{
	cout << "***********循环首次适应算法***********" << endl;
	initial();
	int i, nextPoint = 0;
	bool isWhile;
	for (i = 0; i<ProcessNum; i++)
	{
		isWhile = true;
		while (isWhile)
		{
			if (LeftFreePartition[nextPoint] >= LeftProcessNeed[i])
			{
				LeftFreePartition[nextPoint] -= LeftProcessNeed[i];
				LeftProcessNeed[i] = 0;
				NameProcessToPartition[i][nextPoint] = ProcessName[i];
				nextPoint++;
				if (nextPoint > PartitionNum - 1)
				{
					nextPoint = 0;  //当j遍历到分区末尾的时候，返回首位置
				}
				isWhile = false;
			}
			else
				nextPoint++;
		}
	}
	display();
}

void BestFit()
{
	//思想：利用冒泡排序对分区大小进行排序，但不改变原分区的位置
	//创建一个结构体，包括分区大小和所对应的id，排序过程中，每改变顺序一次，id随着改变
	//关键：每次分配完一个进程的内存大小后，都要重新排序
	cout << "***********最佳适应算法***********" << endl;
	initial();
	int i, j, temp, tempID;

	sortNeed best[MAXNUMBER];
	for (i = 0; i<PartitionNum; i++)
	{
		//初始化结构体
		best[i].partitionSize = FreePartition[i];
		best[i].id = i;
	}

	for (i = 0; i<ProcessNum; i++)
	{
		for (int s = PartitionNum - 1; s > 0; s--)   //冒泡排序(每次分配完一个进程后，都需要重新排序)
		{
			for (int t = 0; t < s; t++)
			{
				if (best[s].partitionSize < best[t].partitionSize)
				{
					temp = best[s].partitionSize;
					best[s].partitionSize = best[t].partitionSize;
					best[t].partitionSize = temp;

					tempID = best[s].id;
					best[s].id = best[t].id;
					best[t].id = tempID;
				}
			}
		}

		for (j = 0; j<PartitionNum; j++)
		{
			if (LeftProcessNeed[i] <= best[j].partitionSize)
			{
				best[j].partitionSize -= LeftProcessNeed[i];
				LeftProcessNeed[i] = 0;

				NameProcessToPartition[i][best[j].id] = ProcessName[i];
				break;
			}
		}
		LeftFreePartition[best[j].id] = best[j].partitionSize;
	}

	display();
}

void WorstFit()
{
	cout << "***********最坏适应算法***********" << endl;
	initial();
	int i, j, s, t, tempSize, tempID;
	sortNeed Worst[MAXNUMBER];

	for (i = 0; i<PartitionNum; i++)
	{
		Worst[i].partitionSize = FreePartition[i];
		Worst[i].id = i;
	}

	for (i = 0; i<ProcessNum; i++)
	{
		for (s = PartitionNum - 1; s>0; s--)
		{
			for (t = 0; t<s; t++)
			{
				if (Worst[s].partitionSize > Worst[t].partitionSize)
				{
					tempSize = Worst[s].partitionSize;
					Worst[s].partitionSize = Worst[t].partitionSize;
					Worst[t].partitionSize = tempSize;

					tempID = Worst[s].id;
					Worst[s].id = Worst[t].id;
					Worst[t].id = tempID;
				}
			}
		}

		for (j = 0; j<PartitionNum; j++)
		{
			if (LeftProcessNeed[i] <= Worst[j].partitionSize)
			{
				Worst[j].partitionSize -= LeftProcessNeed[i];
				LeftProcessNeed[j] = 0;

				NameProcessToPartition[i][Worst[j].id] = ProcessName[i];
				break;
			}
		}
		LeftFreePartition[Worst[j].id] = Worst[j].partitionSize;
	}

	display();

}

void selectAlgorithm(int chooseAlgorithm)
{
	switch (chooseAlgorithm)
	{
	case 0:break;
	case 1:FirstFit(); break;
	case 2:NextFit(); break;
	case 3:BestFit(); break;
	case 4:WorstFit(); break;
	default:cout << "请输入正确的序号：" << endl;
	}
}

void display()
{
	int i;
	cout << "需要分配内存的进程名：" << setw(10);
	for (i = 0; i<ProcessNum; i++)
	{
		cout << ProcessName[i] << setw(6);
	}
	cout << endl;
	cout << "需要分配内存的进程分区大小：" << setw(4);
	for (i = 0; i<ProcessNum; i++)
	{
		cout << ProcessNeed[i] << setw(6);
	}
	cout << endl;
	cout << "分配结果：" << endl;

	cout << "分区序号:";
	for (i = 0; i<PartitionNum; i++)
	{
		cout << "分区" << i + 1 << " ";
	}
	cout << endl << "分区大小:";
	for (i = 0; i<PartitionNum; i++)
	{
		cout << FreePartition[i] << "     ";
	}
	cout << endl << "剩余大小:";
	for (i = 0; i<PartitionNum; i++)
	{
		cout << LeftFreePartition[i] << "     ";
	}
	cout << endl << "分配进程情况:" << endl;
	for (i = 0; i<PartitionNum; i++)
	{
		for (int j = 0; j<ProcessNum; j++)
		{
			if (NameProcessToPartition[j][i] != NULL)
			{
				cout << NameProcessToPartition[j][i] << ": (分区" << i + 1 << ")" << endl;
			}
		}
		//cout<<"  ";
	}
	cout << endl << "********结束**********" << endl;
}

int main()
{
	input();
	system("pause");
	return 0;
}