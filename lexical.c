#include<stdio.h>
#include<ctype.h>
#include<string.h>

int keyword(char s[]) {
    char k[][10]={"int","float","char","if","else","while","for"};
    int i;

    for(i=0;i<7;i++) {
        if(strcmp(s,k[i])==0)
            return 1;
    }

    return 0;
}

int main() {
    char ch,s[20];
    int i;

    printf("Enter input (end with #):\n");

    while((ch=getchar())!='#') {

        /* Ignore spaces, tabs and newlines */
        if(ch==' '||ch=='\t'||ch=='\n')
            continue;

        /* Check for keyword or identifier */
        if(isalpha(ch)) {
            i=0;

            while(isalnum(ch)) {
                s[i++]=ch;
                ch=getchar();
            }

            s[i]='\0';

            if(keyword(s))
                printf("%s : Keyword\n",s);
            else
                printf("%s : Identifier\n",s);

            ungetc(ch,stdin);
        }

        /* Check for number */
        else if(isdigit(ch)) {
            i=0;

            while(isdigit(ch)) {
                s[i++]=ch;
                ch=getchar();
            }

            s[i]='\0';

            printf("%s : Number\n",s);

            ungetc(ch,stdin);
        }

        /* Check for operators */
        else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='=')
            printf("%c : Operator\n",ch);

        /* Check for special symbols */
        else if(ch==';'||ch==','||ch=='('||ch==')'||
                ch=='{'||ch=='}')
            printf("%c : Special Symbol\n",ch);

        else
            printf("%c : Unknown\n",ch);
    }

    return 0;
}