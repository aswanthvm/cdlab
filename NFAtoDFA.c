#include<stdio.h>

int n;
int a[10][10];        // NFA transition table
int dfa[20][10];      // DFA states
int count=1;          // Number of DFA states

/* Check whether two states are same */
int same(int x[],int y[]) {
    int i;

    for(i=0;i<n;i++) {
        if(x[i]!=y[i])
            return 0;
    }

    return 1;
}

int main() {
    int i,j,k;
    int temp[10];
    int found;

    printf("Enter number of states: ");
    scanf("%d",&n);

    printf("Enter NFA transition matrix:\n");

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);

    /* Initial DFA state = {0} */
    dfa[0][0]=1;

    /* Process DFA states */
    for(i=0;i<count;i++) {

        /* Empty set */
        for(j=0;j<n;j++)
            temp[j]=0;

        /* Find destination states */
        for(j=0;j<n;j++) {
            if(dfa[i][j]) {

                for(k=0;k<n;k++) {
                    if(a[j][k])
                        temp[k]=1;
                }
            }
        }

        /* Check if this DFA state already exists */
        found=0;

        for(j=0;j<count;j++) {
            if(same(temp,dfa[j])) {
                found=1;
                break;
            }
        }

        /* If new state, add it */
        if(!found) {

            for(k=0;k<n;k++)
                dfa[count][k]=temp[k];

            count++;
        }
    }

    /* Display DFA states */
    printf("\nDFA States:\n");

    for(i=0;i<count;i++) {

        printf("D%d = { ",i);

        for(j=0;j<n;j++) {
            if(dfa[i][j])
                printf("%d ",j);
        }

        printf("}\n");
    }

    return 0;
}