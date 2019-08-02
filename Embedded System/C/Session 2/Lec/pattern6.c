#include<stdio.h>
#include<stdlib.h>
int main(){
    printf("Enter your number \n");
    int x;
    int i=0;
    scanf("%d",&x);
    while (x != 0){
        x=x/10;
        i++;
    }
    printf("%d",i);
}
