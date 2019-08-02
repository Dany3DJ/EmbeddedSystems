#include<stdlib.h>
#include<stdio.h>
struct account{
    int id;
    int balance;
    int birth;
};
void main(){
    struct account person[3];
    for (int i=0;i<3;i++){
        printf("Enter id \n");
        scanf("%d",&person[i].id);
        printf("Enter balance \n");
        scanf("%d",&person[i].balance);
        printf("Enter birth \n");
        scanf("%d",&person[i].birth);
    }
    for (int i=0;i<3;i++){
        printf("id\tbalance\tbirth\n");
        printf("%d \t %d \t %d \n",person[i].id,person[i].balance,person[i].birth);
    }

}
