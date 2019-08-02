#include<stdlib.h>
#include<stdio.h>
void main(){
    int a[]={1,2,2,2,1,5,2,2,2,3,2};
    char pairs=0;

    for (int i=0;i<(sizeof(a)/sizeof(int))-1;i++){
        if (a[i] == 0){
            continue;
        }
        else{
            for (int j=i+1 ; j<(sizeof(a)/sizeof(int)); j++){
                if(a[j] == a[i]){
                    a[j]=0;
                    pairs++;
                    break;
                }
            }
        }
    }
    printf("Pairs = %d",pairs);
}
