#include<stdlib.h>
#include<stdio.h>
struct student{
    int code;
    int birth;
    int grade;
};
void fill(struct student *student,int code,int birth,int grade){
    student->code=code;
    student->birth=birth;
    student->grade=grade;
}
void main(void){
    struct student student;
    fill(&student,21,1999,100);
    printf("%d\t %d\t %d",student.code,student.birth,student.grade);
}
