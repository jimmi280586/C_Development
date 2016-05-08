#include "enroll.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

enrollment_node *create_enrollment_list()
{
	enrollment_node *new_list = malloc(sizeof(enrollment_node));
	if(NULL == new_list)
	{
        printf("\n Unable to allocate memory \n"); //This shouldn't ever happen
        return NULL;
    }
    new_list->count = 0;
    new_list->current = NULL;
    new_list->next = NULL;
    return new_list;
}

enrollment *create_enrollment(struct student *e_student, struct course *e_course)
{
	enrollment *newEnrollment = malloc(sizeof(enrollment));
	if(NULL == newEnrollment)
	{
        printf("\n Unable to allocate memory \n"); //This shouldn't ever happen
        return NULL;
    }
    newEnrollment->e_student = e_student;
    newEnrollment->e_course = e_course;
    return newEnrollment;
}

enrollment_node *create_enrollment_node(enrollment *newEnrollment, int count)
{
	enrollment_node *node = create_enrollment_list();
	node->current = newEnrollment;
	node->count = count;
	return node;
}

void add_enrollment(enrollment_node *head, enrollment *newEnrollment)
{
	enrollment_node *iterator = head;
	int count = 0;
	while(iterator != NULL && iterator->next != NULL)
	{
		iterator = iterator->next;
		count++;
	}
	iterator->next = create_enrollment_node(newEnrollment, count);
}

int hasEnrollment(struct student *e_student, struct course *e_course, enrollment_node *head)
{
	enrollment_node *iterator = head->next;
	int count = 0;
	while(iterator!=NULL)
	{
		if(iterator->current->e_student->student_number == e_student->student_number && iterator->current->e_course->course_number == e_course->course_number)
		{
			return count;
		}
		count++;
		iterator = iterator->next;
	}
	return -1;
}

void get_students_courses_recursive(enrollment_node *enrollmentList, student *myStudent, course_node *myCoursList)
{
	if (enrollmentList != NULL)
	{
		if (enrollmentList->current != NULL)
		{
			if (enrollmentList->current->e_student->student_number == myStudent->student_number)
			{
				add_course(myCoursList, enrollmentList->current->e_course);
			}
		}
	}
	if (enrollmentList->next != NULL)
	{
		get_students_courses_recursive(enrollmentList->next, myStudent, myCoursList);
	}
}

course_node *get_students_courses(enrollment_node *enrollmentList, student *myStudent)
{
	course_node *myCoursList = create_course_list();
	get_students_courses_recursive(enrollmentList, myStudent, myCoursList);
	return myCoursList;
}

int enrol_student(enrollment_node *enrollmentList, student_node *studentList, course_node *courseList, int student_number, int course_number)
{
	student *myStudent = get_student(student_number, studentList);
	if (myStudent == NULL)
	{
		//student doesn't exist
		printf("Student doesn't exist\n");
		return 0;
	}
	course *myCourse = get_course(course_number, courseList);
	if (myCourse == NULL)
	{
		//course doesn't exist
		printf("Course doesn't exist\n");
		return 0;
	}
	enrollment *myEnrollment = create_enrollment(myStudent, myCourse);
	add_enrollment(enrollmentList, myEnrollment);
	return 1;
}

void print_course_for_student(enrollment_node *enrollmentList, student_node *studentList,  int student_number)
{
	student *myStudent = get_student(student_number, studentList);
	if (myStudent == NULL)
	{
		printf("Student number %d: isn't in the database\n", student_number);
		return;
	}
	printf("Courses for student number %d:\n", student_number);
	course_node *studentsCourses = get_students_courses(enrollmentList, myStudent);
	print_courses(studentsCourses);
}

void get_courses_for_student_recursive(enrollment_node *enrollmentList, course *myCourse, student_node *myStudentList)
{
	if (enrollmentList != NULL)
	{
		if (enrollmentList->current != NULL)
		{
			if (enrollmentList->current->e_course->course_number == myCourse->course_number)
			{
				add_student(myStudentList, enrollmentList->current->e_student);
			}
		}
	}
	if (enrollmentList->next != NULL)
	{
		get_courses_for_student_recursive(enrollmentList->next, myCourse, myStudentList);
	}
}

student_node *get_courses_for_student(enrollment_node *enrollmentList, course *myCourse)
{
	student_node *myStudentList = create_student_list();
	get_courses_for_student_recursive(enrollmentList, myCourse, myStudentList);
	return myStudentList;
}


int remove_student_by_student_number(enrollment_node *enrollmentList, student_node *studentList, int student_number)
{
	student *myStudent = get_student(student_number, studentList);
	if (myStudent == NULL)
	{
		//didn't find the student
		return 0;
	}
	student_node *iterator = studentList;
	while (iterator->next->current->student_number != myStudent->student_number)
	{ //I don't have to check for NULL because I alredy know it contains it
		iterator = iterator->next;
	}
	student_node *studentToRemove = iterator->next;
	iterator->next = iterator->next->next; //remove from the student list
	enrollment_node *enrollment_iterator = enrollmentList;
	while(enrollment_iterator->next != NULL)
	{
		if (enrollment_iterator->next->current->e_student->student_number == studentToRemove->current->student_number)
		{
			enrollment_node *enrollment_to_delete = enrollment_iterator->next;
			enrollment_iterator->next=enrollment_iterator->next->next;
			free(enrollment_to_delete);
		}
		enrollment_iterator=enrollment_iterator->next;
		if (enrollment_iterator == NULL)
		{
			break;
		}
	}
	free(studentToRemove->current->firstName);
	free(studentToRemove->current);
	free(studentToRemove);
	return 1;
}
