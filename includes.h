
 #ifndef SRC_INCLUDES_H_
 #define SRC_INCLUDES_H_
 
 #include <stdio.h>
 #include <stdlib.h>
 /*
 obtains structs of single "objects" and nodes for linked list 
 */
 
  typedef struct student_t{
	 char *student_number;
	 char *student_name;
 } student_t;
 
 typedef struct student_node_t{
 student_t *student_n;
 struct student_node *next;
 } student_node_t;
  
 //... 
 #endif /* SRC_INCLUDES_H_ */