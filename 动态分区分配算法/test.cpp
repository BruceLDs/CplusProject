////#define  _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<vector>
//using namespace std;
//void menu(vector<int> a);
//typedef struct PcbNode{
//	int val;
//	bool state;//falseΪ���У�trueΪ�ѷ���
//}PNode;
////����Ϊ����������Ϊ����
//void FreeSpace(vector<int> a){
//	cout << a.front();
//	vector<int>::iterator cur = a.begin();
//	for (; cur != a.end(); cur++)
//		cout << *cur << endl;
//}
//
////�״���Ӧ�㷨FF
//void FirstFit(vector<PNode> p, vector<int> a){
//	cout << "�״���Ӧ�㷨" << endl;
//	for (int i =0; i < a.size(); i++){   //��������
//		vector<int>::iterator j = a.begin(); 
//		//ÿ�δӷ������׵�ַ��ʼ����
//		for (int j = 0;  j < p.size();  j++){  
//			//��ϵͳ�ڴ�����㹻���ʱ�򣬼������������Դ
//			if (a[i] > 0 && p[j].state == false && p[j].val > a[i]){
//				int temp = p[j].val - a[i];
//				p[j].val = a[i];
//				if (j + 1 != p.size())
//					p[j + 1].val += temp;
//				p.push_back()
//			}
//
//			 //���ڴ�����㹻��ִ�У���ǰ���̴�С��0
//			  //�洢�����������ڵķ���λ��
//				break;   //һ�����̷����������������һ�����̵��ж�
//		}
//	}
//	menu(p);
//}
////
//////ѭ���״���Ӧ�㷨NF
////void NextFit(){
////	cout << "NF" << endl;
////	int i, j, nextPoint = 0;
////	bool isWhile;
////	for (i = 0; i<ProcessNum; i++){
////		isWhile = true;
////		while (isWhile){     //ÿ�ζ��ӵ�ǰ��������һ��������ʼ����
////			if (LeftFreePartition[nextPoint] >= LeftProcessNeed[i]){
////				LeftFreePartition[nextPoint] -= LeftProcessNeed[i];
////				LeftProcessNeed[i] = 0;
////				NameProcessToPartition[i][nextPoint] = ProcessName[i];
////				nextPoint++;
////				if (nextPoint > PartitionNum - 1){
////					nextPoint = 0;  //��j����������ĩβ��ʱ�򣬷�����λ��
////				}
////				isWhile = false;
////			}
////			else{
////				nextPoint++;
////				if (nextPoint > PartitionNum - 1){
////					nextPoint = 0;  //��j����������ĩβ��ʱ�򣬷�����λ��
////				}
////				j++;
////				if (j >= PartitionNum){//������ѭ��
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
//////�����Ӧ�㷨BF
////void BestFit(){
////	//�Է�����С��������,ÿ�η�����һ�����̵��ڴ��С����������
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
////		//ð������(ÿ�η�����һ�����̺󣬶���Ҫ��������)
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
//////���Ӧ�㷨WF
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
//	cout << "*******1.�״���Ӧ�㷨      *********" << endl;
//	cout << "*******2.ѭ���״���Ӧ�㷨********" << endl;
//	cout << "*******3.�����Ӧ�㷨      *********" << endl;
//	cout << "*******4.���Ӧ�㷨      *********" << endl;
//	cout << "**********************************" << endl;
//	cin >> k;
//		switch (k){
//		case 1:FirstFit(p, a);
//			FreeSpace(p); break;
//		/*case 2:NF(a, arr); FreeSpace(a); break;
//		case 3:BF(a, arr); FreeSpace(a); break;
//		case 4:WF(a, arr); FreeSpace(a); break;*/
//		default:cout << "�˳�ϵͳ��" << endl; break;
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
static int PartitionNum;  //�ڴ��п��з����ĸ���
static int ProcessNum; //��Ҫ����Ľ��̸���
static int FreePartition[MAXNUMBER];  //���з�����Ӧ���ڴ�
static int ProcessNeed[MAXNUMBER];  //��Ҫ����Ľ��̴�С

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
	cout << "��ѡ��ʵ�ֵ��㷨��" << endl;
	cout << "*****  1 - �״���Ӧ�㷨     *****" << endl;
	cout << "*****  2 - ѭ���״���Ӧ�㷨 *****" << endl;
	cout << "*****  3 - �����Ӧ�㷨     *****" << endl;
	cout << "*****  4 - ���Ӧ�㷨     *****" << endl;
	cout << "*****  0 - ����             *****" << endl;
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
	readDataFunction();   //��ȡԭʼ����
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
	cout << "***********�״���Ӧ�㷨***********" << endl;
	initial();

	int i, j;
	for (i = 0; i<ProcessNum; i++)   //�������ÿ������
	{
		for (j = 0; j<PartitionNum; j++)
		{
			if (LeftProcessNeed[i] <= LeftFreePartition[j] && LeftFreePartition != 0)  //��ϵͳ�ڴ�����㹻���ʱ�򣬼������������Դ
			{
				LeftFreePartition[j] -= LeftProcessNeed[i];   //�۳���������̵���Դ
				LeftProcessNeed[i] = 0;  //���ҽ���ϵͳ�ڴ�����㹻ʱ��ִ�У�����ǰ���̴�С��0

				NameProcessToPartition[i][j] = ProcessName[i];  //�洢�����������ڵķ���λ��

				break;   //!!!����Ҫ��һ�����̷������Ӧ������break��������һ�����̵��ж�
			}
		}
	}

	display();

}

