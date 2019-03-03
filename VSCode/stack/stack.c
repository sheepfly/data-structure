// 顺序栈
// 1、进出栈
// 2、返回栈顶元素
// 3、构造，输出
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
        printf("%d\n",*s.base++);
    }
}
// 主函数
void fun(){
    int tag;
    Stack stack;
    stackInit(stack);
    // todo
    while(true){
        printf("0 退出 1 入栈 2 退栈 3 输出 4 返回栈顶\n");
        scanf("%d",&tag);
        switch(tag){
            case 0:exit(0);break;
            case 1:{
                int elem,num;
                printf("输入元素个数\n");
                scanf("%d",&num);
                printf("请输入元素\n");
                for(int i=0;i<num;i++){
                    scanf("%d",&elem);
                    Push(elem,stack);
                }
                break;
            }
            case 2:{
                int elem;
                elem=Pop(stack);
                printf("删除的元素是%d\n",elem);
                break;
            }
            case 3:{
                stackDisplsy(stack);
                break;
            }
            case 4:{
                printf("栈顶元素是%d\n",getTop(stack));
            }
            default:printf("welcome\n");
        }
    }
}
// =======================================================

// main函数===============================================
main(int argc, char const *argv[])
{
    /* code */
    fun();
    return 0;
}
