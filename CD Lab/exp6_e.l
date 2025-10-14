%{
#include <stdio.h>
%}

%%
(https?|ftp)://[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}(/[a-zA-Z0-9._~:/?#@!$&'()*+,;=%-]*)? { 
    printf("valid URL: %s\n", yytext); 
}
.+ { 
    printf("not valid: %s\n", yytext); 
}
%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter a URL: ");
    yylex();
    return 0;
}
