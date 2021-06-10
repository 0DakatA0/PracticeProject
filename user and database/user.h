#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/*кода има нужда от users.txt и users папка за да работи

  user_t - структура от данни, в която се съхраняват потрбителското име,
  хеша на паролата и баланса на сметката ма потребителя.

  hash_password - тази функция хешира паролата.

  registraton - въвежда се потребителско име, проверява се дали има саъщото име,
  ако няма се създава, след което се иска парола, която се хешира и се запазва 
  всичко в това в бинарен файл с името на потребителя.

  login - функцията намира файла с подаденото потребителско име, 
  след което се подава парола, и се проверява дали е правилна, и ако е,
  то тогава функцията връща указател към структура са данните на потребителя.

  read_user - тази функция принтира всичко свързано с данните на избрания потребител.*/

#define MAX_USERNAME_LENGTH 13
#define MAX_PASSWORD_LENGTH 25
#define MAX_USERS 20

struct user_t{
    char username[MAX_USERNAME_LENGTH];
    int hash;
    float ballance;
};

int hash_password(char* password){
    int counter = MAX_PASSWORD_LENGTH - 1;
    int hash = 0;

    for(int i = 0; password[i] != '\0'; i++){
        hash += (int)password[i] << counter;
        counter--;
    }

    return hash;
}

void registration(){
    struct user_t user;

    printf("Enter username: ");
    fgets(user.username, MAX_USERNAME_LENGTH, stdin);

    FILE* users = fopen("./users.txt", "r+");
    char buffer[MAX_USERNAME_LENGTH];

    while(fgets(buffer, MAX_USERNAME_LENGTH, users) != NULL){
        
        if(!strcmp(buffer, user.username)){
            printf("Username is already in use!\n");
            return;
        }
    }

    fprintf(users, user.username);
    fputs("\n", users);
    fclose(users);

    printf("Enter passowrd: ");
    char password[21];
    scanf("%[^\n]%*c", password);

    user.hash = hash_password(password);

    user.ballance = 0;

    char path_to_user[25] = "./users/";
    strcat(path_to_user ,user.username);
    strcat(path_to_user, ".bin");

    FILE* user_data = fopen(path_to_user, "wb");
    fwrite(&user, sizeof(struct user_t), 1, user_data);
    fclose(user_data);
}

struct user_t* login(){
    char username[MAX_USERNAME_LENGTH];
    printf("Username: ");
    scanf("%[^\n]%*c", username);

    char path_to_user[25] = "./users/";
    strcat(path_to_user, username);
    strcat(path_to_user, ".bin");

    FILE* user_data = fopen(path_to_user, "rb");

    if(user_data == NULL){
        printf("Invalid user!");
        return NULL;
    }

    struct user_t* user = (struct user_t*)malloc(sizeof(struct user_t));
    fread(user, sizeof(struct user_t), 1, user_data);
    fclose(user_data);

    char password[MAX_PASSWORD_LENGTH];

    printf("Password: ");
    scanf("%[^\n]%*c", password);

    int hash = hash_password(password);
    if(hash == user->hash){
        return user;
    }

    printf("Wrong password!");
    return NULL;
}

void read_user(struct user_t* user){
    if(user != NULL){
        printf("Username: %s\n", user->username);
        //printf("hash: %d\n", user->hash);
        return;
    }

    printf("Something is wrong.");
}