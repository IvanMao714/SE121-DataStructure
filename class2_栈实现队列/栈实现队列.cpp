#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct {
    int* stk;
    int stkSize;
    int stkCapacity;
} Stack;//����ջ 

Stack* stackCreate(int cpacity) {
    Stack* ret = (Stack*)malloc(sizeof(Stack));
    ret->stk = (int*)malloc(sizeof(int) * cpacity);
    ret->stkSize = 0;
    ret->stkCapacity = cpacity;
    return ret;
}//����ջ�ĺ��� 

void stackPush(Stack* obj, int x) {
    obj->stk[obj->stkSize++] = x;
}//��ջ�ռ���� 

void stackPop(Stack* obj) {
    obj->stkSize--;
}//ջ�ռ���-1

int stackTop(Stack* obj) {
    return obj->stk[obj->stkSize - 1];
}//���ϱߵ������ 

bool stackEmpty(Stack* obj) {
    return obj->stkSize == 0;
}//�Ƿ�Ϊ�� 

typedef struct {
    Stack* inStack;
    Stack* outStack;
} Queue;//���ж��� ����ջ��� 

Queue* QueueCreate() {
    Queue* ret = (Queue*)malloc(sizeof(Queue));
    ret->inStack = stackCreate(100);
    ret->outStack = stackCreate(100);
    return ret; //���ɡ����� �� 
}

void in2out(Queue* obj) {
    while (!stackEmpty(obj->inStack)) {
        stackPush(obj->outStack, stackTop(obj->inStack));
        stackPop(obj->inStack);
    }//��һ��ջ������˳��浽��һ�� 
}

void QueuePush(Queue* obj, int x) {
    stackPush(obj->inStack, x);
}// ���д��� 

int QueuePop(Queue* obj) {
    if (stackEmpty(obj->outStack)) {
        in2out(obj);
    }
    int x = stackTop(obj->outStack);
    stackPop(obj->outStack);
    return x;
}//���г����ϱߵ��� 


int main() {
    Queue* test = QueueCreate();
    int input = 0;
    int num = 0;
    printf("�������ֵ��-1Ϊ�˳���\n");
    while (input != -1) {
        scanf("%d", &input);
        QueuePush(test, input);
        num++;
    }
    printf("���ֵΪ\n");
    while(num-1) {
    	printf("%d\n", QueuePop(test));
    	num--;
    }

    return 0;
}
