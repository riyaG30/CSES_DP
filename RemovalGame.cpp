#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[5005][5005];
vector<int> arr;
ll fun(ll i, ll j)
{
    // base case
    if (i > j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    ll op1 = arr[i] + min(fun(i + 2, j), fun(i + 1, j - 1));
    ll op2 = arr[j] + min(fun(i + 1, j - 1), fun(i, j - 2));
    return dp[i][j] = max(op1, op2);
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    memset(dp, -1, sizeof(dp));
    cout << fun(0, n - 1);
    return 0;
}