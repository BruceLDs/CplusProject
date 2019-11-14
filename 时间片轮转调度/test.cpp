#define  _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
using namespace std;
typedef struct pcb {
	string pName;//������
	struct pcb *next;//ָ����һ������
	float arriveTime;//����ʱ��
	float serviceTime;//����ʱ��
	float estimatedRunningtime;//��������ʱ��
	float startTime;//��ʼʱ��
	float finishTime;//���ʱ��
	float turnaroundTime;//��תʱ��
	float weightedTuraroundTime;//��Ȩ��תʱ��
	char state;//���̵�״̬
}PCB;

void createProcess(PCB *p, int n) {//����n�����̣���ͷ���
	cout << endl << "��������" << endl;
	PCB *q = p;//����ָ���ǰһ�����ָ��
	PCB *r = new PCB;//����ָ��
	for (int i = 0; i<n; i++) {
		cout << "�������" << i + 1 << "�����̵����֡�����ʱ�䡢����ʱ��(����:A 12 8):";
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

void sortOfArriveTime(PCB *p, int n) {//������ҵ���ȶԽ�������
	PCB *t = new PCB;
	PCB *q = new PCB;
	PCB *m = new PCB;
	for (int i = 0; i < n - 1; i++) {//ð��ѭ��
		q = p->next;//qָ�������еĵ�һ������
		for (int j = 0; j<n - i - 1; j++) {
			m = q->next;
			if (q->serviceTime > m->serviceTime) {//�����Ϣ���н���
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

void runProcess(PCB *p, int n) {//���н���
	PCB *q = new PCB;
	PCB *m = new PCB;
	PCB *s = new PCB;
	int a = n;
	sortOfArriveTime(p, n);
	q = p;
	m = p->next;
	int currentTime = 0;//��ǰʱ��
	int i = 0;
	int number = 0;
	while (true) {
		currentTime++;
		if (i == 0 && m->arriveTime>currentTime)//�״����н���
			continue;
		number = 0;
		while (m&&m->state == 'C' || m&&m->arriveTime>currentTime) {//Ѱ��Ӧ�÷��ʵĽ���
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
		if (number>n)//���н��̶����ܽ��з���
			continue;
		cout << "�������еĽ���" << endl;
		cout << "��ǰʱ��:" << currentTime << endl;
		cout << "������\t����ʱ�� ����ʱ�� ������ʱ�� ��ʣ����ʱ��" << endl;//�����ǰ�������еĽ���
		cout << m->pName << "\t" << m->arriveTime << "\t " << m->serviceTime << "\t  ";
		cout << m->serviceTime - m->estimatedRunningtime << "\t     " << m->estimatedRunningtime << endl;
		m->estimatedRunningtime--;
		m->finishTime = currentTime + 1;
		if (m->estimatedRunningtime == 0)
			m->state = 'C';
		cout << "����" << m->pName << "ִ��һ��֮����������еĽ���" << endl;
		cout << "������\t����ʱ�� ����ʱ�� ������ʱ�� ��ʣ����ʱ��" << endl;
		s = p->next;
		while (s) {//�����������
			if (s->estimatedRunningtime != 0) {
				cout << s->pName << "\t" << s->arriveTime << "\t " << s->serviceTime << "\t  ";
				cout << s->serviceTime - s->estimatedRunningtime << "\t     " << s->estimatedRunningtime << endl;
			}
			s = s->next;
		}
		cout << endl << endl << endl;
		q = m;
		m = m->next;//q��mָ�����
		if (m == NULL) {//�ص�����ͷ��
			q = p;
			m = p->next;
		}
		s = p->next;
		while (s&&s->state == 'C')
			s = s->next;
		if (s == NULL)//�����н�������ɣ����˳�ѭ��
			break;
		i++;
	}
	q = p;
	m = p->next;
	for (int i = 0; i<n; i++) {//���㿪ʼʱ�䡢��תʱ�䡢��Ȩ��תʱ��
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

void printProcess(PCB *p) {//������н��̵���Ϣ
	PCB *q = p->next;
	cout << endl << "���н���������ɺ���̵������Ϣ" << endl;
	cout << "������\t����ʱ�� ����ʱ�� ��ʼʱ�� ���ʱ�� ��תʱ�� ��Ȩ��תʱ��" << endl;
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
	cout << "��������̵ĸ���:";
	cin >> n;
	createProcess(p, n);//�������� 
	runProcess(p, n);//���н��� 
	printProcess(p);//������� 
	return 0;
}