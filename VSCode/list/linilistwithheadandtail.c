// =====================================================
// 带头尾结点的双向链表
// 功能模块
// 1、插入删除
// 2、顺序构造
// 3、输出
// 4、查找，分精确查找（查找所有位置）和模糊查找（第一个位置）
// =====================================================
#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<stdlib.h>
#define INIT 0
#define MAX 100
#define MAX2 20
#define INCREMENT 10
#define MIN 10

// 结构体定义
typedef struct Node{
    // 输入结构体定义
    int data;
    Node *next,*prior;
};
typedef struct List{
    int length;
    Node *head,*tail;
};
// 结构体函数============================================
// 倒序构造链表===========================================
// void ListStructureDscending(Node *list,int n){
//     list->next=NULL;
//     printf("请输入表中元素\n");
//     for(int i=0;i<n;i++){
//         Node *temp=(Node *)malloc(sizeof(Node));
//         if(!temp){
//             printf("空间分配失败\n");
//             exit(0);
//         }
//         scanf("%d",&temp->data);
//         temp->next=list->next;
//         list->next=temp;
//     }
// }
// 正序生成链表===========================================
void ListStructureAscending(List *list,int n){
    printf("请依次输入数据\n");
    list->length=n;
    // 定义指向头结点和尾结点的指针
    Node *head=list->head;
    Node *tail=list->tail;
    Node *cur=head;//游标指向头结点
    int i=0;
    while(i<n){
        Node *temp=(Node *)malloc(sizeof(Node));
        temp->next=NULL;
        temp->prior=NULL;
        if(!temp){
            printf("空间分配失败\n");
            exit(0);
        }
        scanf("%d",&(temp->data));
        temp->next=head;//尾结点的后继指向头结点
        temp->prior=cur;//尾结点的前驱指向当前结点(cur)，首次进入循环时指向头结点
        tail=temp;//尾指针指向尾结点temp
        cur->next=temp;//当前结点的后继指向temp
        head->prior=temp;//头结点的前驱指向尾结点temp
        cur=cur->next;//游标指向下一个结点（刚刚插入的结点）
        i++;
    }
}
// 输出链表元素===========================================
void ListDisplay(List list){
    Node *cur=list.head->next;
    for(int i=0;i<list.length;i++){
        printf("%d\n",cur->data);
        cur=cur->next;
    }
}
// 插入删除===============================================
void ListInsert(List *list,int location,int elem){
    // todo
    // 指向头结点和尾结点的指针
    Node *head=list->head,*tail=list->tail,*cur=list->head;
    // 寻找插入位置，cur指向插入位置的前驱结点
    int counter=1;
    // 当counter小于插入位置时,counter++
    while(counter<location&&counter<=list->length){
        cur=cur->next;
        counter++;
    }
    // counter小于location时说明线性表长度小于插入位置,插入位置不存在
    if(counter<location||!cur){
        printf("位置不存在，在末尾插入\n");
    }
    Node *temp=(Node *)malloc(sizeof(Node));
    temp->data=elem;
    temp->next=cur->next;//temp的后继指向当前结点的后继
    temp->prior=cur;//temp的前驱指向当前结点
    cur->next=temp;//当前结点的后继指向temp
    temp->next->prior=temp;//temp后继的前驱指向temp
    if (location>list->length) {//在末尾插入时，尾指针指向刚插入的结点
        tail=temp;
    }
    list->length++;
}
int ListDelete(List *list,int location){
    // todo;
    int elem;
    Node *cur=list->head,*del=NULL;
    int counter=0;
    // 寻找删除位置
    while(cur->next&&counter<location-1){
        del=cur;
        cur=cur->next;
        counter++;
    }
    // 删除结点
    del=cur->next;
    cur->next=del->next;
    del->next->prior=cur;
    // 删除最后一个结点是指针指向尾结点的前驱
    if (location>list->length) {
        list->tail=cur;
    }
    elem=del->data;
    free(del);
    list->length--;
    printf("删除结果\n");
    ListDisplay(*list);
    return elem;
}
// 合并两个有序链表=======================================
// Node *ListMergeList(Node *list1,Node list2){
//     Node *cur=list1,*l1=list1->next,*l2=(&list2)->next;
//     while(l1&&l2){
        
