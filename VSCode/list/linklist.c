// ===================================================/ 
// 线性链表，功能模块：
// 1、正序、倒序构造链表
// 2、插入删除
// 3、合并两个有序表
// ===================================================
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
    Node *next;
};
// 结构体函数============================================
// 倒序构造链表===========================================
void ListStructureDscending(Node *list,int n){
    list->next=NULL;
    printf("请输入表中元素\n");
    for(int i=0;i<n;i++){
        Node *temp=(Node *)malloc(sizeof(Node));
        if(!temp){
            printf("空间分配失败\n");
            exit(0);
        }
        scanf("%d",&temp->data);
        temp->next=list->next;
        list->next=temp;
    }
}
// 正序生成链表===========================================
void ListStructureAscending(Node *list,int n){
    printf("请依次输入数据\n");
    list->next=NULL;
    Node *cur=list;//游标指向头结点
    list->next=cur;
    int i=0;
    while(i<n){
        Node *temp=(Node *)malloc(sizeof(Node));
        temp->next=NULL;
        if(!temp){
            printf("空间分配失败\n");
            exit(0);
        }
        if(!temp)exit(0);
        scanf("%d",&(temp->data));
        cur->next=temp;
        cur=cur->next;
        i++;
    }
}
// 输出链表元素===========================================
void ListDisplay(Node list){
    // todo
    Node *cur=&list;
    while(cur->next){
        printf("%d\n",cur->next->data);
        cur=cur->next;
    }
}
// 插入删除===============================================
void ListInsert(Node *list,int location,int elem){
    // todo
    Node *cur=list;
    int counter=1;
    while(cur->next&&counter<location){
        cur=cur->next;
        counter++;
    }
    if(counter<location||!cur){
        printf("位置不存在，在末尾插入\n");
    }
    Node *temp=(Node *)malloc(sizeof(Node));
    temp->next=cur->next;
    temp->data=elem;
    cur->next=temp;
}
int ListDelete(Node *list,int location){
    // todo;
    int elem;
    Node *cur=list,*del=NULL;
    int counter=0;
    while(cur->next&&counter<location-1){
        del=cur;
        cur=cur->next;
        counter++;
    }
    del=cur->next;
    cur->next=del->next;
    elem=del->data;
    free(del);
    printf("删除结果\n");
    ListDisplay(*list);
    return elem;
}
// 合并两个有序链表=======================================
Node *ListMergeList(Node *list1,Node list2){
    Node *cur=list1,*l1=list1->next,*l2=(&list2)->next;
    while(l1&&l2){
        
        if (l1->data<=l2->data) {
            cur->next=l1;
            cur=l1;
            l1=l1->next;
        }
        else {
            cur->next=l2;
            cur=l2;
            l2=l2->next;
        }
        
    }
    if (l1) {
        cur->next=l1;
    }
    else {
        cur->next=l2;
    }
    free(l2);
    return list1;
}
// 结构体函数=============================================
// 公用函数
void fun(){
    int tag=0;
    int location,elem;
    Node list;
    while(true){
        printf("0 退出 1 构造 2 输出 3 插入 4 删除 5 合并有序表\n");
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
                int n=0;
                printf("表1\n长度\n");
                Node list1;
                scanf("%d",&n);
                ListStructureAscending(&list1,n);
                printf("表2\n长度\n");
                scanf("%d",&n);
                Node list2;
                ListStructureAscending(&list2,n);
                ListMergeList(&list1,list2);
                printf("合并完成,结果如下\n");
                ListDisplay(list1);
                break;
            }
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