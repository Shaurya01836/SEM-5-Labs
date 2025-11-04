%{
int spaces = 0;
int words = 0;
int lines = 0;
%}

%%

" "        { spaces++; }
"\t"       { spaces++; }
"\n"       { lines++; }
[^\t\n ]+  { words++; }

%%

int main() {
    yylex();
    printf("Blank spaces: %d\n", spaces);
    printf("Words: %d\n", words);
    printf("Lines: %d\n", lines);
    return 0;
}
