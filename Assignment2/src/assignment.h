#include "course.h"
#include "teacher.h"

typedef struct assignment
{
	struct teacher *a_teacher;
	struct course *a_course;
	}assignment;

typedef struct assignment_node
{
	int count;
	assignment *current;
	struct assignment_node *next;
	}assignment_node;

assignment_node *create_assignment_list();

assignment *create_assignment(struct teacher *a_teacher, struct course *a_course);

void add_assignment(assignment_node *head, assignment *newAssignment);

int hasAssignment(struct teacher *a_teacher, struct course *a_course, assignment_node *head);

course_node *get_teacher_courses(assignment_node *assignmentList, teacher *myTeacher);

int assign_teacher(assignment_node *assignmentList, teacher_node *teacherList, course_node *courseList, int teacher_number, int course_number);

