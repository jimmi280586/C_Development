
#include <stdlib.h>
#include <stdio.h>
#include "DB.h"

void main(){
	database *myDatabase = create_database(); //creates a database and reads from file
	print_students_from_database(myDatabase); //prints student from database
	print_teachers_from_database(myDatabase); //prints teachers from database
	print_courses_from_database(myDatabase); //prints courses from database

	print_all_courses_for_student(myDatabase, 123455); //prints all courses for this student
	print_all_courses_for_teacher(myDatabase, 123457); //prints all courses for this teacher
	assign_teacher_to_course(myDatabase, 123457, 31); //assigns a teacher
	print_all_courses_for_teacher(myDatabase, 123457);
	print_all_students_for_course(myDatabase, 11); //prints all students for course

	printf("\n"); //testing of student removal
	print_students_from_database(myDatabase);
	remove_student_from_database(myDatabase, 123455);
	print_students_from_database(myDatabase); //student removal is still not working
	print_all_students_for_course(myDatabase, 11);


}


