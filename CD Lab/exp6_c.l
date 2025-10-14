%{
#include <stdio.h>
%}

%%
[a-zA-Z_][a-zA-Z0-9_]* { printf("valid identifier: %s\n", yytext); }
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
