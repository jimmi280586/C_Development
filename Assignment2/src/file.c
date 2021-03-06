

#include "file.h"

#include <stdio.h>
#include <stdlib.h>

int limit = 100;


void readStudent(student_node *studentList, char *s)
{
	int student_number;
	char *student_name = malloc(sizeof(char)*limit);
	if (sscanf(s, "S %d %s", &student_number, student_name) > 0)
	{
		student *newStudent = create_student(student_number, student_name);
		add_student(studentList, newStudent);
	}
}

void readTeacher(teacher_node *teacherList, char *s)
{
	int teacher_number;
	char *teacher_name = malloc(sizeof(char)*limit);
	if (sscanf(s, "T %d %s", &teacher_number, teacher_name) > 0)
	{
		teacher *newTeacher = create_teacher(teacher_number, teacher_name);
		add_teacher(teacherList, newTeacher);
	}
}

void readCourse(course_node *courseList, char *s)
{
	int course_number;
	int semester_number;
	char *course_name = malloc(sizeof(char)*limit);
	if (sscanf(s, "C %d %s %d", &course_number, course_name, &semester_number) > 0)
	{
		course *newCourse = create_course(course_number, course_name, semester_number);
		add_course(courseList, newCourse);
	}
}

void readEnrollments(enrollment_node *enrollmentList, student_node *studentList, course_node *courseList, char *s)
{
	int student_number;
	int course_number;
	if (sscanf(s, "E %d %d", &student_number, &course_number) > 0)
	{
		student *myStudent = get_student(student_number, studentList);
		course *myCourse = get_course(course_number, courseList);
		enrollment *newEnrollment = create_enrollment(myStudent, myCourse);
		add_enrollment(enrollmentList, newEnrollment);
	}
}

void readAssignmnet(assignment_node *assignmentList, teacher_node *teacherList, course_node *courseList, char *s)
{
	int teacher_number;
	int course_number;
	if (sscanf(s, "A %d %d", &teacher_number, &course_number) > 0){
		teacher *myTeacher = get_teacher(teacher_number, teacherList);
		course *myCourse = get_course(course_number, courseList);
		assignment *newAssignment = create_assignment(myTeacher, myCourse);
		add_assignment(assignmentList, newAssignment);
	}
}

void readFile(student_node *studentList, teacher_node *teacherList, course_node *courseList, enrollment_node *enrollmentList, assignment_node *assignmentList)
{
	FILE *fp;
	char *s = malloc(sizeof(char)*limit);
	fp = fopen("textFile.txt", "r");
	if (fp != NULL)
	{
		while (fgets(s, limit-1, fp) != NULL)
		{
			switch (s[0])
			{
			case 'S' : readStudent(studentList, s); break;
			case 'T' : readTeacher(teacherList, s); break;
			case 'E' : readEnrollments(enrollmentList, studentList, courseList, s); break;
			case 'A' : readAssignmnet(assignmentList, teacherList, courseList, s); break;
			case 'C' : readCourse(courseList, s); break;
			}
		}
		fclose(fp);
	}else{
		perror("text file not found");
	}
}
