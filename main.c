#include "student.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>

int main()
{
    int c,continue_choice,n=1;
    Student stu[100];
    Program prg;
    printf("\n-----------------ADMISSION PROCESSS-----------------\n");
    while(n){
    printf("\nPress 1 for initializing program seats \n");
    printf("\nPress 2 for registering student \n ");
    printf("\nPress 3 for allotting seats \n");
    printf("\nPress 5 for checking the number of applications submitted \n");
    printf("\nPress 4 for checking the number of seats filled \n");
    printf("\nPress 6 for assigning seats for wait listed students \n");
    printf("\nEnter your option :");
    scanf("%d",&c);
    switch(c){
        case 1:prg=program_seats();
               break;
        case 2:stu[N0_OF_STUDENTS]=student_reg();
               N0_OF_STUDENTS=N0_OF_STUDENTS+1;
               break;
        case 3:prg=allot_seats(stu,prg);
               printf("/n%d",stu[0].regnumber);
               printf("/n%d",prg.filled_bda_seats);
               break;
        case 4:printf("Total number of applications submitted :%d",N0_OF_STUDENTS);
               break;
        case 5:filled_seats(prg);
               break;
        case 6:prg=allot_waitlisted(stu,prg);
        default:printf("\nInvalid choice\n");


    }
    printf("\nPress 1 to continue :");
    scanf("%d",&continue_choice);
    if(continue_choice==1){
            n=1;
    }
    else{
        n=0;
    }

    }


    return 0;
}
