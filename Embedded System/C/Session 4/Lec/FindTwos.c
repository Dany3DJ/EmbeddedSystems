#include<stdlib.h>
#include<stdio.h>
char findtwos(char *a,char Size);
void main(){
    char a[]={1,2,2,4,6,2,1,1,2,2,1,2};
    char ans;
    ans=findtwos(&a,12);
    printf("%d",ans);
}
//Finds the number of Twos present in an array
char findtwos(char *a,char Size){
        int i=0;
        char total=0;
        while (a[i] < Size ){
            if (a[i] == 2){
                total++;
            }
            i++;
        }
    return total;
}