//         if (l1->data<=l2->data) {
//             cur->next=l1;
//             cur=l1;
//             l1=l1->next;
//         }
//         else {
//             cur->next=l2;
//             cur=l2;
//             l2=l2->next;
//         }
        
//     }
//     if (l1) {
//         cur->next=l1;
//     }
//     else {
//         cur->next=l2;
//     }
//     free(l2);
//     return list1;
// }
// 初始化链表=============================================
void ListInit(List *list){
    list->length=0;
    Node *temp=(Node *)malloc(sizeof(Node));
    if(!temp){
        printf("内存分配失败\n");
        exit(0);
    }
    // 头指针和尾指针指向刚刚分配的结点
    list->head=temp;
    list->tail=temp;
    // 初始化temp的前驱和后继，都只想temp
    temp->next=temp;
    temp->prior=temp;
}
// 查找，通过参数accura控制精确查找还是查找首次出现位置
// accurate为true时，返回所有查找到的位置，否则只返回第一个位置
List ListInquire(List list,int elem,int accurate){
    List temp;//声明要返回的线性表
    ListInit(&temp);//初始化要返回的线性表
    Node *cur=list.head;
    cur=cur->next;
    int counter=1,location=1;
    for(;counter<=list.length;counter++){
        if(cur->data==elem){
            ListInsert(&temp,location++,counter);
            if(!accurate)break;
        }
        cur=cur->next;
    }
    return temp;
}
// 定位传入的参数位置，分别使用链表和数组返回。
// 结构体函数end=============================================
// 公用函数==================================================
void fun(){
    int tag=0;
    int location,elem;
    List list;
    ListInit(&list);
    while(true){
        printf("0 退出 1 构造 2 输出 3 插入 4 删除 5 查找 6 合并有序表 \n");
        scanf("%d",&tag);
        // tag=1;
        switch(tag){
            case 0:exit(0);break;
            case 1:{
                printf("输入元素个数\n");
                int n;
                scanf("%d",&n);
                ListStructureAscending(&list,n);//正序构造
                // ListStructureDscending(&list,n);//倒序构造
                printf("构造完成\n");
                break;
            }
            case 2:{
                printf("表中元素如下：\n");
                ListDisplay(list);
                printf("输出完成\n");
                break;
            }
            case 3:{
                printf("插入位置\n");
                scanf("%d",&location);
                printf("插入元素\n");
                scanf("%d",&elem);
                ListInsert(&list,location,elem);
                printf("插入完成\n");
                ListDisplay(list);
                break;
            }
            case 4:{
                printf("输入删除位置\n");
                scanf("%d",&location);
                ListDelete(&list,location);
                break;
            }
            case 5:{
                int accurate;
                printf("输入查找元素\n");
                scanf("%d",&elem);
                printf("是否查找所有 %d 出现的位置？\n",elem);
                printf("1 是 0 否\n");
                scanf("%d",&accurate);
                List temp=ListInquire(list,elem,accurate);
                printf("%d 出现的位置如下\n");
                ListDisplay(temp);
                break;
            }
            // case 5:{
            //     int n=0;
            //     printf("表1\n长度\n");
            //     Node list1;
            //     scanf("%d",&n);
            //     ListStructureAscending(&list1,n);
            //     printf("表2\n长度\n");
            //     scanf("%d",&n);
            //     Node list2;
            //     ListStructureAscending(&list2,n);
            //     ListMergeList(&list1,list2);
            //     printf("合并完成,结果如下\n");
            //     ListDisplay(list1);
            //     break;
            // }
            default:printf("welcome\n");
        }
    }
}
// main()函数============================================
int  main(int argc, char const *argv[])
{
    /* code */
    fun();
    getchar();
    return 0;
}