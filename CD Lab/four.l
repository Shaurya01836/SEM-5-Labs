%{
#include <stdio.h>
int word_count = 0 ; 
%}


%%
[a-zA-Z]+ {word_count++;}
[ \t\n]+
.
%%

int yywrap() {
    return 1;
}

int main() {
    printf("Please enter :");
    yylex();
    printf("%d", word_count);
    return 0;
}
