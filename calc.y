%{
#include<stdio.h>
%}

%token NUMBER

%left '+' '-'
%left '*' '/'

%%

E : E '+' E {
        $$=$1+$3;
    }
  | E '-' E {
        $$=$1-$3;
    }
  | E '*' E {
        $$=$1*$3;
    }
  | E '/' E {
        $$=$1/$3;
    }
  | '(' E ')' {
        $$=$2;
    }
  | NUMBER {
        $$=$1;
    }
  ;

%%

int main() {
    printf("Enter expression: ");
    yyparse();
    return 0;
}

int yyerror(char *s) {
    printf("Invalid Expression\n");
    return 0;
}