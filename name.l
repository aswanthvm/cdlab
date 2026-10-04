%{
#include<stdio.h>
%}

%%

.*ASWA.*    { printf("Rejected\n"); }
.*          { printf("Accepted\n"); }

%%

int main() {
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}