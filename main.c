#include <stdio.h>
#include <stdlib.h>

void menu() {
    unsigned int user_choice = 0;

    printf("Choose one of the following options:\n");
    printf("\n1.Login (Enter 1)\n");
    printf("2.Registration (Enter 2)\n");
    printf("3.Exit (Enter 0)\n");

    do {
        printf("\nEnter here: ");
        scanf("%d", &user_choice);

        if (user_choice > 2) {
            printf("\nInvalid choice!\n");
        }

    } while (user_choice > 2);

    switch (user_choice) {
        case 1:
            printf("Login\n"); //Here will be the login func
            break; 
        case 2:
            printf("Registration\n"); // Here will be the registration func
            break;
        case 0:
            printf("Have a nice day/evening.");
            return;
    }
}

int main() {
    menu();

    return 0;
}