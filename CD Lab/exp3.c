// count total no. of operator in the given file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char ch;
    char operators[] = "+-*/%=";   // renamed from operator[]
    FILE *fp;
    int i, count = 0;

    fp = fopen("exp3.txt", "r");
    if (fp == NULL) {
        printf("Error while opening the file\n");
        exit(1);
    }

    while ((ch = fgetc(fp)) != EOF) {
        for (i = 0; i < strlen(operators); ++i) {
            if (ch == operators[i]) {
                printf("%c is operator\n", ch);
                count++;
            }
        }
    }

    printf("Number of operators = %d\n", count);
    fclose(fp);

    return 0;
}
