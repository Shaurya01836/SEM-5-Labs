%{
#include <stdio.h>
%}

%%
([0 1][0-9]|2[0-3]):[0-5][0-9]:[0-5][0-9] { printf("valid: %s\n", yytext); }
.+ { printf("not valid: %s\n", yytext); }
%%

int yywrap() {
    return 1;
}

int main() {
    printf("Please enter: ");
    yylex();
    return 0;
}
