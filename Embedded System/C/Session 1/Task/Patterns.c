#include<stdio.h>
#include<stdlib.h>
#include "Patterns.h"

int main(){
    int c;
    printf("Available patterns are 2, 6, 10, 15, 34, 47, 54\n");
    while(1){
    printf("Which pattern you want ? \n");
    scanf("%d",&c);
    switch (c){
        case 2: pattern2();
            break;
        case 6: pattern6();
            break;
        case 10: pattern10();
            break;
        case 15: pattern15();
            break;
        case 34: pattern34();
            break;
        case 47: pattern47();
            break;
        case 54: pattern54();
            break;
        default : printf("No such pattern \n");
            break;
        }
    }
}
