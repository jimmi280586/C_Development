#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "teacher.h"

teacher_node *create_teacher_list()
{
    teacher_node *new_list = malloc(sizeof(teacher_node));
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

teacher_node* create_teacher_node(teacher *newteacher, int count)
{
    teacher_node *node = create_teacher_list(); //create an empty teacher node
    node->current = newteacher;
    node->count = count;
    return node;
}

teacher *create_teacher(int teacher_number, char *firstName)
{
  teacher *newteacher = malloc(sizeof(teacher));
  if (NULL == newteacher)
  {
      printf("\n Unable to locate memory \n"); //This shouldn't happen
      return NULL;
  }
  newteacher->teacher_number = teacher_number;
  newteacher->firstName = firstName;
 
  return newteacher;
}

void add_teacher(teacher_node *head, teacher *newteacher)
{
  teacher_node *iterator = head;
  int count = 0;
  while(iterator != NULL && iterator->next != NULL)
  {
  iterator = iterator->next;
  count++;
  }
  iterator->next = create_teacher_node(newteacher, count);
}

int hasteacher(int teacher_number, teacher_node *head)
{
 teacher_node *iterator = head->next;
 int count = 0;
 while(iterator != NULL)
 {
  if(iterator->current->teacher_number == teacher_number)
  {
   return count;
  }
  count++;
  iterator = iterator->next;
 }
 return -1;
}

teacher *get_teacher(int teacher_number, teacher_node *head)
{
 teacher_node *iterator = head->next;
 while(iterator != NULL)
 {
  if(iterator->current->teacher_number == teacher_number)
  {
   return iterator->current;
  }
  iterator = iterator->next;
 }
 return NULL;
}

void print_teachers(teacher_node *head)
{
	teacher_node *iterator = head;
	if (iterator->current != NULL)
	{
		print_teacher(iterator->current);
	}
	if(iterator->next != NULL)
	{
		print_teachers(iterator->next);
	}
}

void print_teacher(teacher *myTeacher)
{
	if (myTeacher == NULL)
	{
		return;
	}
	printf("Teacher number: %d name: %s\n", myTeacher->teacher_number, myTeacher->firstName);
}
