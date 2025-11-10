#include <stdio.h>
#include <string.h>
#include "student.h"

void update_record(struct student s[], int *n) {
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
    printf("Enter roll number to update: ");
    scanf("%d", &roll);

    for (int i = 0; i < *n; i++) {
        if (s[i].rollno == roll) {
            printf("Enter new name: ");
            getchar();
            fgets(s[i].name, 30, stdin);
            s[i].name[strcspn(s[i].name, "\n")] = '\0';

            float sum = 0;
            printf("Enter new marks for 5 subjects:\n");
            for (int j = 0; j < 5; j++) {
                printf("Subject %d: ", j + 1);
                scanf("%f", &s[i].marks[j]);
                sum += s[i].marks[j];
            }

            s[i].per = sum / 5.0;
            s[i].grade = (s[i].per >= 90) ? 'A' :
                         (s[i].per >= 80) ? 'B' :
                         (s[i].per >= 70) ? 'C' :
                         (s[i].per >= 60) ? 'D' :
                         (s[i].per >= 50) ? 'E' : 'F';

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
        printf("Error opening file for writing.\n");
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
    printf("Record updated successfully.\n");
}
