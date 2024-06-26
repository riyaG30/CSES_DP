#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
//? any 2 adjacent element should have diff b/w <=1
int main()
{

    ll n, m;
    cin >> n >> m;
    vector<ll> arr(n, 0);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<vector<ll>> dp(n, vector<ll>(m + 1, 0));
    //! dp[i][x] - > the no. of elememts  to fill prefix, till index i, such that ith elemt is inserted is x
    //! prefix of size i, and at i-1 , value is x
    // base cases

    for (int x = 0; x <= m; x++)
    {
        if (arr[0] == 0)
        {
            // we can fill any number no issues
            dp[0][x] = 1;
        }
        else if (arr[0] == x)
        {
            dp[0][x] = 1;
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int x = 0; x <= m; x++)
        {
            if (arr[i] != 0 && arr[i] != x)
            {
                dp[i][x] = 0;
            }
            else
            {
                dp[i][x] = dp[i - 1][x];
                if (x > 1)
                    dp[i][x] = (dp[i][x] + dp[i - 1][x - 1]) % MOD;
                if (x < m)
                    dp[i][x] = (dp[i][x] + dp[i - 1][x + 1]) % MOD; // means 3 ways, as x-1,x,x+1 are 3 possible values
            }
        }
    }
    ll result = 0;
    for (int x = 1; x <= m; x++)
    {
        result = (result + dp[n - 1][x]) % MOD;
    }
    cout << result;
    return 0;
}