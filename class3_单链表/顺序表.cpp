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

//获取线性表某一位置对应的元素
Status GetElem_Sq(SqList L,int index){
	int Num;
	if(index <= 0 || index > L.length){              //如果要获取元素的位置是否出界 
		printf("请输入一个有效的数字\n");
		return ERROR;
	}
	else
	Num = L.elem[index - 1];
	printf("第%d个位置的元素为：%d\n",index,Num);
	return OK;
} 

//在线性表某一位置插入元素
Status ListInsert_Sq(SqList &L,int i,ElemType e){
	ElemType *newbase;
	int *q,*p; 
	if(i < 1 || i > L.length+1)         //判断插入位置的index值是否合法      
	    return ERROR; 
	if(L.length >= L.listsize){         //如果当前线性表存储空间已满，增加分配 
		newbase = (ElemType *)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
		if(!newbase)  {                 //如果存储空间分配失败，则执行异常退出 
			printf("存储空间分配失败\n");
			exit(OVERFLOW);
		}
		L.elem = newbase;               //新的存储空间基址	
		L.listsize += LISTINCREMENT; 
	}
	q = &(L.elem[i-1]);                 //L.elem[index-1]为数组中的最后一个元素，q为要插入的位置 
	for(p = &(L.elem[L.length - 1]);p >= q;--p)
	    *(p+1) = *p;                    //要插入位置以及之后的位置向后移 
	*q = e;                             //将e插入到想要插入的位置 
	++L.length;                         //插入新的元素之后表长加1 
	printf("元素插入成功\n");
	return OK;
}

//删除线性表某一位置的元素
Status DeleteList_Sq(SqList &L,int i){
	int *p,*q;
	if(i < 1 || i > L.length){            //如果要删除的位置不合法
		printf("请输入一个有效数字\n"); 
		return ERROR;
	} 
	p = &(L.elem[i - 1]);                 //p为被删除元素的位置
	q = L.elem + L.length - 1;            //将表尾元素的位置赋值给q
	for(++p;p <= q;p++)
	    *(p - 1) = *p;                    //被删除的元素之后的元素全部左移 
	--L.length;                           //表长减1 
	printf("第%d个元素删除成功\n",i);
	return OK;
}

//打印线性表
Status PrintList_Sq(SqList L){
	printf("当前线性表的元素为：");
	for(int K = 0;K < L.length;K++)      //遍历当前线性表 
	    printf("  %d",L.elem[K]);
	printf("\n");                        //换行 
	return OK;
} 

