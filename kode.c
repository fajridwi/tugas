#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 2024
#define MIN_LENGTH 2023

void lessThanRequired(int *lengthOfText) {
    printf("The length of your text is less than specified, please update your text\n");
    printf("Length Before : %d\n", *lengthOfText);
    *lengthOfText = MIN_LENGTH;
}

void equalThanRequired(int *lengthOfText) {
    printf("Thank you, Your text length is correct\n");
}

void moreThanRequired(int *lengthOfText) {
    printf("Your text is too long, please reduce the text\n");
    printf("Length Before : %d\n", *lengthOfText);
    *lengthOfText -= MAX_LENGTH - MIN_LENGTH;
}

int checkLengthRequirement(char* text) {
    int length = strlen(text);
    return (length < MIN_LENGTH) ? 0 : ((length == MIN_LENGTH) ? 1 : 2);
}

int main() {
    int lengthOfText, selectOption;
    FILE *fptr = NULL;
    char text[MAX_LENGTH];

    fptr = fopen("file.txt", "w");
    fprintf(fptr, "Tempor sunt quis magna reprehenderit irure irure mollit ex reprehenderit incididunt ex enim. Do eu cillum fugiat sunt reprehenderit. Aute in consequat nulla irure pariatur occaecat velit. Occaecat anim Lorem nulla exercitation dolore et. Qui ea Lorem in consequat nisi exercitation id ad aliqua Lorem anim eu ad.");
    fclose(fptr);

    fptr = fopen("file.txt", "r");
    if(fptr == NULL){
        printf("Error");
        exit(1);
    }

    fgets(text, MAX_LENGTH, fptr);
    fclose(fptr);

    selectOption = checkLengthRequirement(text);

    void (*lengthChecks[])(int *) = {lessThanRequired, equalThanRequired, moreThanRequired};
    lengthOfText = strlen(text);
    lengthChecks[selectOption](&lengthOfText);

    printf("\nThe Length is updated to %d", MIN_LENGTH);

    return 0;
}