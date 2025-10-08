// count the each char in the given file

#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){
    FILE *fp;
    char string[100];
    int c = 0, count[26] = {0}, x;

    fp = fopen("exp.txt", "r");
    if(fp == NULL){
        printf("Error while opening the file.\n");
        return 1;
    }

    while(fscanf(fp , "%s", string) != EOF){
        c = 0;
        while(string[c] != '\0'){
            char ch = tolower(string[c]);
            if(ch>='a' && ch<='z'){
                x=ch-'a';
                count[x]++;
            }
            c++;
        }
    }
    fclose(fp);

    for(c=0; c<26; c++){
        printf("%c occurs %d times in the string.\n", c+'a', count[c]);
    }
    return 0;
}