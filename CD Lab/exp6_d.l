%{
#include <stdio.h>
%}

%%
(0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[0-2])/([0-9]{4}) {
    printf("valid date: %s\n", yytext);
}
.+ {
    printf("not valid: %s\n", yytext);
}
%%

int yywrap() {
    return 1;
}

int main() {
    printf("Please enter: ");
    yylex();
    return 0;
}
