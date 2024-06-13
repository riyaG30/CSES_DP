#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

int main()
{

    int n, target;
    cin >> n >> target;
    int a[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 1; j <= target; ++j)
        {
            if (j - a[i] >= 0)
            {
                dp[j] = (dp[j] + dp[j - a[i]]) % mod;
            }
        }
    }

    cout << dp[target] << endl;
}