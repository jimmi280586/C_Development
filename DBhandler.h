 #ifndef SRC_DB_HANDLER_H_
 #define SRC_DB_HANDLER_H_
 #include "includes.h"

 student_t *build_student_t(char *student_number, char* student_name);
 student_t *create_student_list(student_t *s);
 student_t *add_student_to_list(student_t *s);
 void print_list();
 
 #endif /* SRC_DB_HANDLER_H_ */