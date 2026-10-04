#include <stdio.h>

int n;
int e[10][10];          // Epsilon transitions
int a[10][10];          // 'a' transitions
int visited[10];        // Visited states
int closure[10][10];    // Epsilon closure of each state

// Find epsilon closure of a state
void findClosure(int s)
{
    int i;

    visited[s] = 1;
    closure[s][s] = 1;

    for(i = 0; i < n; i++)
    {
        // If epsilon transition exists
        if(e[s][i] == 1 && visited[i] == 0)
        {
            findClosure(i);
        }
    }
}

int main()
{
    int i, j, k;

    printf("Enter number of states: ");
    scanf("%d", &n);

    // Read epsilon transition matrix
    printf("Enter epsilon transition matrix:\n");

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &e[i][j]);

    // Read 'a' transition matrix
    printf("Enter 'a' transition matrix:\n");

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    // Find epsilon closure of every state
    for(i = 0; i < n; i++)
    {
        // Reset visited
        for(j = 0; j < n; j++)
            visited[j] = 0;

        findClosure(i);
    }

    // Convert NFA with epsilon to NFA without epsilon
    printf("\nNFA without epsilon:\n");

    for(i = 0; i < n; i++)
    {
        printf("%d --a--> { ", i);

        // Check all states in epsilon closure
        for(j = 0; j < n; j++)
        {
            if(closure[i][j] == 1)
            {
                // Follow 'a' transition
                for(k = 0; k < n; k++)
                {
                    if(a[j][k] == 1)
                    {
                        printf("%d ", k);
                    }
                }
            }
        }

        printf("}\n");
    }

    return 0;
}