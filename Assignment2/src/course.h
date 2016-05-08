typedef struct course
{
	int course_number;
	char *course_name;
	int semester_number;
	}course;

typedef struct course_node
{
	int count;
	course *current;
	struct course_node *next;
	}course_node;

course_node *create_course_list();	

course *create_course(int course_number, char *course_name, int semester_number);

void add_course(course_node *head, course *newCourse);

int hasCourse(int course_number, course_node *head);

course *get_course(int course_number, course_node *head);

void print_courses(course_node *head);

void print_course(course *myCourse);
