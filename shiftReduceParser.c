#include<stdio.h>
#include<string.h>

char stack[50];
char input[50];
int top=-1;

void push(char c) {
    stack[++top]=c;
}

/* Reduce i to E */
void reduce() {
    if(top>=0 && stack[top]=='i') {
        stack[top]='E';
        printf("Reduce i to E\n");
    }

    /* Reduce E+E to E */
    if(top>=2 &&
       stack[top-2]=='E' &&
       stack[top-1]=='+' &&
       stack[top]=='E') {

        top=top-2;
        stack[top]='E';

        printf("Reduce E+E to E\n");
    }
}

int main() {
    int i=0;

    printf("Enter expression using i for id: ");
    scanf("%s",input);

    while(input[i]!='\0') {

        /* SHIFT */
        push(input[i]);

        printf("Shift %c\n",input[i]);

        /* REDUCE */
        reduce();

        i++;
    }

    /* Final reduction */
    reduce();

    /* Check whether only E remains */
    if(top==0 && stack[top]=='E')
        printf("Accepted\n");
    else
        printf("Rejected\n");

    return 0;
}