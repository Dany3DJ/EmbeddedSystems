#include<stdlib.h>
#include<stdio.h>
int main(){
    int index=0,choice;
    int x[10]={0};
    while (1){
    printf("Press 1 to push, 2 to pop ,3 to print array\n");
    scanf("%d",&choice);
    if (choice == 1){
        printf("Enter push value \n");
        scanf("%d",&x[index]);
        index++;
    }
  else if (choice == 2){
        index--;
        printf("%d \n",x[index]);
        x[index]=0;

  }
  else if (choice == 3){
      for(int i=0;i<index;i++){
        printf("%d \n",x[i]);

    }
  }
}
}
