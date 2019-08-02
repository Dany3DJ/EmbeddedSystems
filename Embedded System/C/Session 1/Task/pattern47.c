#include<stdio.h>
#include<stdlib.h>
int main(void){
    for (int i=4;i>=1;i--){
        for (int j=1;j<8;j++){
          if (j<4+i && j>4-i){
            printf("*");
          }
          else printf(" ");
        }
        printf("\n");
    }

}
