#include <iostream>
#include <iomanip>
using namespace std;
#define MaxNumber 6
#if 0
static int n;//进程数
static int m;//资源种类数
static int Available[MaxNumber];//可利用资源
static int Max[MaxNumber];//最大资源总数
static int Allocation[MaxNumber][MaxNumber];//可分配资源
static int Need[MaxNumber][MaxNumber];
#endif
static int Request[MaxNumber];//请求资源数组
static int SafeOrder[MaxNumber];//安全序列
static bool Finish[MaxNumber];//每个进程的Finish状态
static char sourceName[] = { 'A', 'B', 'C', 'D', 'E', 'F'};	  //资源名称
/*
（1）有录入界面动态录入进程数、资源种类数、各类资源总数、t0时刻各进程的最大需求数、已分配数等信息；
（2）有算法选择界面，能够进行安全性检测、对进程动态请求资源的银行家算法检查、退出等的功能选择，要求可以进行多进程多次的资源请求；
（3）有输出界面，要求能够输出安全性检测的结果、如安全能够输出安全序列、能够输出进程请求资源后是否分配的结果，若不能分配要输出原因，如果能够分配，要输出分配后进程及资源的状态。
*/
//0 :1 0 0  0
#if 1
static int n = 5;//进程数
static int m = 4;//资源种类数
static int Available[MaxNumber] = { 1, 6, 2, 2};//可利用资源
static int Max[MaxNumber] = {3, 12, 14, 14};//最大资源总数
static int Allocation[MaxNumber][MaxNumber] = {
	{ 0, 0, 3, 2 },
	{ 1, 0, 0, 0 },
	{ 1, 3,  5, 4},
	{ 0 ,3, 3, 2 },
	{ 0, 0, 1, 4 }
};//可分配资源
static int Need[MaxNumber][MaxNumber] = {
	{ 0, 0, 1, 2 },
	{ 1, 7, 5, 0 },
	{ 2, 3, 5, 6 },
	{ 0, 6, 5, 2 },
	{ 0, 6, 5, 6 }
};
#endif
void getData(){
	cout << "请输入进程数：";
	cin >> n;
	cout << endl;
	cout << "请输入资源种类数：";
	cin >> m;
	cout << endl;
	cout << "请输入最大资源数：" << endl;
	for (int i = 0; i < m; i++)
		cin >> Max[i];
	cout << "请输入已分配资源数：" << endl;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> Allocation[i][j];
		}
	}
	cout << "请输入需求资源数：" << endl;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> Need[i][j];
		}
	}
	cout << "请输入可利用资源数：" << endl;
	for (int i = 0; i < m; i++)
		cin >> Available[i];
}
void outData(){
	char processName[] = { '1', '2', '3', '4', '5', '6' };
	cout << "----------------------------------------------------------------------" << endl;
	cout << "当前进程个数为 n = " << n << endl;
	cout << "当前资源个数为 m = " << m << endl;
	cout << "系统最大资源数情况如下：" << endl;
	for (int i = 0; i<m; i++)
	{
		cout << setw(3) << sourceName[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < m; i++)
	{
		cout << setw(3) << Max[i] << " ";
	}
	cout << endl;
	cout << "系统可利用资源数情况如下：" << endl;
	for (int i = 0; i<m; i++)
	{
		cout << setw(3) << sourceName[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < m; i++)
	{
		cout << setw(3) << Available[i] << " ";
	}
	cout << endl;

	cout << "系统已分配分配资源数情况如下：" << endl;
	for (int i = 0; i < m; i++)
	{
		cout << setw(3) << sourceName[i];
	}
	cout << endl;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cout << setw(3) << Allocation[i][j];
		}
		cout << endl;
	}
	cout << "系统需求资源数情况如下：" << endl;
	for (int i = 0; i < m; i++)
	{
		cout << setw(3) << sourceName[i];
	}
	cout << endl;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cout << setw(3) << Need[i][j];
		}
		cout << endl;
	}
}
bool isSystemSafe()
{
	int work[MaxNumber];
	for (int i = 0; i < m; i++) 
		work[i] = Available[i];
	for (int i = 0; i < n; i++) 
		Finish[i] = false;
	int FinishNumebr = 0;//安全序列坐标
	int i = 0;
	int isSafe = 0;
	while (i < n)
	{
		isSafe = 0;//判满标志
		if (Finish[i] == false){
		for (int j = 0; j < m; j++)
				{
					if (Need[i][j] <= work[j])
						isSafe++;
					else
						break;
				}
		}
		
		if (isSafe == m)  //当且仅当进程对应的所有资源的数量都满足的时候才成立
		{	
			for (int j = 0; j < m; j++)
				work[j] += Allocation[i][j];
			cout << "找P" << i << " : " << endl;
			cout << "Work[ " << i << "] = ";
			for (int j = 0; j < m; j++)
				cout << work[j] << " , ";
			cout << endl;
			cout << "Need[ " << i << "] = " ;
			for (int j = 0; j < m; j++)
				cout << Need[i][j] << " , ";
			cout << endl;
			cout << "Finish[ " << i << " ] = true" << endl;
			Finish[i] = true;
			SafeOrder[FinishNumebr] = i;
			FinishNumebr++;
			i = -1;
		}
		i++;
	}
	for (i = 0; i < n; i++){
		if (Finish[i] == false){
			cout << "**********************************Unsafe!******************************" << endl;
			return false;
		}
	}
		cout << "**********************************Safe!******************************" << endl;
		cout << "对应的安全序列为：" << endl;
		for (int i = 0; i < n; i++)
		{
			if (i == 0)
				cout << "P" << SafeOrder[i] ;
			else
				cout << " -> P"<<  SafeOrder[i];
		}
		cout << endl;
		return true;
}
void Apply(){
	int ptype;
	cout << "请输入请求资源进程类型（例0，1，2）：" << endl;
	cin >> ptype;
	cout << "请输入请求资源：" << endl;
	for (int i = 0; i < m; i++)
		cin >> Request[i];
	for (int i = 0; i < m; i++){
		if (Request[i] > Available[i]){
			cout << "请求资源大于可利用资源,分配失败！" << endl;
			return;
		}
	}
	for (int i = 0; i < m; i++){
	Allocation[ptype][i] += Request[i];
	Available[i] -= Request[i];
	}
	if (isSystemSafe()){
		cout << "分配成功，可得到如上安全序列！" << endl;
	}
	else{
		cout << "分配失败，找不到其安全序列！" << endl;
	}
}
void menu(){
	cout << "*********************************" << endl;
	cout << "******1. 获取数据信息************" << endl;
	cout << "******2. 输出数据信息      ********" << endl;
	cout << "******3. 寻找安全序列安全********" << endl;
	cout << "******4. 进程请求资源      ********" << endl;
	cout << "******0. 退出系统            ********" << endl;
	cout << "*********************************" << endl;
	int k;
	cin >> k;
	switch (k)
	{
	case 1:getData();//获取数据
		menu(); break;
	case 2:outData();//输出数据
	menu(); break;
	case 3:isSystemSafe();
	menu(); break;
	case 4:Apply();
	menu(); break;
	default:cout << "退出系统" << endl;
		break;
	}
}
int main()
{
	menu();
	return 0;
}

