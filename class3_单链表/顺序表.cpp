#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define TRUE 1
#define FLASE 0
#define OK 1
#define OVERFOLW -2

typedef int Status;
typedef int Elemtype;

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef struct{
	ElemType *elem;
	int length;
	int listsize;
}SqList; 

Status InitList_Sq(SqList &L){
	L.elem = (Elemtype *)malloc(sizeof(Elemtype));
	if(!L.elem){
		printf("the process failed!");
		exit(OVERFLOW);
	}
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	printf("the empty list was created sucessfully!");
	return OK;
}

Status ValueList_Sq(SqList &L){
	int i;
	
	printf("How many list you want to create?");
	scanf("%d", &i);
	if(i > L.listsize) {
		while(1){
			if(i > L.listsize){
				L.elem =(ElemType *)realloc(L.elem, LISTINCREMENT * sizeof(ElemType));
				L.listsize += LISTINCREMENT;
			}
			else
			break;
		}
	}
	
	for(j=0; j<i; j++){
		printf("please enter the no. %d element!");
		scanf("%d", &L.elem[j]);	
	}
	L.length = i;
	printf("Ok");
	return OK;
	
} 

Status DistoryList_Sq(SqList &L){
	if(!L.elem){
		printf("the Sq_ist haven't been creat!");
		return ERROR;
	}
	free(L.elem);
	L.elem = NULL;
	L.length = 0;
	L.listsize = 0;
	printf("the Sq_list has been destroyed!");
	return OK; 
}

Status ClearList_Sq(SqList &L){
	if(L.elem){
		L.length = 0;
		printf("the Sq_list has been reset!");
		return OK;
	}
	else
	printf("the Sq_list hadn't been created");
	return OK;
}

Status ListEmpty_Sq(SqList L){
	if(L.elem){
		if(L.length != 0){
			printf("the Sq_list isn't empty");
			return FLASE;
		}
		else{
			printf("the Sq_list is empty");
			return TURE;
		}
	}
	else{
		printf("the Sq_list hadn't been created");
		return OK;
	}
}

Status ListLength_Sq(SqList L){
	if(L.length != 0){
		int k;
		k = L.length;
		printf("the length of list is %d", k);
		return OK;
	}
	else{
		printf("the Sq_list hadn't been created");
		return OK;
	}
}

//��ȡ���Ա�ĳһλ�ö�Ӧ��Ԫ��
Status GetElem_Sq(SqList L,int index){
	int Num;
	if(index <= 0 || index > L.length){              //���Ҫ��ȡԪ�ص�λ���Ƿ���� 
		printf("������һ����Ч������\n");
		return ERROR;
	}
	else
	Num = L.elem[index - 1];
	printf("��%d��λ�õ�Ԫ��Ϊ��%d\n",index,Num);
	return OK;
} 

//�����Ա�ĳһλ�ò���Ԫ��
Status ListInsert_Sq(SqList &L,int i,ElemType e){
	ElemType *newbase;
	int *q,*p; 
	if(i < 1 || i > L.length+1)         //�жϲ���λ�õ�indexֵ�Ƿ�Ϸ�      
	    return ERROR; 
	if(L.length >= L.listsize){         //�����ǰ���Ա�洢�ռ����������ӷ��� 
		newbase = (ElemType *)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
		if(!newbase)  {                 //����洢�ռ����ʧ�ܣ���ִ���쳣�˳� 
			printf("�洢�ռ����ʧ��\n");
			exit(OVERFLOW);
		}
		L.elem = newbase;               //�µĴ洢�ռ��ַ	
		L.listsize += LISTINCREMENT; 
	}
	q = &(L.elem[i-1]);                 //L.elem[index-1]Ϊ�����е����һ��Ԫ�أ�qΪҪ�����λ�� 
	for(p = &(L.elem[L.length - 1]);p >= q;--p)
	    *(p+1) = *p;                    //Ҫ����λ���Լ�֮���λ������� 
	*q = e;                             //��e���뵽��Ҫ�����λ�� 
	++L.length;                         //�����µ�Ԫ��֮�����1 
	printf("Ԫ�ز���ɹ�\n");
	return OK;
}

//ɾ�����Ա�ĳһλ�õ�Ԫ��
Status DeleteList_Sq(SqList &L,int i){
	int *p,*q;
	if(i < 1 || i > L.length){            //���Ҫɾ����λ�ò��Ϸ�
		printf("������һ����Ч����\n"); 
		return ERROR;
	} 
	p = &(L.elem[i - 1]);                 //pΪ��ɾ��Ԫ�ص�λ��
	q = L.elem + L.length - 1;            //����βԪ�ص�λ�ø�ֵ��q
	for(++p;p <= q;p++)
	    *(p - 1) = *p;                    //��ɾ����Ԫ��֮���Ԫ��ȫ������ 
	--L.length;                           //����1 
	printf("��%d��Ԫ��ɾ���ɹ�\n",i);
	return OK;
}

//��ӡ���Ա�
Status PrintList_Sq(SqList L){
	printf("��ǰ���Ա��Ԫ��Ϊ��");
	for(int K = 0;K < L.length;K++)      //������ǰ���Ա� 
	    printf("  %d",L.elem[K]);
	printf("\n");                        //���� 
	return OK;
} 

