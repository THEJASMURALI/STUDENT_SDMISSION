#include <stdint.h>
#include "appconst.h"
#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED


static int N0_OF_STUDENTS=0;

struct _student_{
	char    name[STUDENT_NAME_LEN];
	int32_t regnumber;
	char    program[PROGRAM_NAME_LEN];
	char    email[EMAIL_LEN];
	int32_t MET_rank;
	float   UG_grade;
	char    addmission_status[ADMISSSION_STATUS_LEN];
};
typedef struct _student_ Student;

struct _program_  {
	int8_t big_data_seats;
	int8_t machine_learning_seats;
	int8_t emnedded_systems_seats;

	int8_t filled_bda_seats;
	int8_t filled_ml_seats;
	int8_t filled_es_seats;
};
typedef struct _program_ Program;

Program	program_seats();
Student student_reg();
Program allot_seats(Student *s,Program pg);
int32_t test_admission_ststus(Student s1);
Program allot_waitlisted(Student *s,Program pg);
void filled_seats(Program pg);

#endif
