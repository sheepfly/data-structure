#include<stdio.h>
#include<stdlib.h>
#define ANTI 1
#define KEEP 0
int a[100][100];
void Anti(int a[100][100],int x,int y){
    int num=a[x][y];
    if(num)a[x][y]=0;
    else a[x][y]=1;
}
int Sum(int a[100][100],int x,int y){
    int sum=0;
    sum+=a[x-1][y-1];
    sum+=a[x-1][y];
    sum+=a[x-1][y+1];
    sum+=a[x][y-1];
    sum+=a[x][y+1];
    sum+=a[x+1][y-1];
    sum+=a[x+1][y];
    sum+=a[x+1][y+1];
    return sum;
}
void Random(int a[100][100],int x,int y){
    int sum=0;
        for(int i=1;i<99;i++){
            for(int j=1;j<99;j++){
                sum=Sum(&a[100],x,y);
                if(sum<2)Anti(&a[100],x,y);
                else if(sum<4);
                else if(sum<6)a[x][y]=1;
                else a[x][y]=0;
            }
        }
}
main(){
    int a[100][100];
    system("pause");
}