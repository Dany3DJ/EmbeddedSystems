#include<stdio.h>
#include<stdlib.h>
int main(){
// Writing array
   char x[6][6];
   int index=1;
   for (int i=0; i<6; i++){
    for(int j=0; j<6; j++){
        x[i][j]=index;
        index++;
    }
}
//printing array
for (int i=0; i<6; i++){
    for(int j=0; j<6; j++){
        printf("%d \t",x[i][j]);
    }
    printf("\n");
}
printf("\n");
// Calculating stamps
 int stamp[16];
 int y=0;
    for (int i=1; i<5; i++){
        for (int j=1; j<5 ; j++){
           stamp[y]= x[i][j] + x[i-1][j-1] + x[i-1][j] + x[i-1][j+1] + x[i+1][j-1] + x[i+1][j] + x[i+1][j+1];
           y++;
        }
    }
printf("\n");
 // Printing stamps
 for (int i=0; i<16 ; i++){
    printf("%d \t",stamp[i]);
 }
 // calculating max stamp
 int max=0;
 for (int i=0; i<16 ; i++){
    if (stamp[i]>max)
        max=stamp[i];
 }
 printf("\n \n");
 //printing max stamp
printf("Max stamp is %d",max);
}
