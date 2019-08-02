#include<stdio.h>
#include<stdlib.h>
int main(){
    int bin[32];
    int x;
    printf("Enter the number \n");
    scanf("%d",&x);
    int i=0;
    while(x>0){
        bin[i]= x%2 ;
        x=x/2;
        i++;
    }
for(int j=i-1;j>=0;j--){
    printf("%d",bin[j]);
    }
}
