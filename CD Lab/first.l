%{
    #include <stdio.h>

%}

%%
%%
int yywrap(){
    return 1 ; 
}
int main(){
    printf("Hello World");
    yylex();
    return 0 ; 
}