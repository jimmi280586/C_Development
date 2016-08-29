 #include <stdio.h> 
 #include <stdlib.h> 
 #include "includes.h"
 
 //these keeps reference of "pointers" in liked lists
 student_node_t *head = NULL;
 student_node_t *current = NULL;
 
 student_t *student1;
 student_t *student2;
 
  //returns student struct 
 student_t * build_student_t(char *student_number, char* student_name){
	 student_t *student ;
	 student = (student_t*) malloc(sizeof(student_t)); //allocating student struct
	 //do we need allocate the internal parameters of node ? 
	 student_number = (char*)malloc(sizeof(char)*6);
	 student_name = (char*)malloc(sizeof(char)*30);
	 
	 student->student_number = student_number;
	 student->student_name = student_name;
	 return student;
 }
 
 // add student node to list
 student_node_t * create_student_list(student_t *s){
	 student_node_t *s_node;
	 s_node = (student_node_t*)malloc(sizeof(student_node_t));
	 s_node->student_n = s;
	 s_node->next = NULL;
	 head = s_node;
	 return s_node;
 }
 
 student_node_t * add_student_to_list(student_t *s){
	 
	 if(head == NULL){
		 return (create_student_list(s));
	 }
	 student_node_t *a_node;
	 a_node = (student_node_t*)malloc(sizeof(student_node_t));
	 a_node->student_n = s;
	 a_node->next = NULL;
	 current = head;
	 while(current->next != NULL){
		 current = current->next;
		 
	 }
	 current->next = a_node;
	 return a_node;
 }
  
  void print_list(){
	  current = head;
	  while(current!=NULL){
		 fprintf("%s %s",current->student_n->student_number,current->student_n->student_name);
		 current = current->next;
	  }
  }
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
}
 //-----------------------------------------------------------------------------
