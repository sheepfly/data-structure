// 队列
// 1、出入队
// 2、输出队列元素，从队头到队尾
// 3、
#include<stdio.h>
#include<stdlib.h>
#define INIT 5
#define INIT2 10
#define INIT3 100
#define INCREMENT 10
typedef struct Node{//结点
    int data;
    Node *next;//指向下一个结点
};
typedef struct Quene{//队列
    // 定义头尾指针
    Node *head;
    Node *tail;
};
// 这里写函数
// 输出队列中的元素，从队头开始
void QueneDisplay(Quene quene){
    Node *current=quene.head->next;
    //循环结束时输出了了队尾前一个元素
    while(current!=quene.tail){
        printf("%d\n",current->data);
        if(current->next)current=current->next;
    }
    // 输出队尾元素
    printf("%d\n",current->data);
}
// 初始化
void QueneInit(Quene &quene){
    // 初始化后头尾指针指向头结点，头结点不存放数据
    Node *temp=(Node *)malloc(sizeof(Node));
    if(!temp){
        exit(0);
        printf("queneInit空间分配失败退出程序\n");
        system("pause");    
    }
    quene.head=quene.tail=temp;
}
// 入队
void QueneInsert(int elem,Quene &quene){
    // todo
    Node *temp=(Node *)malloc(sizeof(Node));
    if(!temp){
        exit(0);
        printf("queneInsert空间分配失败退出程序\n");
        system("pause");
    }
    temp->data=elem;
    temp->next=NULL;
    quene.tail->next=temp;
    quene.tail=temp;
}
// 出队
int QueneDelete(Quene &quene){
    // todo
    Node *del=quene.head->next;//取头结点（队头)
    quene.head->next=del->next;//头指针指向头结点的下一个结点
    return del->data;//返回删除的元素
    free(del);//释放队头结点
}
// 返回队头队尾
int QueneHead(Quene quene){
    return quene.head->next->data;
}
int QueneTail(Quene quene){
    return quene.tail->data;
}
// 清空和销毁
void QueneEmpty(Quene &quene){
    // todo
}
void QueneDestroy(Quene &quene){
    // todo
}
// 函数结束
// 子函数
void fun(){
    int tag;
    Quene quene;
    QueneInit(quene);
    int elem;
    // todo
    while(true){
        printf("0 退出 1 入队 2 出队 3 输出 4 输入多个\n");
        scanf("%d",&tag);
        switch(tag){
            case 0:exit(0);break;
            case 1:{
                // todo
                printf("请输入要入队的元素\n");
                scanf("%d",&elem);
                QueneInsert(elem,quene);
                printf("入队完成\n");
                break;
            }
            case 2:{
                int delElem=QueneDelete(quene);
                printf("出队元素是%d\n",delElem);
                break;
            }
            case 3:{
                QueneDisplay(quene);
                printf("输出完成\n");
                break;
            }
            case 4:{
                printf("输入元素个数\n");
                int num;
                scanf("%d",&num);
                printf("输入所有元素\n");
                for(int i=0;i<num;i++){
                    scanf("%d",&elem);
                    QueneInsert(elem,quene);
                }
                printf("所有元素输入完成\n");
                break;
            }
            default:printf("参数错误，请重新输入welcome\n");
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
