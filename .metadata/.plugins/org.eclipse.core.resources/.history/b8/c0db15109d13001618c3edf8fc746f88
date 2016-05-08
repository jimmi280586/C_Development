
#include "course.h"
#include <stdlib.h>
#include <stdio.h>


course_node *create_course_list()
{
	course_node *new_list = malloc(sizeof(course_node));
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

course_node *create_course_node(course *newCourse, int count)
{
	course_node *node = create_course_list();
	node->current = newCourse;
	node->count = count;
	return node;
}

course *create_course(int course_number, char *course_name, int semester_number)
{
	course *newCourse = malloc(sizeof(course));
	if(NULL == newCourse)
	{
	      printf("\n Unable to locate memory \n"); //This shouldn't happen
	      return NULL;
	}
	newCourse->course_number=course_number;
	newCourse->semester_number=semester_number;
	newCourse->course_name=course_name;
	return newCourse;
}

void add_course(course_node *head, course *newCourse)
{
	course_node *iterator = head;
	int count = 0;
	while(iterator!= NULL && iterator->next != NULL)
	{
		iterator=iterator->next;
		count++;
	}
	iterator->next = create_course_node(newCourse, count);
}

int hasCourse(int course_number, course_node *head)
{
	course_node *iterator = head->next;
	int count = 0;
	while(iterator!=NULL)
	{
		if (iterator->current->course_number == course_number)
		{
			return count;
		}
		count++;
		iterator = iterator->next;
	}
	return -1;
}

course *get_course(int course_number, course_node *head)
{
 course_node *iterator = head->next;
 while(iterator != NULL)
 {
  if(iterator->current->course_number == course_number)
  {
   return iterator->current;
  }
  iterator = iterator->next;
 }
 return NULL;
}

void print_courses(course_node *head)
{
	course_node *iterator = head;
	if (iterator->current != NULL)
	{
		print_course(iterator->current);
	}
	if(iterator->next != NULL)
	{
		print_courses(iterator->next);
	}
}

void print_course(course *myCourse)
{
	if (myCourse == NULL)
	{
		return;
	}
	printf("Course number: %d name: %s semester number: %d\n", myCourse->course_number, myCourse->course_name, myCourse->semester_number);
}
