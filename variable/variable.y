%{
#include<stdio.h>
%}

%token ID

%%

S : ID '\n' {
        printf("Valid Variable\n");
    }
  ;

%%

int main() {
    printf("Enter variable: ");
    yyparse();
    return 0;
}

int yyerror(char *s) {
    printf("Invalid Variable\n");
    return 0;
}