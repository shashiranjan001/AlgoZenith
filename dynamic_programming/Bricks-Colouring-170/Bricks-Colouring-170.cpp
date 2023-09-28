#include <iostream>
#include <vector>

int main () {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int t;
    std::cin >> t;
    long long mod = 1e9 + 7;
    while (t--) {
        int n, m, k;
        std::cin >> n >> m >> k;
        std::vector<std::vector<long long int> > dp(n+1, std::vector<long long int>(k+1, 0));
        dp[1][0] = m;

        for (int i = 2; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                dp[i][j] = dp[i-1][j];
                if (j) dp[i][j] += dp[i-1][j-1]*(m-1);
            }
        }
        std::cout << dp[n][k] % mod << std::endl;
    }
}