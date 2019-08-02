#include<stdlib.h>
#include<stdio.h>
int main(){
    int a[]={5,9,3,2,1};
    order(&a,sizeof(a)/sizeof(int));
    for (int i=0;i<sizeof(a)/sizeof(int);i++){
        printf("%d \t",a[i]);
    }
}
void order(int *a,int size){
    for (int i=0;i<size-1;i++){
        for (int j=0; j<size-1;j++){
            if (a[j]>a[j+1]){
                swap(&a[j],&a[j+1]);
            }
        }
    }
}
void swap(int *x,int*y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
