typedef struct teacher
{
	int teacher_number;
	char *firstName;
	}teacher;

typedef struct teacher_node
{
	int count;
	struct teacher *current;
	struct teacher_node *next;
	}teacher_node;

teacher_node *create_teacher_list();

teacher *create_teacher(int teacher_number, char *firstName);

void add_teacher(teacher_node *head, teacher *newTeacher);

int hasTeacher(int teacher_number, teacher_node *head);

teacher *get_teacher(int teacher_number, teacher_node *head);

void print_teachers(teacher_node *head);

void print_teacher(teacher *myTeacher);
