
#include "DB.h"

database *create_database()
{
	database *myDatabase = malloc(sizeof(database));
	if (NULL == myDatabase)
	{
	      printf("\n Unable to locate memory \n"); //This shouldn't happen
	      return NULL;
	 }
	myDatabase->studentList = create_student_list();
	myDatabase->teacherList = create_teacher_list();
	myDatabase->assignmentList = create_assignment_list();
	myDatabase->enrollmentList = create_enrollment_list();
	myDatabase->courseList = create_course_list();
	readFile(myDatabase->studentList, myDatabase->teacherList, myDatabase->courseList, myDatabase->enrollmentList, myDatabase->assignmentList);
	return myDatabase;
}


void add_student_to_database(database *myDatabase, int student_number, char* student_name)
{
	student *newStudent = create_student(student_number, student_name);
	add_student(myDatabase->studentList, newStudent);
}

void add_teacher_to_database(database *myDatabase, int teacher_number, char* teacher_name)
{
	teacher *newTeacher = create_teacher(teacher_number, teacher_name);
	add_teacher(myDatabase->teacherList, newTeacher);
}

void print_students_from_database(database *myDatabase)
{
	print_students(myDatabase->studentList);
}

void print_teachers_from_database(database *myDatabase)
{
	print_teachers(myDatabase->teacherList);
}

void print_courses_from_database(database *myDatabase)
{
	print_courses(myDatabase->courseList);
}

int enrol_student_in_course(database *myDatabase, int student_number, int course_number)
{
	return enrol_student(myDatabase->enrollmentList, myDatabase->studentList, myDatabase->courseList, student_number, course_number);
}

int assign_teacher_to_course(database *myDatabase, int teacher_number, int course_number)
{
	return assign_teacher(myDatabase->assignmentList, myDatabase->teacherList, myDatabase->courseList, teacher_number, course_number);
}

void print_all_courses_for_student(database *myDatabase, int student_number)
{
	print_course_for_student(myDatabase->enrollmentList, myDatabase->studentList, student_number);
}

void print_all_courses_for_teacher(database *myDatabase, int teacher_number)
{
	print_course_for_teacher(myDatabase->assignmentList,myDatabase->teacherList, teacher_number);
}

void print_all_students_for_course(database *myDatabase, int course_number)
{
	course *myCourse = get_course(course_number, myDatabase->courseList);
	if (myCourse == NULL)
	{
		//courses isn't in the database
		printf("course number: %d isn't in the database", course_number);
		return;
	}
	printf("Printing all students for course number %d:\n", course_number);
	student_node *myStudentList = get_courses_for_student(myDatabase->enrollmentList, myCourse);
	print_students(myStudentList);
}

int remove_student_from_database(database *myDatabase, int studen_number)
{
	return remove_student_by_student_number(myDatabase->enrollmentList, myDatabase->studentList, studen_number);
}
