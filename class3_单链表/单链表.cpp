#include <stdio.h> 
#include <stdlib.h>
typedef struct Node{
	int data;
	struct Node *next;
}Node, *PNode;

//Initialization
PNode init_list(){
	PNode pHead = (PNode) malloc(sizeof(Node));
	return pHead;
} 

PNode create_listH(int *a,int len){
	PNode pHead,pNew;
	int i;
	//����ͷ���
	pHead = (PNode) malloc(sizeof(Node));
	if(pHead == NULL){
		printf("�ڴ����ʧ�ܣ�������ֹ��\n");
		exit(-1);//��������
	}
	//ͷ����ʼָ����ΪNULL
	pHead->next = NULL;
	for(i = 0;i < len;i++){
		//�����½��
		pNew = (PNode) malloc(sizeof(Node));
		if(pNew == NULL){
			printf("�ڴ����ʧ�ܣ�������ֹ��\n");
			exit(-1);//��������
		}
		//����������
		pNew->data = a[i];
		//ͷ�巨������
		pNew->next = pHead->next;
		pHead->next = pNew;
	}
	return pHead;//����ͷ���
}

