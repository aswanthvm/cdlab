#include<stdio.h>
#include<string.h>

char stack[50];
char input[50];
int top=-1;

void push(char c) {
    stack[++top]=c;
}

void pop() {
    top--;
}

/* Return precedence of operator */
int precedence(char c) {
    if(c=='+' || c=='-')
        return 1;

    if(c=='*' || c=='/')
        return 2;

    return 0;
}

int main() {
    int i=0;
    char a,b;

    printf("Enter expression using i for id: ");
    scanf("%s",input);

    push('$');

    while(input[i]!='\0') {

        a=stack[top];
        b=input[i];

        /* Operand: shift */
        if(b=='i') {
            push(b);
            i++;
            printf("Shift i\n");
        }

        /* Higher precedence: shift */
        else if(precedence(b)>precedence(a)) {
            push(b);
            i++;
            printf("Shift %c\n",b);
        }

        /* Lower/equal precedence: reduce */
        else {
            pop();
            printf("Reduce\n");
        }
    }

    /* Reduce remaining symbols */
    while(top>0) {
        pop();
        printf("Reduce\n");
    }

    printf("Accepted\n");

    return 0;
}