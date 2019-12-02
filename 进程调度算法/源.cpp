#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
 class pcb {
 public:
	 pcb(string name = "a", float arriveTime = 1, float serviceTime = 3)
		 :
		 _name(name),
		_arriveTime(arriveTime),
		_serviceTime(serviceTime), 
		_startTime(0),
		 _finishTime(0),
		 _turnaroundTime(0),
		 _weightedTuraroundTime(0),
		 _state(false)
	 {
	 }
	 string _name;//������
	float _arriveTime;//����ʱ��
	float _serviceTime;//����ʱ��
	float _startTime;//��ʼʱ��
	float _finishTime;//���ʱ��
	float _turnaroundTime;//��תʱ��
	float _weightedTuraroundTime;//��Ȩ��תʱ��
	bool _state;//���̵�״̬
};
 void F_sort(vector<pcb> a){
		 //�ж��Ƿ�����
		 int i = 0;
		 int j = 0;
		 int n = a.size();
		 for (; i < n; i++)
		 {
			 for (j = i; j < n; j++)
			 {
				 if (a[i]._arriveTime >= a[j]._arriveTime)
					 swap(a[i]._arriveTime, a[j]._arriveTime);
					 swap(a[i]._finishTime, a[j]._finishTime);
					 swap(a[i]._name, a[j]._name);
					 swap(a[i]._serviceTime, a[j]._serviceTime);
					 swap(a[i]._startTime, a[j]._startTime);
					 swap(a[i]._turnaroundTime, a[j]._turnaroundTime);
					 swap(a[i]._weightedTuraroundTime, a[j]._weightedTuraroundTime);
					 swap(a[i]._state, a[j]._state);
			 }
		 }
}
 void S_sort(vector<pcb> a){
	 //�ж��Ƿ�����
	 int i = 0;
	 int j = 0;
	 int n = a.size();
	 for (; i < n; i++)
	 {
		 for (j = i; j < n; j++)
		 {
			 if (a[i]._serviceTime >= a[j]._serviceTime)
				 swap(a[i]._arriveTime, a[j]._arriveTime);
			 swap(a[i]._finishTime, a[j]._finishTime);
			 swap(a[i]._name, a[j]._name);
			 swap(a[i]._serviceTime, a[j]._serviceTime);
			 swap(a[i]._startTime, a[j]._startTime);
			 swap(a[i]._turnaroundTime, a[j]._turnaroundTime);
			 swap(a[i]._weightedTuraroundTime, a[j]._weightedTuraroundTime);
			 swap(a[i]._state, a[j]._state);
		 }
	 }
 }
 void FCFS(vector<pcb> p , float k = 0){//�ȵ��ȷ���
	 F_sort(p);
	 for (int i = 0; i < p.size(); i++){
		 p[i]._startTime = p[i]._arriveTime + k;
		 p[i]._finishTime = p[i]._startTime + p[i]._serviceTime;
		 p[i]._state = true;
		 p[i]._turnaroundTime = p[i]._finishTime - p[i]._arriveTime;
		 p[i]._weightedTuraroundTime = p[i]._turnaroundTime / p[i]._serviceTime;
		 cout << p[i]._name << "����CPU��" << endl;
		 cout << "��������	����ʱ��	����ʱ��	��ʼʱ��	����ʱ��	��תʱ��	��Ȩ��תʱ��		����״̬" << endl;
		 cout << p[i]._name << "		" << p[i]._arriveTime << "			" << p[i]._serviceTime << "		" << p[i]._startTime << "	" << p[i]._finishTime << "			" << p[i]._turnaroundTime << "		" << p[i]._weightedTuraroundTime << "		" << p[i]._state << endl;
		 k += p[i]._finishTime;
	 }
 }
 void RR(vector<pcb> p, int k = 0){//ʱ��Ƭ��ת
	 int i = 0;
	 int s = 0;
	 while(1){
		 p[i]._startTime = p[i]._arriveTime + k;
		 p[i]._finishTime = p[i]._startTime + p[i]._serviceTime;
		 p[i]._state = true;
		 p[i]._turnaroundTime = p[i]._finishTime - p[i]._arriveTime;
		 p[i]._weightedTuraroundTime = p[i]._turnaroundTime / p[i]._serviceTime;
		 cout << p[i]._name << "����CPU��" << endl;
		 cout << "��������\t����ʱ��	\t����ʱ��\t��ʼʱ��\t����ʱ��\t��תʱ��\t��Ȩ��תʱ��\t����״̬" << endl;
		 cout << p[i]._name << "\t" << p[i]._arriveTime << "\t" << p[i]._serviceTime << "\t" << p[i]._startTime << "	\t" << p[i]._finishTime << "\t" << p[i]._turnaroundTime << "\t" << p[i]._weightedTuraroundTime << "\t" << p[i]._state << endl;
		 k += p[i]._finishTime;
		 i++;
		 if (i == p.size())
			 i = 0;
	 }
 }
 void SJF(vector<pcb> p, int k = 0){//����ҵ����
	 S_sort(p);
	 for (int i = 0; i < p.size(); i++){
		 p[i]._startTime = p[i]._arriveTime + k;
		 p[i]._finishTime = p[i]._startTime + p[i]._serviceTime;
		 p[i]._state = true;
		 p[i]._turnaroundTime = p[i]._finishTime - p[i]._arriveTime;
		 p[i]._weightedTuraroundTime = p[i]._turnaroundTime / p[i]._serviceTime;
		 cout << p[i]._name << "����CPU��" << endl;
		 cout << "��������	����ʱ��	����ʱ��	��ʼʱ��	����ʱ��	��תʱ��	��Ȩ��תʱ��		����״̬" << endl;
		 cout << p[i]._name << "		" << p[i]._arriveTime << "			" << p[i]._serviceTime << "		" << p[i]._startTime << "	" << p[i]._finishTime << "			" << p[i]._turnaroundTime << "		" << p[i]._weightedTuraroundTime << "		" << p[i]._state << endl;
		 k += p[i]._finishTime;
	 }
 }
 void PRT(vector<pcb> p, int k =0){//���ȼ�����
	 for (int i = 0; i < p.size(); i++){
		 p[i]._startTime = p[i]._arriveTime + k;
		 p[i]._finishTime = p[i]._startTime + p[i]._serviceTime;
		 p[i]._state = true;
		 p[i]._turnaroundTime = p[i]._finishTime - p[i]._arriveTime;
		 p[i]._weightedTuraroundTime = p[i]._turnaroundTime / p[i]._serviceTime;
		 cout << p[i]._name << "����CPU��" << endl;
		 cout << "��������	����ʱ��	����ʱ��	��ʼʱ��	����ʱ��	��תʱ��	��Ȩ��תʱ��		����״̬" << endl;
		 cout << p[i]._name << "		" << p[i]._arriveTime << "			" << p[i]._serviceTime << "		" << p[i]._startTime << "	" << p[i]._finishTime << "			" << p[i]._turnaroundTime << "		" << p[i]._weightedTuraroundTime << "		" << p[i]._state << endl;
		 k += p[i]._finishTime;
	 }
 }
 void menu(vector<pcb> p){
	 cout << "***********************" << endl;
	 cout << "***********************" << endl;
	 cout << "*******1.FCFS  ********" << endl;
	 cout << "*******2.RR     ********" << endl;
	 cout << "*******3.SJF    ********" << endl;
	 cout << "*******4.PR     ********" << endl;
	 cout << "*******0.exit    ********" << endl;
	 cout << "***********************" << endl;
	 cout << "***********************" << endl;
	 int n;
	 float k = 0;
	 cin >> n;
		 switch (n){
		 case 1:FCFS(p, k); break;
		 case 2:RR(p, 0); break;
		 case 3:SJF(p, 0); break;
		 case 4:PRT(p, 0); break;
		 default:break;
		 }
 }
 void test(){
	 vector<pcb> p;
	 int n = 0;
	 cout << "��������̵ĸ���" << endl;
	 cin >> n;
	 p.resize(n);
	 for (int i = 0; i < n; i++){
		 string name;
		 float arriveTime;
		 float serviceTime;
		 cout << "�����������������ʱ�䡢����ʱ�䣨��ʽ a 1 3��" << endl;
		 cin >> name >> arriveTime >> serviceTime;
		 pcb s(name, arriveTime, serviceTime);
		 p[i] = s;
	 }
	 menu(p);
 }
 int main(){
	 test();
	return 0;
}