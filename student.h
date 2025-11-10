#ifndef STUDENT_H
#define STUDENT_H

struct student {
    char name[30], grade;
    float marks[5], per;
    int rollno;
};

void add_record(struct student s[], int *n);
void view_record(struct student s[], int *n);
void update_record(struct student s[], int *n);
void delete_record(struct student s[], int *n);
void print_single_record(struct student st);
void authentication();

#endif
