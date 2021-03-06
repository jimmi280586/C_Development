#include "assignment.h"
#include "student.h"

typedef struct enrollment
{
	struct student *e_student;
	struct course *e_course;
	}enrollment;

typedef struct enrollment_node
{
	int count;
	struct enrollment *current;
	struct enrollment_node *next;
	}enrollment_node;

enrollment_node *create_enrollment_list();

enrollment *create_enrollment(struct student *e_student, struct course *e_course);

void add_enrollment(enrollment_node *head, enrollment *newEnrollment);

int hasEnrollment(struct student *e_student, struct course *e_course, enrollment_node *head);

course_node *get_students_courses(enrollment_node *enrollmentList, student *myStudent);

int enrol_student(enrollment_node *enrollmentList, student_node *studentList, course_node *courseList, int student_number, int course_number);

void print_course_for_student(enrollment_node *enrollmentList, student_node *studentList,  int student_number);

student_node *get_courses_for_student(enrollment_node *enrollmentList, course *myCourse);

int remove_student_by_student_number(enrollment_node *enrollmentList, student_node *studentList, int student_number);
