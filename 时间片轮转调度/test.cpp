#define  _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
using namespace std;
typedef struct pcb {
	string pName;//进程名
	struct pcb *next;//指向下一个进程
	float arriveTime;//到达时间
	float serviceTime;//服务时间
	float estimatedRunningtime;//估计运行时间
	float startTime;//开始时间
	float finishTime;//完成时间
	float turnaroundTime;//周转时间
	float weightedTuraroundTime;//带权周转时间
	char state;//进程的状态
}PCB;

void createProcess(PCB *p, int n) {//创建n个进程，带头结点
	cout << endl << "创建进程" << endl;
	PCB *q = p;//工作指针的前一个结点指针
	PCB *r = new PCB;//工作指针
	for (int i = 0; i<n; i++) {
		cout << "请输入第" << i + 1 << "个进程的名字、到达时间、服务时间(例如:A 12 8):";
		cin >> r->pName;
		cin >> r->arriveTime;
		cin >> r->serviceTime;
		r->startTime = 0;
		r->finishTime = 0;
		r->estimatedRunningtime = r->serviceTime;
		r->turnaroundTime = 0;
		r->weightedTuraroundTime = 0;
		r->state = 'R';
		q->next = r;
		q = r;
		r->next = new PCB;
		r = r->next;
	}
	r->next = NULL;
	q->next = NULL;
	q = NULL;
	delete q;
	delete r;
	cout << endl << endl;
}

void sortOfArriveTime(PCB *p, int n) {//按短作业优先对进程排序
	PCB *t = new PCB;
	PCB *q = new PCB;
	PCB *m = new PCB;
	for (int i = 0; i < n - 1; i++) {//冒泡循环
		q = p->next;//q指向链表中的第一个进程
		for (int j = 0; j<n - i - 1; j++) {
			m = q->next;
			if (q->serviceTime > m->serviceTime) {//结点信息进行交换
				t->pName = q->pName;
				t->arriveTime = q->arriveTime;
				t->serviceTime = q->serviceTime;
				t->estimatedRunningtime = q->estimatedRunningtime;
				q->pName = m->pName;
				q->arriveTime = m->arriveTime;
				q->serviceTime = m->serviceTime;
				q->estimatedRunningtime = m->estimatedRunningtime;
				m->pName = t->pName;
				m->arriveTime = t->arriveTime;
				m->serviceTime = t->serviceTime;
				m->estimatedRunningtime = t->estimatedRunningtime;
			}
			q = q->next;
		}
	}
	t = NULL;
	m = NULL;
	q = NULL;
	delete t;
	delete m;
	delete q;
}

void runProcess(PCB *p, int n) {//运行进程
	PCB *q = new PCB;
	PCB *m = new PCB;
	PCB *s = new PCB;
	int a = n;
	sortOfArriveTime(p, n);
	q = p;
	m = p->next;
	int currentTime = 0;//当前时间
	int i = 0;
	int number = 0;
	while (true) {
		currentTime++;
		if (i == 0 && m->arriveTime>currentTime)//首次运行进程
			continue;
		number = 0;
		while (m&&m->state == 'C' || m&&m->arriveTime>currentTime) {//寻找应该访问的进程
			number++;
			q = m;
			m = m->next;
			if (m == NULL) {
				q = p;
				m = p->next;
			}
			if (number>n)
				break;
		}
		if (number>n)//所有进程都不能进行访问
			continue;
		cout << "正在运行的进程" << endl;
		cout << "当前时间:" << currentTime << endl;
		cout << "进程名\t到达时间 服务时间 已运行时间 还剩运行时间" << endl;//输出当前正在运行的进程
		cout << m->pName << "\t" << m->arriveTime << "\t " << m->serviceTime << "\t  ";
		cout << m->serviceTime - m->estimatedRunningtime << "\t     " << m->estimatedRunningtime << endl;
		m->estimatedRunningtime--;
		m->finishTime = currentTime + 1;
		if (m->estimatedRunningtime == 0)
			m->state = 'C';
		cout << "进程" << m->pName << "执行一次之后就绪队列中的进程" << endl;
		cout << "进程名\t到达时间 服务时间 已运行时间 还剩运行时间" << endl;
		s = p->next;
		while (s) {//输出就绪队列
			if (s->estimatedRunningtime != 0) {
				cout << s->pName << "\t" << s->arriveTime << "\t " << s->serviceTime << "\t  ";
				cout << s->serviceTime - s->estimatedRunningtime << "\t     " << s->estimatedRunningtime << endl;
			}
			s = s->next;
		}
		cout << endl << endl << endl;
		q = m;
		m = m->next;//q、m指针后移
		if (m == NULL) {//回到链表头部
			q = p;
			m = p->next;
		}
		s = p->next;
		while (s&&s->state == 'C')
			s = s->next;
		if (s == NULL)//若所有进程已完成，则退出循环
			break;
		i++;
	}
	q = p;
	m = p->next;
	for (int i = 0; i<n; i++) {//计算开始时间、周转时间、带权周转时间
		if (i == 0) {
			m->startTime = m->arriveTime;
			m->turnaroundTime = m->finishTime - m->arriveTime;
			m->weightedTuraroundTime = m->turnaroundTime*1.0 / m->serviceTime;
		}
		else {
			m->startTime = q->startTime + 1>m->arriveTime ? q->startTime + 1 : m->arriveTime;
			m->turnaroundTime = m->finishTime - m->arriveTime;
			m->weightedTuraroundTime = m->turnaroundTime*1.0 / m->serviceTime;
		}
		m = m->next;
	}
	q = NULL;
	m = NULL;
	s = NULL;
	delete q;
	delete m;
	delete s;
	cout << endl;
}

void printProcess(PCB *p) {//输出所有进程的信息
	PCB *q = p->next;
	cout << endl << "所有进程运行完成后进程的相关信息" << endl;
	cout << "进程名\t到达时间 服务时间 开始时间 完成时间 周转时间 带权周转时间" << endl;
	while (q) {
		cout << q->pName << "\t" << q->arriveTime << "\t " << q->serviceTime << "\t  ";
		cout << q->startTime << "\t   " << q->finishTime << "\t    " << q->turnaroundTime << "\t     " << q->weightedTuraroundTime << endl;
		q = q->next;
	}
	cout << endl << endl;
}

int main() {
	PCB *p = new PCB;
	int n;
	cout << "请输入进程的个数:";
	cin >> n;
	createProcess(p, n);//创建进程 
	runProcess(p, n);//运行进程 
	printProcess(p);//输出进程 
	return 0;
}