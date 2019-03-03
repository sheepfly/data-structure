#include<stdio.h>
#include"stack.h"
main(){
    Stack s;
    stackInit(s);
    int tag,num;
    while(true){
        printf("请输入数字\n");
        scanf("%d",&num);
        while(num){
            Push(num%8,s);
            num=num/8;
        }
        printf("结果如下\n");
        stackDisplsy(s);
        stackEmpty(s);
    }
}