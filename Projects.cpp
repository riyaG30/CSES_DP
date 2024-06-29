#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct job
{
    ll start, end, profit;
};

bool cmp(job j1, job j2)
{
    return j1.end < j2.end;
}
int bin_search(ll value, int start, int end, job *arr)
{
    int ans = -1;
    while (start <= end)
    {
        int p = (start + end) / 2;
        if (arr[p].end < value)
        {
            ans = max(ans, p);
            start = p + 1;
        }
        else
        {
            end = p - 1;
        }
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    job *arr = new job[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].start >> arr[i].end >> arr[i].profit;
    }
    sort(arr, arr + n, cmp);
    ll dp[n];
    dp[0] = arr[0].profit;
    for (int i = 1; i < n; i++)
    {
        ll op1 = dp[i - 1];
        ll op2 = arr[i].profit;
        int index = bin_search(arr[i].start, 0, i - 1, arr);
        if (index != -1)
        {
            op2 += dp[index];
        }
        dp[i] = max(op1, op2);
    }
    cout << dp[n - 1] << endl;
    return 0;
}
