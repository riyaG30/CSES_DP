#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    vector<vector<int>> dp(a + 1, vector<int>(b + 1, 1e9));
    // dp[i][j] = min number of cuts to break a block of i * j into squares

    // dp[i][j] -> dp[i - some value][j], dp[i][j - some value]
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            if (i == j)
            {
                dp[i][j] = 0;
                //! no further cutting required
                continue;
                // bse case
            }
            // making vertical cut
            for (int v = 1; v <= i - 1; v++)
            {
                dp[i][j] = min(dp[i][j], dp[v][j] + dp[i - v][j] + 1);
            }
            // making horizontal cut
            for (int h = 1; h <= j - 1; h++)
            {
                dp[i][j] = min(dp[i][j], dp[i][h] + dp[i][j - h] + 1);
            }
        }
    }
    cout << dp[a][b] << endl;
    return 0;
}