#include <stdio.h>
#include "algorithm.h"

#define BUFFER 1000

int main() {

    //strings to store input
    char input[BUFFER];
    char password[BUFFER];

    //store text
    printf("type the text you want to encrypt:\n");
    fgets((char *) input, BUFFER, stdin);

    //store password
    printf("your password:\n");
    fgets(password, BUFFER, stdin);

    //call our encryption function and passing input(text) and password(password)
    encrypt(input, password);
}