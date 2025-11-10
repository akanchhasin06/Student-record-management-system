#include <stdio.h>
#include <string.h>
#include "student.h"


void add_record(struct student s[], int *n) {
    int new_count;
    printf("Enter number of students to add: ");
    scanf("%d", &new_count);
    getchar();

    FILE *p = fopen("record.txt", "a"); 
    if (!p) {
        printf("Error opening file.\n");
        return;
    }

    for (int i = 0; i < new_count; i++) {
        float sum = 0;
        int ind = *n + i;

        printf("\nEnter roll number: ");
        scanf("%d", &s[ind].rollno);
        getchar();

        printf("Enter name: ");
        fgets(s[ind].name, 30, stdin);
        s[ind].name[strcspn(s[ind].name, "\n")] = '\0';

        printf("Enter marks in five subjects:\n");
        for (int j = 0; j < 5; j++) {
            printf("Subject %d: ", j + 1);
            scanf("%f", &s[ind].marks[j]);
            sum += s[ind].marks[j];
        }

        s[ind].per = sum / 5.0;
        s[ind].grade = (s[ind].per >= 90) ? 'A' :
                       (s[ind].per >= 80) ? 'B' :
                       (s[ind].per >= 70) ? 'C' :
                       (s[ind].per >= 60) ? 'D' :
                       (s[ind].per >= 50) ? 'E' : 'F';

       
        fprintf(p, "%d\n%s\n", s[ind].rollno, s[ind].name);
        for (int j = 0; j < 5; j++) {
            fprintf(p, "%.2f ", s[ind].marks[j]);
        }
        fprintf(p, "\n%.2f\n%c\n", s[ind].per, s[ind].grade);
    }

    *n += new_count;
    fclose(p);
    printf("Student records added and saved successfully.\n");
}



