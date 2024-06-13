#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e6;
const int INF = 0x3f3f3f3f;

int n, dp[maxN+1];

int main()
{
    int n;
    cin >> n;
    
    fill(dp+1, dp+n+1, INF);
    dp[0] = 0; // Base case: 0 steps are required to reduce 0 to 0
    
    for (int i = 1; i <= n; i++)
    {
        int d = i;
        while (d > 0)
        {
            int digit = d % 10;
            if (digit != 0)
            {
                dp[i] = min(dp[i], dp[i - digit] + 1);
            }
            d /= 10;
        }
    }

    cout << dp[n] << endl;
    return 0;
}
