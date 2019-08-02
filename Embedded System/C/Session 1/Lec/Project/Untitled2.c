#include<stdio.h>
#include<stdlib.h>

int main(){
 int x;
 printf("How many times to print \n");
 scanf("%d",&x);
 for (int i=0; i<x; i++){
    printf("Daniel ");
    printf("%d",i+1);
    printf("\n");
 }
}
