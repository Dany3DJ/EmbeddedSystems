#include<stdlib.h>
#include<stdio.h>
int arraySum(int a[],int size){
    int sum=0;
    for (int i=0; i<size; i++){
        sum=sum+a[i];
    }
    return sum;
}
void main(void){
    int x[]={1,2,3,4,5,6,7,8,9,10};
    int length=sizeof(x)/sizeof(int);
    int sum=arraySum(x,length);
    printf("Sum= %d \nAverage= %d",sum,(sum/length));
}
