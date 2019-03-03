// 队列的顺序存储表示，即循环对老爹
// 1、出入队
// 2、输出队列中的元素
#include<stdio.h>
#include<stdlib.h>
#define INIT 5
#define INIT2 10
#define INIT3 100
#define INCREMENT 10
typedef struct Quene{
    int *base;
    int head,tail;//队头和队尾
};
// 这里写函数
// 初始化队列
int queneLength(Quene quene){
    return (quene.tail-quene.head+INIT3)%INIT3;
}
void queneInit(Quene &quene){
    quene.base=(int *)malloc(sizeof(int)*INIT3);
    if(!quene.base){
        printf("queneInit()空间分配失败，退出程序\n");
        system("pause");
        exit(0);
    }
    quene.head=quene.tail=0;//头指针和尾指针相同
}
// 输出队列中的元素，由队头开始
void queneDisplay(Quene quene){
    if(quene.tail==quene.head){
        printf("空队列\n");
        return;
    }
    int num=queneLength(quene);
    for(int i=0;i<num;i++){
        printf("%d\n",quene.base[(quene.head+i+INIT3)%INIT3]);
    }
}
// 出入队
void queneInsert(Quene &quene,int elem){
    if((quene.tail+1)%INIT3==quene.head){
        printf("队列已满\n");
        return;
    }
    quene.base[quene.tail]=elem;
    quene.tail=(quene.tail+1)%INIT3;
}
int queneDelete(Quene &quene){
    int elem;
    if(quene.tail==quene.head){
        printf("空队列\n");
        return 0;
    }
    elem=quene.base[quene.head];
    quene.head=(quene.head+1)%INIT3;
    return elem;
}
// 清空
void queneEmpty(Quene &quene){
    quene.tail=quene.head;
}
// 返回队列长度
// 函数结束
// 子函数
void fun(){
    int tag,elem,num;
    Quene quene;
    queneInit(quene);
    // todo
    while(true){
        printf("0 退出 1 入队 2 出队 3 输出 4 入队多个元素 5 清空\n");
        scanf("%d",&tag);
        switch(tag){
            case 0:exit(0);break;
            case 1:{
                printf("请输入元素\n");
                scanf("%d",&elem);
                queneInsert(quene,elem);
                printf("入队完成\n");
                break;
            }
            case 2:{
                elem=queneDelete(quene);
                printf("出队如下%d\n",elem);
                break;
            }
            case 3:{
                printf("开始输出\n");
                queneDisplay(quene);
                printf("输出完成\n");
                break;
            }
            case 4:{
                printf("输出元素数量\n");
                scanf("%d",&num);
                printf("输入元素\n");
                for(int i=0;i<num;i++){
                    scanf("%d",&elem);
                    queneInsert(quene,elem);
                }
                printf("入队完成\n");
                break;
            }
            case 5:{
                printf("开始清空\n");
                queneEmpty(quene);
                printf("清空完成\n");
                break;
            }
            default:printf("welcome\n");
        }
    }
}
// 子函数fun()结束
// main函数===============================================
main(int argc, char const *argv[])
{
    /* code */
    fun();
    return 0;
}
