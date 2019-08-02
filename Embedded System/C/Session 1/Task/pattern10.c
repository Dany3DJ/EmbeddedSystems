#include<stdio.h>
#include<stdlib.h>
int main(void){
    for (int i=4;i>=0;i--){
         for (int j=5-i;j>0;j--)
            printf("*");
    printf("\n");
}
}
