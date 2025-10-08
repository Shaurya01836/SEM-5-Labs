%{
#include <stdio.h>
%}

digit [0-9]

%%
{digit}+ { printf("it is a digit\n"); }
%%

int yywrap() {
    return 1;
}

int main() {
    printf("Please enter a number :");
    yylex();
    return 0;
}
