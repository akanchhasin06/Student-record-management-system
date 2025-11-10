#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "auth.c"
#include "add-rec.c"
#include "delete.c"
#include "update.c"
#include "view_rec.c"


struct student s[100];

int main() {
    authentication();

    int n = 0, choice;

    while (1) {
        printf("\n===== STUDENT RECORD SYSTEM =====\n");
        printf("1. Enter new student records\n");
        printf("2. View previous records\n");
        printf("3. Update records\n");
        printf("4. Delete records\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                add_record(s, &n);
                break;
            case 2:
                view_record(s, &n);
                break;
            case 3:
                update_record(s, &n);
                
                break;
            case 4:
                delete_record(s, &n);
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid option. Try again.\n");
        }
    }
}
