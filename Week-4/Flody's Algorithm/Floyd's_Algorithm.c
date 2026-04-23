#include <stdio.h>

#define MAX 10
#define INF 999

void main()
{
    int cost[MAX][MAX], n;
    int i, j, k;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix:\n");
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);

            if(i != j && cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    // Floyd's Algorithm
    for(k = 1; k <= n; k++)
    {
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                if(cost[i][j] > cost[i][k] + cost[k][j])
                {
                    cost[i][j] = cost[i][k] + cost[k][j];
                }
            }
        }
    }

    printf("\nAll Pair Shortest Path Matrix:\n");
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(cost[i][j] == INF)
                printf("INF\t");
            else
                printf("%d\t", cost[i][j]);
        }
        printf("\n");
    }

    getch();
}
