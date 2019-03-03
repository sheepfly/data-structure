// 线性表，实现功能：
// 1、构造新表
// 2、插入:两种实现，用指针和不用指针
// 3、删除：两种实现，用指针和不用指针
// 4、查找，可以查找重复元素并返回，有两种实现，一种使用线性表返回
//     查找结果，一种使用数组返回查找结果
// 5、合并两个表
// 6、合并两个有序表的指针实现和非指针实现
// ==================================================================
#include<stdio.h>
#include<stdlib.h>
// #include<malloc.h>
#define OVERFLOW 0
#define MAX 100
#define MAX2 20
#define INCREMENT 10
#define MIN 10
// 结构体定义
typedef struct List{
    int length;
    int size;
    
    int *location;
};
// ====================================================================
// 成员函数
// ====================================================================
// 返回指定位置的值
int ListGet(List list,int location){
    int length=list.length;
    int elem=0;
    int *p=list.location;
    if(location>list.length||location<=0){
        printf("参数错误\n");
    }
    else{
        for(int i=0;i<location;i++){
            if(i==(location-1)){
                elem=*p;
            }
            p++;
        }
    }
    return elem;
}
// ====================================================================
// 构造线性表
void ListStruct(List *L){
    int m,length;
    printf("请输入线性表长度\n");
    scanf("%d",&length);
    if(length>=L->size){
        int *newAddress=(int *)realloc(L->location,sizeof(int)*(L->size+INCREMENT));
        if(newAddress!=(L->location)){
            L->location=newAddress;
            L->size=L->size+INCREMENT;
        }
    }
    L->length=length;
    printf("请输入线性表中的元素\n");
    for(int i=0;i<length;i++){
        scanf("%d",&(L->location[i]));
    }
}
// ====================================================================
// 输出线性表元素
void ListDisplay(List L){
    for(int i=0;i<L.length;i++){
        printf("%d\n",(L.location[i]));
    }
}
// ====================================================================
// 初始化线性表
void  ListInit(List *L){
    L->length=0;
    L->size=MIN;
    int *address=(int *)malloc(sizeof(int)*MIN);
    if(!address)printf("申请内存失败\n");
    L->location=address;
}
// ====================================================================
// 插入和删除
void ListInsert(List *list,int location,int elem){
    printf("开始插入\n");
    int length=list->length;
    // 空间不足分配空间
    if((length+1)>list->size){
        int *newAddress=(int *)realloc(list->location,sizeof(int)*(list->size+INCREMENT));
        if(newAddress!=(list->location)){
            list->location=newAddress;
        }
        list->size=list->size+INCREMENT;
    }
    int *L=list->location;
    int quantity=length-1;//标记
    for(;quantity>=location-1;quantity--){
        L[quantity+1]=L[quantity];
    }
    L[quantity+1]=elem;
    list->length++;
    printf("插入完成\n");
}
void ListInsertUsePoint(List *list,int location,int elem){
// void ListInsert(List *list,int location,int elem){
    // 空间不足分配空间
    int length=list->length;
    // =========================================================
    // 使用ListMergerList(list1,list2)时加上本段
    // if((length+1)>list->size){
    //     // 在合并有序表时，此处realloc分配地址失败，原因未知
    //     int *newAddress=(int *)realloc(list->location,sizeof(int)*(list->size+INCREMENT));
    //     if(newAddress!=(list->location)){
    //         list->location=newAddress;
    //     }
    //     list->location=newAddress;
    //     list->size=list->size+INCREMENT;
    // }
    // ==========================================================
    // 空间分配完成
    int *insert=list->location+location-1;
    int *end=list->location+length;
    for(;end>=insert;--end){
        *(end+1)=*end;
    }
    *insert=elem;
    list->length++;
    printf("插入完成\n");
}
// 删除
void ListDelete(List *list,int location){
    int i=list->length;
    int *p=list->location;
    int elem,j;
    elem=p[location-1];
    for(j=location-1;j<i;j++){
        p[j]=p[j+1];
    }
    list->length--;
    printf("删除完成\n");
    printf("删除的元素是%d\n",elem);
}
void ListDeleteUsePoint(List *list,int location){
    int elem,length=list->length;
    int *del=&(list->location[location-1]);
    int *end=list->location+length-1;
    elem=*del;
    for(++del;del<=end;++del){
        *(del-1)=*del;
    }
    list->length--;
    printf("删除完成\n");
    printf("删除的元素是%d\n",elem);
}
// ====================================================================
//查找元素
int *ListInquire(List list,int elem){
    int *address=(int *)malloc(sizeof(int)*list.length);//分配空间
    if(!address)printf("内存分配失败\n");
    int *location=address;
    int *current=list.location,*end=list.location+list.length-1;//指向线性表头和尾的指针
    int quantity=1;//查找到的数量，用于表明当前元素顺序（线性表顺序）
    // 这个函数里将i改成i后，不执行if语句体i也会+1,又好了
    int i=0;//目标数量
    *location=0;
    for(;current<=end;current++){
        if(*current==elem){
            // i=i+1;
            // i++;
            location[++i]=quantity;
            // location[i]=quantity;
            (*location)++;
        }
        quantity++;
    }
    return location;
}
// ====================================================================
// 使用线性表存储查找到的元素位置并返回该线性表
List ListInquireUseList(List list,int elem){
    List listQuantity;
    ListInit(&listQuantity);
    ListInsertUsePoint(&listQuantity,1,0);
    int *current=list.location,*end=list.location+list.length-1;//指向线性表头和尾的指针
    int quantity=1;//查找到的数量，用于表明当前元素顺序（线性表顺序）
    int i=1;//目标数量
    for(;current<=end;current++){
        if(*current==elem){
            ListInsertUsePoint(&listQuantity,++i,quantity);
        }
        quantity++;
    }
    listQuantity.location[0]=i-1;
    return listQuantity;
}
// ====================================================================
// 将b-a中的元素插入到a中
void ListUnion(List *list1,List list2){
    printf("表1\n");
    ListDisplay(*list1);
    printf("表2\n");
    ListDisplay(list2);
    printf("开始合并\n");
    int quantity=list2.length,i=0,length=list1->length;
    for(i=0;i<quantity;i++){
        int quantity=*ListInquire(*list1,list2.location[i]);
        if(!quantity){
        // if(!(*(ListInquire(*list1,list2.location[i])))){
            ListInsertUsePoint(list1,++length,list2.location[i]);
        }
    }
    printf("合并完成\n");
}
// ====================================================================
// 合并有序表
// List ListMergerList(List list1,List list2)
List ListMergerList(List list1,List list2,List list3)
{
    int length1=list1.length,length2=list2.length;
    int i,j,k=0;
    i=1;j=1;
    // ===============================================================
    // 使用ListMergerList(List list1,List list2)时加上本段
    // List list3;
    // ListInit(&list3);
    // =====================================================================
    int a[50];
    int couter=0;
    while((i<=length1)&&(j<=length2)){
        couter++;
        int elem1=ListGet(list1,i),elem2=ListGet(list2,j);
        if(elem1<=elem2){
            ListInsertUsePoint(&list3,++k,elem1);
            i++;
        }
        else{
            ListInsertUsePoint(&list3,++k,elem2);
            j++;
        }
        printf("合并后的\n");
        ListDisplay(list3);
    }
    int elem;
    while(i<=length1){
        elem=ListGet(list1,i++);
        ListInsertUsePoint(&list3,++k,elem);
    }
    while(j<=length2){
        elem=ListGet(list2,j++);
        ListInsertUsePoint(&list3,++k,elem);
    }
    return list3;
}
// 使用指针合并连个有序表
void ListMergerListUsePoint(List list1,List list2,List *list3){
    int length1=list1.length,length2=list2.length;
    list3->length=length1+length2;
    list3->size=length1;
    int length=list3->length;
    list3->location=(int *)malloc(sizeof(int)*length);
    if(!(list3->location))exit(OVERFLOW);
    int *p1=list1.location,*p2=list2.location,*p=list3->location;
    int *a=list1.location+length1-1,*b=list2.location+length2-1;
    while(p1<=a&&p2<=b){
        if(*p1<=*p2){
            *p++=*p1++;
        }
        else{
            *p++=*p2++;
        }
    }
    while(p1<=a)*p++=*p1++;
    while(p2<=b)*p++=*p2++;
    printf("合并完成\n");
}
// ====================================================================
// 增删改查，初始化，构造,合并
void fun(){
    int location,elem;
    int tag;
    while(true){
        List list;
        printf("0 退出 1 插入 2 删除 3 构造 4 查找 5 初始化 6 输出 7 查找 8 合并 9 合并两个有序表  10 指针合并有序表\n");
        scanf("%d",&tag);
        switch(tag){
            case 0:exit(0);break;
            case 1:{
                printf("输入插入元素\n");
                scanf("%d",&elem);
                printf("输入插入位置\n");
                scanf("%d",&location);
                ListInsertUsePoint(&list,location,elem);
                // ListInsert(&list,location,elem);
                break;
            }
            case 2:{
                printf("输入删除位置\n");
                scanf("%d",&location);
                ListDeleteUsePoint(&list,location);
                break;
            }
            case 3:{
                ListStruct(&list);
                break;
            }
            case 4:{
                printf("输入查找元素\n");
                scanf("%d",&elem);
                ListInquire(list,elem);
                break;
            }
            case 5:{
                printf("输入要构造的线性表\n");
                ListInit(&list);
                break;
            }
            case 6:{
                ListDisplay(list);break;
            }
            case 7:{
                // 查找有两个实现，一个是将查找到的元素位置放在数组里返回，另一个是放在线性表中返回
                printf("输入查询目标\n");
                scanf("%d",&elem);
                List objectLocation=ListInquireUseList(list,elem);
                if(objectLocation.location[0]==0){
                    printf("查找失败\n");
                }
                else{
                    printf("查找成功\n");
                    printf("数量，位置\n");
                    ListDisplay(objectLocation);
                }
                // =============================================================
                // int *elemLocation=ListInquire(list,elem);
                // printf("查询完成，位置：\n");
                // if(*elemLocation==0){
                //     printf("查找失败，目标表中没有此元素\n");
                // }
                // else{
                //     int *p=elemLocation;
                //     printf("查找成功，目标位置\n");
                //     // 移动指针输出元素
                //     for(int i=0;i<*elemLocation;i++){
                //         printf("%d\n",*(++elemLocation));
                //     }
                //     // 使用下标访问元素
                //     for(int i=0;i<*elemLocation;){
                //         printf("%d\n",elemLocation[++i]);
                //     }
                // }
                // ==============================================================
            }
            case 8:{
                List list1,list2;
                printf("输入list1\n");
                ListInit(&list1);
                ListStruct(&list1);
                printf("输入list2\n");
                ListInit(&list2);
                ListStruct(&list2);
                ListUnion(&list1,list2);
                ListDisplay(list1);
                break;
            }
            case 9:{
                printf("请输入两个有序表\n");
                List list1,list2;
                printf("表1\n");
                ListInit(&list1);
                ListStruct(&list1);
                printf("表2\n");
                ListInit(&list2);
                ListStruct(&list2);
                printf("表1\n");
                ListDisplay(list1);
                printf("表2\n");
                ListDisplay(list2);
                // ====================================================================
                // 传入list1,list2合并到list3,list3初始化不调用Listinit()函数
                int length=list1.length+list2.length;
                List list3;
                list3.size=length;
                list3.length=length;
                list3.location=(int *)malloc(sizeof(int)*length);
                ListMergerList(list1,list2,list3);
                // =====================================================================
                // 传入两个有序表，返回合并后的有序表
                // List list3=ListMergerList(list1,list2);
                // =====================================================================
                printf("合并后的表\n");
                ListDisplay(list3);
                break;
            }
            case 10:{
                printf("请输入两个有序表\n");
                List list1,list2;
                printf("表1\n");
                ListInit(&list1);
                ListStruct(&list1);
                printf("表2\n");
                ListInit(&list2);
                ListStruct(&list2);
                printf("表1\n");
                ListDisplay(list1);
                printf("表2\n");
                ListDisplay(list2);
                List list3;
                ListMergerListUsePoint(list1,list2,&list3);
                ListDisplay(list3);
                break;
            }
            default:printf("welcome\n");
        }
    }
}
// ====================================================================
// 主函数
int main(int argc, char const *argv[])
{
    fun();
    system("pause");
    return 0;
}