#include<stdlib.h>
#include<stdio.h>
struct list{
    int even[20];
    int odd[20];
};
struct list separate(int a[],int size);
void decbin(int x);
void pattern10(void);
void sort(int a[],int size);
void swap(int *a,int *b);
void largest2nums(int a[],int size);

int main(void){
    int a[]={1,2,3,4,5,6,7,8,9,10};
    largest2nums(a,10);
}
void decbin(int x){
    int value[20]={0};
    int current=0;
    int j=0;
    for(int i=0;i<10;i++){

        if (x==0){
            break;
        }

        current =x;
        x=x/2;
        if (current%2 == 0){
            value[i]=0;
        }
        if (current%2 == 1 ){
            value[i]=1;
        }
        j++;
    }
    while (j>=0){
        printf("%d",value[j]);
        j--;
    }

}
void printPrimes(void){
    char primes[100]={0};
    char flag=0;
    for(int i=2;i<=20;i++){
        for (int j=2;j<i;j++){
            if (i%j == 0)
                flag=1;
                break;
        }
    }
}
void pattern10(void){

    for (int i=3;i>=0;i--){
        for (int j=1;j<8;j++){
            if (j<=4+i && j>=4-i){
                printf("*");
            }
            else
                printf(" ");
        }
        printf("\n");
    }
        for (int i=1;i<4;i++){
        for (int j=1;j<8;j++){
            if (j<=4+i && j>=4-i){
                printf("*");
            }
            else
                printf(" ");
        }
        printf("\n");
    }
}
void sort(int a[],int size){
    int temp;
    for (int j=0; j<size; j++){
    for (int i=size; i>0 ;i--){
            if ( a[i] < a[i-1] ){
                swap(&a[i],&a[i-1]);
            }
            else{
                continue;
            }
        }
    }
}
void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void largest2nums(int a[],int size){
    int flag=0;
    int max1=0,max2=0;
    for (int i=0;i<size;i++){
        if (a[i]>max1){
                max1=a[i];
                flag=1;
            }
        if (a[i]>max2 ){
                if (max2<max1){
                max2=a[i];
                }
            }

    }
    printf("first largest number is %d \n second largest number is %d",max1,max2);
}
struct list separate(int a[],int size){
    struct list list;
    int i=0,j=0;
    for(int k=0;k<size;k++){
        if (a[k]%2==0){
            list.even[i]=a[k];
            i++;
        }
        else{
            list.odd[j]=a[k];
            j++;
        }
    }
    list.even[i]=NULL;
    list.even[j]=NULL;
    return list;
}
