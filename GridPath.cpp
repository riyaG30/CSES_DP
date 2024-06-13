#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = 1000;
const ll MOD = 1e9+7;

int N;
char c[maxN+1][maxN+1];
ll dp[maxN+1][maxN+1];

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            scanf(" %c", &c[i][j]);

    // Initialize the dp array
    dp[0][0] = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (c[i][j] == '*') {
                dp[i][j] = 0;
            } else if (i == 1 && j == 1) {
                dp[i][j] = 1;
            } else {
                ll up = 0, left = 0;
                if (j > 1) {
                    left = dp[i][j-1];
                }
                if (i > 1) {
                    up = dp[i-1][j];
                }
                dp[i][j] = (left + up) % MOD;
            }
        }
    }
    cout << dp[N][N] << endl;
    return 0;
}
