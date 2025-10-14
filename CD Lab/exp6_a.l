%{
#include <stdio.h>
%}


%%
[6-9][0-9]{9} {printf("valid" , yytext);}
.+ {printf("not valid: %s\n", yytext);}

%%

int yywrap() {
    return 1;
}

int main() {
    printf("Please enter :");
    yylex();
    return 0;
}
