#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "student.h"

student_node *create_student_list()
{
    student_node *new_list = malloc(sizeof(student_node));
    if(NULL == new_list)
    {
        printf("\n Unable to locate memory \n"); //This shouldn't happen
        return NULL;
    }
    new_list->current = NULL;
    new_list->next = NULL;
    new_list->count = 0;
    return new_list;
}

student_node *create_student_node(student *newStudent, int count)
{
    student_node *node = create_student_list(); //create an empty student node
    node->current = newStudent;
    node->count = count;
    return node;
}

student *create_student(int student_number, char *firstName)
{
  student *newStudent = malloc(sizeof(student));
  if (NULL == newStudent)
  {
      printf("\n Unable to locate memory \n"); //This shouldn't ever happen
      return NULL;
  }
  newStudent->student_number = student_number;
  newStudent->firstName = firstName;
 
  return newStudent;
}

void add_student(student_node *head, student *newStudent)
{
  student_node *iterator = head;
  int count = 0;
  while(iterator != NULL && iterator->next != NULL)
  {
  iterator = iterator->next;
  count++;
  }
  iterator->next = create_student_node(newStudent, count);
}

int hasStudent(int student_number, student_node *head)
{
 student_node *iterator = head->next;
 int count = 0;
 while(iterator != NULL)
 {
  if(iterator->current->student_number == student_number)
  {
   return count;
  }
  count++;
  iterator = iterator->next;
 }
 return -1;
}

student *get_student(int student_number, student_node *head)
{
 student_node *iterator = head->next;
 while(iterator != NULL)
 {
  if(iterator->current->student_number == student_number)
  {
   return iterator->current;
  }
  iterator = iterator->next;
 }
 return NULL;
}

void print_students(student_node *head)
{
	student_node *iterator = head;
	if (iterator->current != NULL)
	{
		//printf("Student number: %d name: %s\n", iterator->current->student_number, iterator->current->firstName);
		print_student(iterator->current);
	}
	if(iterator->next != NULL){
		print_students(iterator->next);
	}
}

void print_student(student *myStudent)
{
	if (myStudent == NULL)
	{
		return;
	}
	printf("Student number: %d name: %s\n", myStudent->student_number, myStudent->firstName);
}

