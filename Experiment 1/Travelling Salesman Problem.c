//Bhavya Agrawal 25070521016
#include <stdio.h>
#include <limits.h>
#define MAX 15
#define INF 999999
int n;
int cost[MAX][MAX];
int dp[1 << MAX][MAX];
int tsp(int mask, int pos)
{
    // All cities visited
    if (mask == (1 << n) - 1)
        return cost[pos][0];
    // Already calculated
    if (dp[mask][pos] != -1)
        return dp[mask][pos];
    int ans = INF;
    for (int city = 0; city < n; city++)
    {
        // City not visited and connection exists
        if (!(mask & (1 << city)) && cost[pos][city] != -1)
        {
            int newCost = cost[pos][city] +
                          tsp(mask | (1 << city), city);
            if (newCost < ans)
                ans = newCost;
        }
    }
    return dp[mask][pos] = ans;
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }
    // Initialize DP table
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = -1;
        }
    }
    // Start from city 0
    int answer = tsp(1, 0);
    printf("%d\n", answer);
    return 0;
}
