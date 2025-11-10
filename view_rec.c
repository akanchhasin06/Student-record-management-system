#include <stdio.h>
#include <string.h>
#include "student.h"

void print_single_record(struct student st) {
    printf("\nRoll no: %d\n", st.rollno);
    printf("Name : %s\n", st.name);
    printf("Marks:\n");
    for (int j = 0; j < 5; j++)
        printf("Subject %d = %.2f\n", j + 1, st.marks[j]);
    printf("Percentage: %.2f%%\n", st.per);
    printf("Grade: %c\n", st.grade);
}

void view_record(struct student s[], int *n) {
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

    char choice;
    int roll;
    printf("A. Display individual student record\n");
    printf("B. Display all records\n");
    printf("Enter choice (A/B): ");
    scanf(" %c", &choice);

    if (choice == 'A' || choice == 'a') {
        printf("Enter roll number: ");
        scanf("%d", &roll);
        int found = 0;
        for (int i = 0; i < *n; i++) {
            if (s[i].rollno == roll) {
                print_single_record(s[i]);
                found = 1;
                break;
            }
        }
        if (!found)
            printf("Record not found.\n");
    } else if (choice == 'B' || choice == 'b') {
        for (int i = 0; i < *n; i++)
            print_single_record(s[i]);
    } else {
        printf("Invalid choice.\n");
    }
}

