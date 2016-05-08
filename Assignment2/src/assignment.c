#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "assignment.h"

assignment_node *create_assignment_list()
{
	assignment_node *new_list = malloc(sizeof(assignment_node));
	if(NULL == new_list)
	{
        printf("\n Unable to locate memory \n"); //This shouldn't happen
        return NULL;
    }
    new_list->count = 0;
    new_list->current = NULL;
    new_list->next = NULL;
    return new_list;
}

assignment *create_assignment(struct teacher *a_teacher, struct course *a_course)
{
	assignment *newAssignment = malloc(sizeof(assignment));
	if(NULL == newAssignment)
	{
        printf("\n Unable to locate memory \n"); //This shouldn't happen
        return NULL;
    }
    newAssignment->a_teacher = a_teacher;
    newAssignment->a_course = a_course;
    return newAssignment;
}

assignment_node *create_assignment_node(assignment *newassignment, int count)
{
	assignment_node *node = create_assignment_list();
	node->current = newassignment;
	node->count = count;
	return node;
}

void add_assignment(assignment_node *head, assignment *newassignment)
{
	assignment_node *iterator = head;
	int count = 0;
	while(iterator != NULL && iterator->next != NULL)
	{
		iterator = iterator->next;
		count++;
	}
	iterator->next = create_assignment_node(newassignment, count);
}

int hasAssignment(struct teacher *a_teacher, struct course *a_course, assignment_node *head)
{
	assignment_node *iterator = head->next;
	int count = 0;
	while(iterator!=NULL)
	{
		if(iterator->current->a_teacher->teacher_number == a_teacher->teacher_number && iterator->current->a_course->course_number == a_course->course_number)
		{
			return count;
		}
		count++;
		iterator = iterator->next;
	}
	return -1;
}

void get_teacher_courses_recursive(assignment_node *assignmentList, teacher *myTeacher, course_node *myCoursList)
{
	if (assignmentList != NULL)
	{
		if (assignmentList->current != NULL)
		{
			if (assignmentList->current->a_teacher->teacher_number == myTeacher->teacher_number)
			{
				add_course(myCoursList, assignmentList->current->a_course);
			}
		}
	}
	if (assignmentList->next != NULL)
	{
		get_students_courses_recursive(assignmentList->next, myTeacher, myCoursList);
	}
}

course_node *get_teacher_courses(assignment_node *assignmentList, teacher *myTeacher)
{
	course_node *myCoursList = create_course_list();
	get_teacher_courses_recursive(assignmentList, myTeacher, myCoursList);
	return myCoursList;
}

int assign_teacher(assignment_node *assignmentList, teacher_node *teacherList, course_node *courseList, int teacher_number, int course_number)
{
	teacher *myTeacher = get_teacher(teacher_number, teacherList);
	if (myTeacher == NULL)
	{
		//student doesn't exist
		printf("Teacher doesn't exist\n");
		return 0;
	}
	course *myCourse = get_course(course_number, courseList);
	if (myCourse == NULL)
	{
		//course doesn't exist
		printf("Course doesn't exist\n");
		return 0;
	}
	assignment *myAssignment = create_assignment(myTeacher, myCourse);
	add_enrollment(assignmentList, myAssignment);
	return 1;
}

void print_course_for_teacher(assignment_node *assignmentList, teacher_node *teacherList,  int teacher_number)
{
	teacher *myTeacher = get_teacher(123457, teacherList);
	if (myTeacher == NULL)
	{
		printf("teacher number %d: isn't in the database\n", teacher_number);

	}
	printf("Courses for teacher number %d:\n", teacher_number);
	course_node *teacherCourses =  get_teacher_courses(assignmentList, myTeacher);
	print_courses(teacherCourses);
}

