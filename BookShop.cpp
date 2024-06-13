#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = 100;
const int maxX = 1e6;
const ll MOD = 1e9 + 7;
ll fun(int i, vector<ll> pages, vector<ll> price, ll x)
{
    if (i < 0)
        return 0;
    if (i == 0)
    {
        if (x - price[0] >= 0)
        {
            return pages[0];
        }
        return 0;
    }
    int take = -1e9;
    if (x - price[i] >= 0)
    {
        take = pages[i] + fun(i - 1, pages, price, x - price[i]);
    }
    int not_take = 0 + fun(i - 1, pages, price, x);
    return max(take, not_take);
}
int main()
{
    ll n, x;
    cin >> n >> x;
    vector<ll> pages(n, 0);
    vector<ll> price(n, 0);

    for (ll i = 0; i < n; i++)
    {
        cin >> price[i];
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> pages[i];
    }

    //
    // cout << fun(n - 1, pages, price, x);
    vector<vector<int>> dp(n, (vector<int>(x + 1, 0)));

    // dp[i][j] = number of pages we can read from books[0......i] such that we are allowed to spend j
    for (int j = 0; j <= x; j++)
    {
        if (j >= price[0])
        {
            dp[0][j] = pages[0];
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            int take = INT_MIN;
            if (j - price[i] >= 0)
            {
                take = pages[i] + dp[i - 1][j - price[i]];
            }
            int not_take = dp[i - 1][j];
            dp[i][j] = max(take, not_take);
        }
    }
    cout << dp[n - 1][x];
    return 0;
}