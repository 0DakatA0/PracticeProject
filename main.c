#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

int dayTime() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    if (tm.tm_hour >= 18) {
        return 1;
    }

    return 0;
}

char* stabilize_letter_case(char* menu_option_string) {
    unsigned char *menu_option_string_pointer = (unsigned char *)menu_option_string;

    while (*menu_option_string_pointer) {
        *menu_option_string_pointer = tolower((unsigned char)*menu_option_string_pointer);
        menu_option_string_pointer++;
    }

    return menu_option_string;
}
 
int validate(char* menu_option_string) {
    menu_option_string = stabilize_letter_case(menu_option_string);
    if(
        strcmp(menu_option_string, "sign in") == 0 ||
        strcmp(menu_option_string, "sign up") == 0 ||
        strcmp(menu_option_string, "exit") == 0 ||
        strcmp(menu_option_string, "help") == 0
    ) return 1;
    return 0;
}

void menu() {
    char menu_option_string[50] = {0};
    int is_menu_option_valid = 0;

    while(1) {
        printf("Choose one of the following options:\n");
        printf("\n1.Sign In [sign in]\n2.Sign Up [sign up] \n3.Exit [exit] \n4.Help [help]\n");

        do {
            printf("\n: ");
            scanf("%s", menu_option_string);

            is_menu_option_valid = validate(menu_option_string);
            if(!is_menu_option_valid) {
                printf("Option not found. Type help for info.\n");
            }
            printf("%s", menu_option_string);

        } while (!is_menu_option_valid);

        if(strcmp(menu_option_string, "help") == 0) {
            printf("\nUsage [Commands]: \n   sign in (Case Insensitive) \n   sign up (Case Insensitive) \n   exit (Case Insensitive) \n   help (Case Insensitive)");
        }
        else if(strcmp(menu_option_string, "exit") == 0) {
            return 0;
        }
        // logic here
    }

}

int main() {
    menu();

    return 0;
}