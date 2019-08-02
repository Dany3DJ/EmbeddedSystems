#include<stdlib.h>
#include<stdio.h>
void main(){
    char *s="hello";
    char *p=s;
    printf("%p\t%p \n",p,s);
    printf(sizeof(char));
}
