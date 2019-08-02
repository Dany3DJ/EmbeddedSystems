#include<stdlib.h>
#include<stdio.h>
int a[10]={0,0,0,0,0,0,0,0,0,1};
int *point(int *a,int *y, int size){
    y=&a[size-1];
    return y;
}
int main(){

    int *y;
    y=point(&a,y,10);
    printf("%d",*y);
}
