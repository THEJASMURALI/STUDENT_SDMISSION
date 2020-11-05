#include "student.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>

int REG_BDA=1;
int REG_ML=1;
int REG_ES=1;

Program  program_seats(){
    Program prog;
    scanf("\nEnter the number of BDA seats: %d",&prog.big_data_seats);
    scanf("\nEnter the number of ML seats: %d",&prog.machine_learning_seats);
    scanf("\nEnter the number of ES seats: %d",&prog.emnedded_systems_seats);
    prog.filled_bda_seats=0;
    prog.filled_ml_seats=0;
    prog.filled_es_seats=0;
    return prog;
}




Student student_reg(){
    Student s;
    printf("\n Enter the Student name \n");
    scanf("%s",s.name);
    printf("\n Enter the program\n");
    scanf("%s",s.program);
    printf("\nEnter the email address\n");
    scanf("%s",s.email);
    printf("\nEnter the MET rank\n");
    scanf("%d",&s.MET_rank);
    printf("\nEnter UG grade\n");
    scanf("%f",&s.UG_grade);
    N0_OF_STUDENTS=N0_OF_STUDENTS+1;
    return s;


}

Program allot_seats(Student *s,Program pg){
            int i;

            for (i=0;i<N0_OF_STUDENTS;i++){
                if (s[i].UG_grade>5.0){
                    if(strcmp(s[i].program,"BDA")==0){
                        if(pg.filled_bda_seats<pg.big_data_seats){
                            pg.filled_bda_seats++;
                            strcpy(s[i].addmission_status,"alotted");
                            s[i].regnumber=REG_BDA++;

                        }
                        else{
                           strcpy(s[i].addmission_status,"waiting");
                        }
                    }
                    if(strcmp(s[i].program,"ML")==0){
                        if(pg.filled_ml_seats<pg.machine_learning_seats){
                            pg.filled_ml_seats++;
                            strcpy(s[i].addmission_status,"alotted");
                            s[i].regnumber=REG_ML++;

                        }
                        else{
                           strcpy(s[i].addmission_status,"waiting");
                        }
                    }
                    if(strcmp(s[i].program,"ES")==0){
                        if(pg.filled_es_seats<pg.emnedded_systems_seats){
                            pg.filled_es_seats++;
                            strcpy(s[i].addmission_status,"alotted");
                            s[i].regnumber=REG_ES++;

                        }
                        else{
                           strcpy(s[i].addmission_status,"waiting");
                        }
                    }
                }
                else{
                    strcpy(s[i].addmission_status,"rejected");
                }
            }
            return pg;
}



Program allot_waitlisted(Student *s,Program pg){
    int i;
    char   next_option1[PROGRAM_NAME_LEN],next_option2[PROGRAM_NAME_LEN];
    for(i=0;i<N0_OF_STUDENTS;i++){
        if(!strcmp(s[i].addmission_status,"waiting")){
            scanf("\nEnter the next 1st preference : %s",next_option1);
            scanf("\nEnter the next 2nd preference : %s",next_option2);
        if (!strcmp(next_option1,"ML")&&pg.filled_ml_seats<pg.machine_learning_seats){
                            pg.filled_ml_seats++;
                            strcpy(s[i].addmission_status,"alotted");
                            s[i].regnumber=REG_ML++;
                            return pg;
        }
        else if (!strcmp(next_option1,"BDA")&&pg.filled_bda_seats<pg.big_data_seats){
                            pg.filled_bda_seats++;
                            strcpy(s[i].addmission_status,"alotted");
                            s[i].regnumber=REG_BDA++;
                            return pg;
        }
        else if (!strcmp(next_option1,"ES")&&pg.filled_es_seats<pg.emnedded_systems_seats){
                            pg.filled_es_seats++;
                            strcpy(s[i].addmission_status,"alotted");
                            s[i].regnumber=REG_ES++;
                            return pg;
        }
        if (!strcmp(next_option2,"ML")&&pg.filled_ml_seats<pg.machine_learning_seats){
                            pg.filled_ml_seats++;
                            strcpy(s[i].addmission_status,"alotted");
                            s[i].regnumber=REG_ML++;
                            return pg;
        }
        else if (!strcmp(next_option2,"BDA")&&pg.filled_bda_seats<pg.big_data_seats){
                            pg.filled_bda_seats++;
                            strcpy(s[i].addmission_status,"alotted");
                            s[i].regnumber=REG_BDA++;
                            return pg;
        }
        else if (!strcmp(next_option2,"ES")&&pg.filled_es_seats<pg.emnedded_systems_seats){
                            pg.filled_es_seats++;
                            strcpy(s[i].addmission_status,"alotted");
                            s[i].regnumber=REG_ES++;
                            return pg;
        }

        }
    }
    return pg;
}


void     filled_seats(Program pg){
    printf("/nNumber of seats filled in BDA %d",pg.filled_bda_seats);
    printf("/nNumber of seats filled in ML %d",pg.filled_ml_seats);
    printf("/nNumber of seats filled in ES %d",pg.filled_es_seats);

}

