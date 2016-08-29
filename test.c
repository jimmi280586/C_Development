#include <stdio.h>
#include <stdlib.h>
#include "test.h"
#include "DBhandler.h"
student_node_t *head = NULL;

student_t *student1;
student_t *student2;

int main(){
	student1 = (student_t*) malloc(sizeof(student_t));
	student2 = (student_t*) malloc(sizeof(student_t));
	
	//student1->student_number = "123456";
	//student1->student_name = "Marek";
	student1 = build_student_t("123456", "Marek");
	
	//student2->student_number = "654321";
	//student2->student_name = "Brano";
	student2 = build_student_t("654321", "Brano");
	
	printf("1 from student :%s %s\n",student1->student_number,student1->student_name);
	printf("2 from student :%s %s\n",student2->student_number,student2->student_name);
	
	
	
	/*
	student_t build_student_t(char *student_number, char* student_name);
	student_t *create_student_list(student_t *s);
	student_t *add_student_to_list(student_t *s);
	void print_list();
	*/
}
