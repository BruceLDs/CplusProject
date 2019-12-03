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
	 string _name;//进程名
	float _arriveTime;//到达时间
	float _serviceTime;//服务时间
	float _startTime;//开始时间
	float _finishTime;//完成时间
	float _turnaroundTime;//周转时间
	float _weightedTuraroundTime;//带权周转时间
	bool _state;//进程的状态
};
 void print(vector<pcb> p){
	 cout << "进程名称	到达时间	服务时间	开始时间	结束时间	周转时间	带权周转时间		进程状态" << endl;
	 for (auto& e : p)
		 cout << e._name << "		" <<e._arriveTime << "			" << e._serviceTime << "		" << e._startTime << "	" << e._finishTime << "			" << e._turnaroundTime << "		" << e._weightedTuraroundTime << "		" << e._state << endl;
 }
 void F_sort(vector<pcb> a){
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
 void FCFS(vector<pcb> p , float k = 0){//先到先服务
	 F_sort(p);
	 for (int i = 0; i < p.size(); i++){
		 p[i]._startTime = p[i]._arriveTime + k;
		 p[i]._finishTime = p[i]._startTime + p[i]._serviceTime;
		 p[i]._state = true;
		 p[i]._turnaroundTime = p[i]._finishTime - p[i]._arriveTime;
		 p[i]._weightedTuraroundTime = p[i]._turnaroundTime / p[i]._serviceTime;
		 cout << p[i]._name << "正在CPU中" << endl;
		 cout << "进程名称	到达时间	服务时间	开始时间	结束时间	周转时间	带权周转时间		进程状态" << endl;
		 cout << p[i]._name << "		" << p[i]._arriveTime << "			" << p[i]._serviceTime << "		" << p[i]._startTime << "	" << p[i]._finishTime << "			" << p[i]._turnaroundTime << "		" << p[i]._weightedTuraroundTime << "		" << p[i]._state << endl;
		 k += p[i]._finishTime;
	 }
	 print(p);
 }
 void RR(vector<pcb> p, int k = 0){//时间片轮转
	 int i = 0;
	 int s = 0;
	 int n = 0;
	 for (auto& e : p){
	 s += e._serviceTime;
	 n++;
	 }
	 vector<int> arr;
	 arr.resize(n, 0);
	 s += p[i]._arriveTime;
	 p[0]._startTime = p[0]._arriveTime;
	 while(i < s){
		 if(i > 0)
		 if (arr[i] != p[i]._serviceTime){
			 p[i]._startTime = p[i - 1]._finishTime;
			 p[i]._finishTime = p[i]._startTime + 1;
			 p[i]._state = true;
			 p[i]._turnaroundTime = p[i]._finishTime - p[i]._arriveTime;
			 p[i]._weightedTuraroundTime = p[i]._turnaroundTime / p[i]._serviceTime;
			 cout << p[i]._name << "正在CPU中" << endl;
			 cout << "进程名称\t到达时间	\t服务时间\t开始时间\t结束时间\t周转时间\t带权周转时间\t进程状态" << endl;
			 cout << p[i]._name << "\t" << p[i]._arriveTime << "\t" << p[i]._serviceTime << "\t" << p[i]._startTime << "	\t" << p[i]._finishTime << "\t" << p[i]._turnaroundTime << "\t" << p[i]._weightedTuraroundTime << "\t" << p[i]._state << endl;
			 k += p[i]._finishTime;
			 p[i]._state = false;
			 arr[i]++;
			 i++;
		 }
		 else{
			 i++;
		 }
	 }
	 print(p);
 }
 void SJF(vector<pcb> p, int k = 0){//短作业优先
	 S_sort(p);
	 for (int i = 0; i < p.size(); i++){
		 p[i]._startTime = p[i]._arriveTime + k;
		 p[i]._finishTime = p[i]._startTime + p[i]._serviceTime;
		 p[i]._state = true;
		 p[i]._turnaroundTime = p[i]._finishTime - p[i]._arriveTime;
		 p[i]._weightedTuraroundTime = p[i]._turnaroundTime / p[i]._serviceTime;
		 cout << p[i]._name << "正在CPU中" << endl;
		 cout << "进程名称	到达时间	服务时间	开始时间	结束时间	周转时间	带权周转时间		进程状态" << endl;
		 cout << p[i]._name << "		" << p[i]._arriveTime << "			" << p[i]._serviceTime << "		" << p[i]._startTime << "	" << p[i]._finishTime << "			" << p[i]._turnaroundTime << "		" << p[i]._weightedTuraroundTime << "		" << p[i]._state << endl;
		 k += p[i]._finishTime;
	 }
	 print(p);
 }
 void PRT(vector<pcb> p, int k =0){//优先级调度
	 for (int i = 0; i < p.size(); i++){
		 p[i]._startTime = p[i]._arriveTime + k;
		 p[i]._finishTime = p[i]._startTime + p[i]._serviceTime;
		 p[i]._state = true;
		 p[i]._turnaroundTime = p[i]._finishTime - p[i]._arriveTime;
		 p[i]._weightedTuraroundTime = p[i]._turnaroundTime / p[i]._serviceTime;
		 cout << p[i]._name << "正在CPU中" << endl;
		 cout << "进程名称	到达时间	服务时间	开始时间	结束时间	周转时间	带权周转时间		进程状态" << endl;
		 cout << p[i]._name << "		" << p[i]._arriveTime << "			" << p[i]._serviceTime << "		" << p[i]._startTime << "	" << p[i]._finishTime << "			" << p[i]._turnaroundTime << "		" << p[i]._weightedTuraroundTime << "		" << p[i]._state << endl;
		 k += p[i]._finishTime;
	 }
	 print(p);
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
	 while (1){
		 cin >> n;
		 switch (n){
		 case 1:FCFS(p, k); break;
		 case 2:RR(p, 0); break;
		 case 3:SJF(p, 0); break;
		 case 4:PRT(p, 0); break;
		 default:break;
		 }
	 }
 }
 void test(){
	 vector<pcb> p;
	 int n = 0;
	 cout << "请输入进程的个数" << endl;
	 cin >> n;
	 p.resize(n);
	 for (int i = 0; i < n; i++){
		 string name;
		 float arriveTime;
		 float serviceTime;
		 cout << "请输入进程名、到达时间、服务时间（格式 a 1 3）" << endl;
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