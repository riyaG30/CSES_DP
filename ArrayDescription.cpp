#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
//? any 2 adjacent element should have diff b/w <=1

bool valid(int x, int m)
{
    return x >= 1 && x <= m;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    // dp[i][k] = number of ways to build a prefix of size i
    // such that the last element of the prefix is k
    //! dp[i][x] - > the no. of elememts  to fill prefix, till index i, such that ith elemt is inserted is x
    //! prefix of size i, and at i-1 , value is x

    // base case dp[1][k] = 1 if (a[0] = 0 OR a[0] = k)
    for (int i = 1; i <= m; i++)
    {

        // agla valvue 0 nahi hai, aur jo chahiiw, wo bh mahi hai  matlab ki 0
        if (a[0] == i || a[0] == 0)
            dp[1][i] = 1;
    }

    for (int i = 2; i <= n; i++)
    {
        for (int k = 1; k <= m; k++)
        {
            // finding dp[i][k] here
            if (a[i - 1] != 0 && a[i - 1] != k)
            {
                dp[i][k] = 0;
                continue;
            }

            for (int prev = k - 1; prev <= k + 1; prev++)
            {
                if (!valid(prev, m))
                {
                    continue;
                }
                // transition
                dp[i][k] = (dp[i][k] + dp[i - 1][prev]) % MOD;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        ans = (ans + dp[n][i]) % MOD;
    }

    // final subproblem
    cout << ans << endl;
}
// final answer is summation of all dp(n,i)