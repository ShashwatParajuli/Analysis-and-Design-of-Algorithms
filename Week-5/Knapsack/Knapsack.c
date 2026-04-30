#include <stdio.h>

#define MAX 100

int max(int a, int b) {
    return (a > b) ? a : b;
}

void knapsack(int n, int W, int wt[], int val[]) {
    int dp[MAX][MAX];

    // Build DP table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i-1] <= w)
                dp[i][w] = max(dp[i-1][w], val[i-1] + dp[i-1][w - wt[i-1]]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }

    printf("\nMaximum Profit: %d\n", dp[n][W]);

    // Backtracking to find selected items
    int w = W;
    int selected[MAX];
    int count = 0;

    for (int i = n; i > 0 && w > 0; i--) {
        if (dp[i][w] != dp[i-1][w]) {
            selected[count++] = i - 1;
            w -= wt[i-1];
        }
    }

    // Print in correct order
    printf("Selected items:\n");
    for (int i = count - 1; i >= 0; i--) {
        int idx = selected[i];
        printf("Item %d -> Weight: %d, Value: %d\n", idx, wt[idx], val[idx]);
    }
}

int main() {
    int n, W;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int wt[n], val[n];

    printf("Enter weights:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &wt[i]);
    }

    printf("Enter values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val[i]);
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    knapsack(n, W, wt, val);

    return 0;
}
