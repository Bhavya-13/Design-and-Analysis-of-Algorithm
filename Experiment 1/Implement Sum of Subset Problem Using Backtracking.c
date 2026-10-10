//Bhavya Agrawal 25070521016
#include <stdio.h>
#define MAX 100
int arr[MAX], path[MAX];
int n, target, found = 0;
void solve(int start, int sum, int size)
{
    // try the later elements first, so subsets come out in reverse order of discovery
    for (int i = n - 1; i >= start; i--)
    {
        path[size] = arr[i];                    // choose arr[i]
        solve(i + 1, sum + arr[i], size + 1);   // explore deeper first
        // after the deeper subsets are printed, check this subset
        if (sum + arr[i] == target)
        {
            found = 1;
            for (int k = 0; k <= size; k++)
            {
                //if (k) printf(" ");
                printf("%d ", path[k]);
            }
            printf("\n");
        }
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    scanf("%d", &target);
    solve(0, 0, 0);
    if (!found)
        printf("-1\n");
    return 0;
}
