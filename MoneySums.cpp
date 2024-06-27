//! dp[i] = set of sums possible with coins from 1 to i th  coin
//! transition -> dp[i] => add or not add the current coint to all sums possible in the previous state
//! base case = >
//!  dp[0] = 0
// final answer dp[n]

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // Initialize a set to store all possible sums
    set<int> possible_sums;
    possible_sums.insert(0); // base case: sum of zero

    // Iterate through each coin
    for (int i = 0; i < n; i++)
    {
        // Create a temporary set to store new sums
        set<int> new_sums;
        for (int sum : possible_sums)
        {
            new_sums.insert(sum + arr[i]);
        }
        // Add new sums to the possible sums set
        possible_sums.insert(new_sums.begin(), new_sums.end());
    }

    // Remove the base case sum (zero)
    possible_sums.erase(0);

    // Output the number of distinct sums
    cout << possible_sums.size() << endl;
    // Output all possible sums in increasing order
    for (int sum : possible_sums)
    {
        cout << sum << " ";
    }
    cout << endl;
    return 0;
}