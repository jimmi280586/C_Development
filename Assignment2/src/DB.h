
#include <stdlib.h>
#include <stdio.h>
#include "file.h"

typedef struct database{
	struct student_node *studentList;
	struct teacher_node *teacherList;
	struct assignment_node *assignmentList;
	struct enrollment_node *enrollmentList;
	struct course_node *courseList;
}database;

database *create_database();

void add_student_to_database(database *myDatabase, int student_number, char* student_name);

void add_teacher_to_database(database *myDatabase, int teacher_number, char* teacher_name);

void print_students_from_database(database *myDatabase);

void print_teachers_from_database(database *myDatabase);

void print_courses_from_database(database *myDatabase);


int enrol_student_in_course(database *myDatabase, int student_number, int course_number);

int assign_teacher_to_course(database *myDatabase, int teacher_number, int course_number);

void print_all_courses_for_student(database *myDatabase, int student_number);

void print_all_courses_for_teacher(database *myDatabase, int teacher_number);

void print_all_students_for_course(database *myDatabase, int course_number);

int remove_student_from_database(database *myDatabase, int studen_number);
