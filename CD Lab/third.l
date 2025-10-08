%{
#include <stdio.h>
%}


%%
"int" { printf("%s it is a keyword\n", yytext); }
"auto" { printf("%s it is a keyword\n", yytext); }
[a-zA-Z]+ { printf("%s it is not a keyword\n", yytext); }

%%

int yywrap() {
    return 1;
}

int main() {
    printf("Please enter :");
    yylex();
    return 0;
}
