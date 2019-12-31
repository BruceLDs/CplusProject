#include <iostream>
#include <iomanip>
using namespace std;
#define MaxNumber 6
#if 0
static int n;//������
static int m;//��Դ������
static int Available[MaxNumber];//��������Դ
static int Max[MaxNumber];//�����Դ����
static int Allocation[MaxNumber][MaxNumber];//�ɷ�����Դ
static int Need[MaxNumber][MaxNumber];
#endif
static int Request[MaxNumber];//������Դ����
static int SafeOrder[MaxNumber];//��ȫ����
static bool Finish[MaxNumber];//ÿ�����̵�Finish״̬
static char sourceName[] = { 'A', 'B', 'C', 'D', 'E', 'F'};	  //��Դ����
/*
��1����¼����涯̬¼�����������Դ��������������Դ������t0ʱ�̸����̵�������������ѷ���������Ϣ��
��2�����㷨ѡ����棬�ܹ����а�ȫ�Լ�⡢�Խ��̶�̬������Դ�����м��㷨��顢�˳��ȵĹ���ѡ��Ҫ����Խ��ж���̶�ε���Դ����
��3����������棬Ҫ���ܹ������ȫ�Լ��Ľ�����簲ȫ�ܹ������ȫ���С��ܹ��������������Դ���Ƿ����Ľ���������ܷ���Ҫ���ԭ������ܹ����䣬Ҫ����������̼���Դ��״̬��
*/
//0 :1 0 0  0
#if 1
static int n = 5;//������
static int m = 4;//��Դ������
static int Available[MaxNumber] = { 1, 6, 2, 2};//��������Դ
static int Max[MaxNumber] = {3, 12, 14, 14};//�����Դ����
static int Allocation[MaxNumber][MaxNumber] = {
	{ 0, 0, 3, 2 },
	{ 1, 0, 0, 0 },
	{ 1, 3,  5, 4},
	{ 0 ,3, 3, 2 },
	{ 0, 0, 1, 4 }
};//�ɷ�����Դ
static int Need[MaxNumber][MaxNumber] = {
	{ 0, 0, 1, 2 },
	{ 1, 7, 5, 0 },
	{ 2, 3, 5, 6 },
	{ 0, 6, 5, 2 },
	{ 0, 6, 5, 6 }
};
#endif
void getData(){
	cout << "�������������";
	cin >> n;
	cout << endl;
	cout << "��������Դ��������";
	cin >> m;
	cout << endl;
	cout << "�����������Դ����" << endl;
	for (int i = 0; i < m; i++)
		cin >> Max[i];
	cout << "�������ѷ�����Դ����" << endl;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> Allocation[i][j];
		}
	}
	cout << "������������Դ����" << endl;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> Need[i][j];
		}
	}
	cout << "�������������Դ����" << endl;
	for (int i = 0; i < m; i++)
		cin >> Available[i];
}
void outData(){
	char processName[] = { '1', '2', '3', '4', '5', '6' };
	cout << "----------------------------------------------------------------------" << endl;
	cout << "��ǰ���̸���Ϊ n = " << n << endl;
	cout << "��ǰ��Դ����Ϊ m = " << m << endl;
	cout << "ϵͳ�����Դ��������£�" << endl;
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
	cout << "ϵͳ��������Դ��������£�" << endl;
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

	cout << "ϵͳ�ѷ��������Դ��������£�" << endl;
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
	cout << "ϵͳ������Դ��������£�" << endl;
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
	int FinishNumebr = 0;//��ȫ��������
	int i = 0;
	int isSafe = 0;
	while (i < n)
	{
		isSafe = 0;//������־
		if (Finish[i] == false){
		for (int j = 0; j < m; j++)
				{
					if (Need[i][j] <= work[j])
						isSafe++;
					else
						break;
				}
		}
		
		if (isSafe == m)  //���ҽ������̶�Ӧ��������Դ�������������ʱ��ų���
		{	
			for (int j = 0; j < m; j++)
				work[j] += Allocation[i][j];
			cout << "��P" << i << " : " << endl;
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
		cout << "��Ӧ�İ�ȫ����Ϊ��" << endl;
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
	cout << "������������Դ�������ͣ���0��1��2����" << endl;
	cin >> ptype;
	cout << "������������Դ��" << endl;
	for (int i = 0; i < m; i++)
		cin >> Request[i];
	for (int i = 0; i < m; i++){
		if (Request[i] > Available[i]){
			cout << "������Դ���ڿ�������Դ,����ʧ�ܣ�" << endl;
			return;
		}
	}
	for (int i = 0; i < m; i++){
	Allocation[ptype][i] += Request[i];
	Available[i] -= Request[i];
	}
	if (isSystemSafe()){
		cout << "����ɹ����ɵõ����ϰ�ȫ���У�" << endl;
	}
	else{
		cout << "����ʧ�ܣ��Ҳ����䰲ȫ���У�" << endl;
	}
}
void menu(){
	cout << "*********************************" << endl;
	cout << "******1. ��ȡ������Ϣ************" << endl;
	cout << "******2. ���������Ϣ      ********" << endl;
	cout << "******3. Ѱ�Ұ�ȫ���а�ȫ********" << endl;
	cout << "******4. ����������Դ      ********" << endl;
	cout << "******0. �˳�ϵͳ            ********" << endl;
	cout << "*********************************" << endl;
	int k;
	cin >> k;
	switch (k)
	{
	case 1:getData();//��ȡ����
		menu(); break;
	case 2:outData();//�������
	menu(); break;
	case 3:isSystemSafe();
	menu(); break;
	case 4:Apply();
	menu(); break;
	default:cout << "�˳�ϵͳ" << endl;
		break;
	}
}
int main()
{
	menu();
	return 0;
}

