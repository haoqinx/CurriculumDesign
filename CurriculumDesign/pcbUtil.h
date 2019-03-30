#pragma once
#define MAX_NAME_LENGTH 20
#define MAX_PROCESS_PRIORITY 30
#include"list.h"
typedef enum {
	SCHEDULER_RUNNING = 1,
	SCHEDULER_STOP = 0
}SCHEDULER_STATUS;
typedef enum {
	BLOCKING = 0,
	SUSPEND,
	RUNNING,
	READY,
	DELETED
}PCB_STATUS;

//����һ������ֵΪ�յĺ���ָ�� 
//�����������̺���
typedef void(*ProcessFunction_t)(void*);

typedef struct PCB_ADDRESSofMEMORY {
	void* start;
	unsigned int length;

}PCB_ADDRESSofMEMORY;

typedef struct ProcessControllBlock {
	volatile PCB_ADDRESSofMEMORY stackAddress;
	//ָ��ĸ��б���
	ListItem hostItem;
	//��������ʱ��
	clock_t runTime;
	//��������
	char* PCBname[MAX_NAME_LENGTH];
	//�������ȼ�
	unsigned int processPriority;
	//����״̬
	PCB_STATUS status;
	//����id
	unsigned int IDofPCB;
	//���̺���
	ProcessFunction_t function;
	//�����ڶ�ջ�е�λ��
	int stackPosition;
}PCB;


typedef PCB PCB_t;
//���ڴ����Ľ���
PCB_t* volatile CurrentPCB_pointer;

//ȫ�־����б�
ProcessList ProcessReadyList[MAX_PROCESS_PRIORITY];
//ȫ�������б�
ProcessList ProcessBlockingList[MAX_PROCESS_PRIORITY];
//ȫ��ɾ���б�
ProcessList ProcessDeleteList[MAX_PROCESS_PRIORITY];


//ϵͳ�ؼ���¼
//���еĽ�������
volatile unsigned int CurrentProcessNumer;
//������ȼ��Ľ���
volatile unsigned int TopPriorityReadyProcess;
//����������״̬
SCHEDULER_STATUS schdulerStatus;
