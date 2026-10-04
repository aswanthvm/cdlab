#include<stdio.h>
#include<ctype.h>
#include<string.h>

char prod[10][20];
int n;

/* Find FIRST */
void first(char c) {
    int i;

    /* If terminal, print it */
    if(!isupper(c)) {
        printf("%c ",c);
        return;
    }

    /* Find production of the non-terminal */
    for(i=0;i<n;i++) {
        if(prod[i][0]==c) {

            /* If first symbol is terminal */
            if(!isupper(prod[i][2]))
                printf("%c ",prod[i][2]);

            /* If first symbol is non-terminal */
            else
                first(prod[i][2]);
        }
    }
}

/* Find FOLLOW */
void follow(char c) {
    int i,j;

    /* Start symbol gets $ */
    if(c==prod[0][0])
        printf("$ ");

    /* Search all productions */
    for(i=0;i<n;i++) {
        for(j=2;j<strlen(prod[i]);j++) {

            /* Find the required non-terminal */
            if(prod[i][j]==c) {

                /* If another symbol follows it */
                if(prod[i][j+1]!='\0') {

                    /* If next symbol is terminal */
                    if(!isupper(prod[i][j+1]))
                        printf("%c ",prod[i][j+1]);

                    /* If next symbol is non-terminal */
                    else
                        first(prod[i][j+1]);
                }
            }
        }
    }
}

int main() {
    int i;
    char c;

    printf("Enter number of productions: ");
    scanf("%d",&n);

    printf("Enter productions like E=TA:\n");

    for(i=0;i<n;i++)
        scanf("%s",prod[i]);

    printf("\nEnter non-terminal: ");
    scanf(" %c",&c);

    printf("FIRST(%c) = { ",c);
    first(c);
    printf("}\n");

    printf("FOLLOW(%c) = { ",c);
    follow(c);
    printf("}\n");

    return 0;
}