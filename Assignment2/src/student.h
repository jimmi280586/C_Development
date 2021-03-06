typedef struct student
{
 	int student_number;
 	char *firstName;
	}student;

typedef struct student_node
{
 	int count;
 	student *current;
 	struct student_node *next;
	}student_node; 

student_node *create_student_list();

student *create_student(int student_number, char *firstName);

void add_student(student_node *head, student *newStudent);

int hasStudent(int student_number, student_node *head); 

student *get_student(int student_number, student_node *head);

void print_students(student_node *head);

void print_student(student *myStudent);

