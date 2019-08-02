#include<stdio.h>
#include<stdlib.h>
int main(void){
    for (int i=0;i<5;i++){
         for (int j=5-i;j>0;j--)
            printf("*");
    printf("\n");
}
}
