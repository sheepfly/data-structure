// 代码说明

#include<stdio.h>
#include<stdlib.h>
#define INIT 5
#define INIT2 10
#define INIT3 100
#define INCREMENT 10
typedef struct structName{
    // elemtype elemname;
};
// 这里写函数

// 函数结束
// 子函数
void fun(){
    int tag,elem,num;
    // todo
    while(true){
        printf("0 退出 \n");
        scanf("%d",&tag);
        switch(tag){
            case 0:exit(0);break;
            case 1:{
                // todo
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
