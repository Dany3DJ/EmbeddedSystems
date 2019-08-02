#include<stdio.h>
#include<stdlib.h>
void main(){
    int x=5, y=11;
    int *ptr=&x, *ptr2=&y;
    *ptr=10;
    printf("%d \n",*ptr);
    printf("%p \n",&x);
    printf("%p \n",&y);
    printf("%p \n",ptr);
    printf("%p \n",ptr2);

}
