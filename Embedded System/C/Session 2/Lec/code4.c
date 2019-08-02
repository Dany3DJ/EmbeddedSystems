#include<stdio.h>
#include<stdlib.h>
int add(int x,int y); // Function Prototyping
int main(){
    int z;
    z= add(3,5);
    printf("%d",z);
}
int add(int x,int y){
    return x+y;
}

