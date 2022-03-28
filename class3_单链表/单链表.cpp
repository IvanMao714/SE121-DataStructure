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
	//创建头结点
	pHead = (PNode) malloc(sizeof(Node));
	if(pHead == NULL){
		printf("内存分配失败，程序终止！\n");
		exit(-1);//结束程序
	}
	//头结点初始指针域为NULL
	pHead->next = NULL;
	for(i = 0;i < len;i++){
		//创建新结点
		pNew = (PNode) malloc(sizeof(Node));
		if(pNew == NULL){
			printf("内存分配失败，程序终止！\n");
			exit(-1);//结束程序
		}
		//保存结点数据
		pNew->data = a[i];
		//头插法插入结点
		pNew->next = pHead->next;
		pHead->next = pNew;
	}
	return pHead;//返回头结点
}

