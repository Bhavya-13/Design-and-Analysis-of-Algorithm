//Bhavya Agrawal 25070521016
#include <stdio.h>

int main()
{
    int n, W;
    scanf("%d", &n);

    int value[n], weight[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &value[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &weight[i]);

    scanf("%d", &W);

    int dp[W + 1];

    for (int w = 0; w <= W; w++)
        dp[w] = 0;

    for (int i = 0; i < n; i++)
    {
        for (int w = W; w >= weight[i]; w--)
        {
            if (dp[w] < dp[w - weight[i]] + value[i])
                dp[w] = dp[w - weight[i]] + value[i];
        }
    }

    printf("%d\n", dp[W]);

    return 0;
}
