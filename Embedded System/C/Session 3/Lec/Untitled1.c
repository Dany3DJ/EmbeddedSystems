#include<stdio.h>
#include<stdlib.h>
int main(){
    char x[5][2];
    char index='a';
  // printf("%c",index);
    for (int i=0;i<5;i++){
        x[i][0]=index;
        printf("Enter grade of student %c \n",index);
        scanf("%d",&x[i][1]);
        index++;
    }
    printf("\nstudent \t grade \n");
    for (int i=0;i<5;i++){
        printf("%c \t",x[i][0]);
        printf("\t %d",x[i][1]);
        printf("\n");
    }
}