void NextFit()
{
	cout << "***********ѭ���״���Ӧ�㷨***********" << endl;
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
					nextPoint = 0;  //��j����������ĩβ��ʱ�򣬷�����λ��
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
	//˼�룺����ð������Է�����С�������򣬵����ı�ԭ������λ��
	//����һ���ṹ�壬����������С������Ӧ��id����������У�ÿ�ı�˳��һ�Σ�id���Ÿı�
	//�ؼ���ÿ�η�����һ�����̵��ڴ��С�󣬶�Ҫ��������
	cout << "***********�����Ӧ�㷨***********" << endl;
	initial();
	int i, j, temp, tempID;

	sortNeed best[MAXNUMBER];
	for (i = 0; i<PartitionNum; i++)
	{
		//��ʼ���ṹ��
		best[i].partitionSize = FreePartition[i];
		best[i].id = i;
	}

	for (i = 0; i<ProcessNum; i++)
	{
		for (int s = PartitionNum - 1; s > 0; s--)   //ð������(ÿ�η�����һ�����̺󣬶���Ҫ��������)
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
	cout << "***********���Ӧ�㷨***********" << endl;
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
	default:cout << "��������ȷ����ţ�" << endl;
	}
}

void display()
{
	int i;
	cout << "��Ҫ�����ڴ�Ľ�������" << setw(10);
	for (i = 0; i<ProcessNum; i++)
	{
		cout << ProcessName[i] << setw(6);
	}
	cout << endl;
	cout << "��Ҫ�����ڴ�Ľ��̷�����С��" << setw(4);
	for (i = 0; i<ProcessNum; i++)
	{
		cout << ProcessNeed[i] << setw(6);
	}
	cout << endl;
	cout << "��������" << endl;

	cout << "�������:";
	for (i = 0; i<PartitionNum; i++)
	{
		cout << "����" << i + 1 << " ";
	}
	cout << endl << "������С:";
	for (i = 0; i<PartitionNum; i++)
	{
		cout << FreePartition[i] << "     ";
	}
	cout << endl << "ʣ���С:";
	for (i = 0; i<PartitionNum; i++)
	{
		cout << LeftFreePartition[i] << "     ";
	}
	cout << endl << "����������:" << endl;
	for (i = 0; i<PartitionNum; i++)
	{
		for (int j = 0; j<ProcessNum; j++)
		{
			if (NameProcessToPartition[j][i] != NULL)
			{
				cout << NameProcessToPartition[j][i] << ": (����" << i + 1 << ")" << endl;
			}
		}
		//cout<<"  ";
	}
	cout << endl << "********����**********" << endl;
}

int main()
{
	input();
	system("pause");
	return 0;
}