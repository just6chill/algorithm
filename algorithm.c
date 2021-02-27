//
// Created by justi on 27.02.2021.
//

#include "algorithm.h"
#include <stdio.h>

int encrypt(char text[], char password[]) {

    //the text string converted into its ascii values
    unsigned long long int AsciiOfText[1000]={};

    //the password string converted into its ascii values
    long long int AsciiOfPWD[1000]={};

    //the sum of all ascii values from the text string
    long long int PWDAsciiSum;

    //values for the loops
    int check = 0;
    int i=0;
    int j;

    //converting text string to ascii values
    while(text[i]!='\0') {
        AsciiOfText[i] = text[i];
        i++;
    }

    //converting password string to ascii values
    while(password[i]!='\0') {
        AsciiOfPWD[i] = password[i];
        i++;
    }

    //counting together every ascii value to calculate sum
    for(j=0;j<i-1;j++) {
        PWDAsciiSum += AsciiOfPWD[i];

    }

    //cutting away everything except the last 3 digits
    PWDAsciiSum = PWDAsciiSum % 1000;

    //multiplying the password sum to each of the ascii text values
    for(j=0;j<i-1;j++) {
        AsciiOfText[j] = AsciiOfText[j] * PWDAsciiSum;
    }

    //print out the entire encrypted string
    printf("\nencrypted code:\n");
    for(j=0;j<i-1;j++) {
        if(AsciiOfText[j] != check) {
            printf("%lld ", AsciiOfText[j]);
        }
    }

    //exit the program
    return 0;
}
