#include<stdio.h>
main(){
    int i=4;
    int b=i^0xfffff;
    printf("%d",b&i);
    int a;
    scanf("%d",&a);
}