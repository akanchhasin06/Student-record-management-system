#include <stdio.h>
#include "student.h"  
#include <string.h>


void delete_record(struct student s[], int *n) {
    FILE *p = fopen("record.txt", "r");
    if (!p) {
        printf("Error opening file.\n");
        return;
    }

    int count = 0;
    while (fscanf(p, "%d\n", &s[count].rollno) == 1) {
        fgets(s[count].name, 30, p);
        s[count].name[strcspn(s[count].name, "\n")] = '\0';
        for (int j = 0; j < 5; j++) {
            fscanf(p, "%f", &s[count].marks[j]);
        }
        fscanf(p, "\n%f\n %c\n", &s[count].per, &s[count].grade);
        count++;
    }
    fclose(p);
    *n = count;

    int roll, found = 0;
    printf("Enter roll number to delete: ");
    scanf("%d", &roll);

    for (int i = 0; i < *n; i++) {
        if (s[i].rollno == roll) {
            for (int j = i; j < *n - 1; j++) {
                s[j] = s[j + 1];
            }
            (*n)--;
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Record not found.\n");
        return;
    }

    p = fopen("record.txt", "w");
    if (!p) {
        printf("Error saving file.\n");
        return;
    }

    for (int i = 0; i < *n; i++) {
        fprintf(p, "%d\n%s\n", s[i].rollno, s[i].name);
        for (int j = 0; j < 5; j++) {
            fprintf(p, "%.2f ", s[i].marks[j]);
        }
        fprintf(p, "\n%.2f\n%c\n", s[i].per, s[i].grade);
    }
    fclose(p);

    printf("Record deleted successfully.\n");
}

