%{
int vowels = 0;
int consonants = 0;
%}

%%

[aAeEiIoOuU]     { vowels++; }
[b-df-hj-np-tv-zB-DF-HJ-NP-TV-Z]  { consonants++; }
.|\n             { /* ignore other characters */ }

%%

int main() {
    printf("Analyzing C file... (use redirection or paste input)\n");
    yylex();
    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);
    return 0;
}

int yywrap() {
    return 1;
}
