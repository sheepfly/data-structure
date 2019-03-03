#ifndef _STACK_H_
#define _STACK_H_
#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<stdlib.h>
#define INIT 5
#define INIT2 10
#define INIT3 100
#define INCREMENT 10

// 结构体定义
typedef struct Stack{
    int size;
    int *base,*top;
};

// 初始化
void stackInit(Stack &s){
    int *temp=(int *)malloc(sizeof(int)*INIT);
    if (!temp) {
        printf("空间分配失败，退出程序\n");
        exit(0);
    }
    s.base=temp;
    s.top=temp;
    s.size=INIT3;
}
// 入栈
void Push(int elem,Stack &s){
    // 判断空间是否足够，不够则分配空间
    if(s.top-s.base>=s.size){
        s.base=(int *)realloc(s.base,sizeof(int)*INCREMENT);
        if(!s.base){
            printf("空间分配失败\n");
            exit(0);
        }
        s.size+=INCREMENT;
    }
    *s.top++=elem;
}
// 退栈
int Pop(Stack &s){
    if(s.base==s.top)printf("error:空栈\n");
    int elem=*--s.top;
    return elem;
}
// 返回栈顶元素
int getTop(Stack s){
    return *--s.top;
}
// 输出
void stackDisplsy(Stack s){
    Stack temp=s;
    while(s.top!=s.base){
        printf("%d",*--s.top);
    }
}
void stackEmpty(Stack &s){
    s.top=s.base;
}
#endif