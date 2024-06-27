#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a, b;
    cin >> a >> b;
    int n = a.size();
    int m = b.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1e9));
    //! dp[i][j] = min steps to match the first i characters of first string with first j characters of second string
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = i;
        // first string has i characters remaining
        // second string has finished
    }
    for (int j = 0; j <= m; j++)
    {
        dp[0][j] = j;
        // second string has j characters remaining
        // first string has exhausted
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[i - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                // replace character to match
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            // skip ith character or add one character after jth character
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);

            // skip jth character or add one character after ith character
            dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}