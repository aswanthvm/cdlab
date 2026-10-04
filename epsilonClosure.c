#include <stdio.h>

int n;
int a[10][10];       // Epsilon transition matrix
int visited[10];     // Stores visited states

// Function to find epsilon closure of a state
void closure(int s)
{
    int i;

    // Include the current state in its own closure
    visited[s] = 1;

    // Check all states
    for(i = 0; i < n; i++)
    {
        // If epsilon transition exists
        // and the state is not visited
        if(a[s][i] == 1 && visited[i] == 0)
        {
            // Visit that state
            closure(i);
        }
    }
}

int main()
{
    int i, j;

    // Read number of states
    printf("Enter number of states: ");
    scanf("%d", &n);

    // Read epsilon transition matrix
    printf("Enter epsilon transition matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    // Find epsilon closure of every state
    for(i = 0; i < n; i++)
    {
        // Reset visited array before finding new closure
        for(j = 0; j < n; j++)
        {
            visited[j] = 0;
        }

        // Find closure of state i
        closure(i);

        // Print the result
        printf("E-closure(%d) = { ", i);

        for(j = 0; j < n; j++)
        {
            if(visited[j] == 1)
            {
                printf("%d ", j);
            }
        }

        printf("}\n");
    }

    return 0;
}