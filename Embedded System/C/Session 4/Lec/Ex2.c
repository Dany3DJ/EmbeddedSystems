#include<stdlib.h>
#include<stdio.h>
int x=0;
void update(void){
    static int y=0;
    x++;
    y++;
    printf("%d \n",x);
    printf("You called me #%d\n",y);
}

void main(void){
    for (int i=0;i<10;i++){
        update();
    }
}
