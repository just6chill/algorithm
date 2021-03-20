//
// Created by justi on 27.02.2021.
//

#include "algorithm.h"
#include <stdio.h>

int encrypt(char text[], char password[]) {

    int AsciiText[1000];
    int AsciiPwd[1000];
    int i = 0;
    int IndexNumText;
    int IndexNumPwd;
    int SecureSum = 0;
    int index = 0;

    while(text[i] != '\0') {
        AsciiText[i] = text[i];
        i++;
    }

    IndexNumText = i - 1;
    i = 0;

    while(password[i] != '\0') {
        AsciiPwd[i] = password[i];
        i++;
    }

    IndexNumPwd = i - 1;
    i = 0;

    for(int j=0; j < IndexNumText; j++) {
        AsciiText[j] = AsciiText[j] + AsciiPwd[index];
        index++;

        if(index == IndexNumPwd){
            index = 0;
        }
    }
    index = 0;

    for(int j=0; j < IndexNumText; j++) {
        AsciiText[j] = (AsciiText[j] << AsciiPwd[index]) | (AsciiText[j] >> (32 - AsciiPwd[index]));
        index++;

        if(index == IndexNumPwd){
            index = 0;
        }
    }

    while(i < IndexNumPwd){
        SecureSum += AsciiPwd[i];
        i+=2;
    }

    for(int j=0; j < IndexNumText; j++) {
        AsciiText[j] += SecureSum;
    }

    for(int j=0; j < IndexNumText; j++) {
        printf("%d ", AsciiText[j]);
    }

    //exit the program
    return 0;
}
