#include <stdio.h>
#include <string.h>

void authentication() {
    char *username = "Akanchha";
    char *password = "abc@123";

    char e_user[100], e_pass[100];
    char *eptr, *sptr;
    char ch1, ch2;

    printf("Enter username: ");
    scanf("%s", e_user);
    printf("Enter password: ");
    scanf("%s", e_pass);

    eptr = username;
    sptr = e_user;
    while (*eptr && *sptr) {
        ch1 = *eptr;
        ch2 = *sptr;

        if (ch1 >= 'A' && ch1 <= 'Z')
        ch1 += 32;
        if (ch2 >= 'A' && ch2 <= 'Z')
        ch2 += 32;

        if (ch1 != ch2) break;

        eptr++;
        sptr++;
    }

    if (*eptr == '\0' && *sptr == '\0' && strcmp(password, e_pass) == 0) {
        printf("valid user\n");
    } else {
        printf("invalid user \n");
        exit(0);


    }
}
