#include<stdio.h>
#include<string.h>

char input[50];
int i=0;

/* Function for E */
void E() {
    T();

    if(input[i]=='+') {
        i++;
        E();
    }
}

/* Function for T */
void T() {
    if(input[i]=='i')
        i++;
    else
        printf("Invalid\n");
}

int main() {
    printf("Enter expression using i for id: ");
    scanf("%s",input);

    E();

    /* Check whether complete input is consumed */
    if(input[i]=='\0')
        printf("Accepted\n");
    else
        printf("Rejected\n");

    return 0;
}