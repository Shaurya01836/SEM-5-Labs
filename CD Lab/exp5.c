//write a c program to insert , delete, and display the entries in Symbol Table
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void display(char d[], void *add[], int x) {
    printf("\nSymbol Table\n");
    printf("Symbol \t addr \t\t type");
    for (int i = 0; i < x; i++) {
        if (isalpha(d[i]))
            printf("\n%c\t%p\t identifier", d[i], add[i]);
        else
            printf("\n%c\t%p\t operator", d[i], add[i]);
    }
    printf("\n");
}

void deleteSymbol(char d[], void *add[], int *x, char sym) {
    int found = 0;
    for (int i = 0; i < *x; i++) {
        if (d[i] == sym) {
            found = 1;
            free(add[i]);
            for (int j = i; j < *x - 1; j++) {
                d[j] = d[j+1];
                add[j] = add[j+1];
            }
            (*x)--;
            printf("\nSymbol %c deleted successfully.\n", sym);
            break;
        }
    }
    if (!found) {
        printf("\nSymbol %c not found in table.\n", sym);
    }
}

void main() {
    int i=0, j=0, x=0, n;
    void *p, *add[50];
    char ch, srch, b[100], d[100], c;

    printf("Expression terminated by $: ");
    while((c=getchar()) != '$'){
        b[i] = c;
        i++;
    }
    n=i-1;

    printf("Given Expression: ");
    i=0;
    while(i<=n){
        printf("%c", b[i]);
        i++;
    }

    while(j<=n){
        c=b[j];
        if(isalpha(toascii(c))){
            p=malloc(sizeof(char));
            add[x]=p;
            d[x]=c;
            x++;
            j++;
        }
        else{
            ch=c;
            if(ch == '+' || ch == '-' || ch == '*' || ch == '='){
                p=malloc(sizeof(char));
                add[x]=p;
                d[x]=ch;
                x++;
                j++;
            } else {
                j++;
            }
        }
    }

    display(d, add, x);

    printf("\nEnter symbol to delete: ");
    scanf(" %c", &srch);
    deleteSymbol(d, add, &x, srch);

    display(d, add, x);
}
