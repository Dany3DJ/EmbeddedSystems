#include<stdlib.h>
#include<stdio.h>
struct student{
    int namecode;
    int *ptr;
};
typedef struct student student;
void main(void){
    student p1;
    student *pointer;
    pointer=&p1;
    p1.namecode=50;
    printf("%d \n",p1.namecode);
    pointer->namecode=70;
    printf("%d \n",pointer ->namecode);
}
