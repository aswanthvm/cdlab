#include<stdio.h>

int main() {
    int n,m,i,j,k,change;
    int t[10][5];       // DFA transition table
    int f[10];          // Final states
    int g[10];          // Groups

    printf("Enter number of states: ");
    scanf("%d",&n);

    printf("Enter number of symbols: ");
    scanf("%d",&m);

    /* Read transition table */
    printf("Enter transition table:\n");

    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&t[i][j]);

    /* Enter final states
       1 = final
       0 = non-final */
    printf("Enter final states (1/0):\n");

    for(i=0;i<n;i++)
        scanf("%d",&f[i]);

    /* Initial groups */
    for(i=0;i<n;i++)
        g[i]=f[i];

    /* Repeat until no more splitting */
    do {
        change=0;

        for(i=0;i<n;i++) {
            for(j=i+1;j<n;j++) {

                /* Compare states in same group */
                if(g[i]==g[j]) {

                    for(k=0;k<m;k++) {

                        /* Different destination groups */
                        if(g[t[i][k]]!=g[t[j][k]]) {

                            g[j]=g[i]+1;
                            change=1;
                            break;
                        }
                    }
                }
            }
        }

    } while(change);

    /* Display minimized groups */
    printf("\nMinimized DFA:\n");

    for(i=0;i<n;i++)
        printf("State %d -> Group %d\n",i,g[i]);

    return 0;
}