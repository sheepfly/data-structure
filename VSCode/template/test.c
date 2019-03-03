#include<stdio.h>
#include<stdlib.h>
// void fun(int a[][]){
//     a[0][0]=3;
// }
// void fun2(int *a){
//     a[0][0]=3;
// }
void fun3(int a[3][3]){
    a[0][0]=3;
}
void fun4(int a){
    a=4;
}
void fun5(int &a){
    a=5;
}
main(){
    char a;
    int a[]={1,2,3,4};
    int b[4];
}