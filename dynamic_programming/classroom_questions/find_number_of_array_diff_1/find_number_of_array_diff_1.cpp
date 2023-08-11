#include <iostream>
#include <vector>
#include <algorithm>

signed main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int> > dp(n+1, std::vector<int>(m+1, 0));
    for (int i = 1; i <= m; i++) {
        dp[1][i] = 1;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = dp[i-1][j];
            if (j-1 >= 1) dp[i][j] += dp[i-1][j-1];
            if (j+1 <= m) dp[i][j] += dp[i-1][j+1];
        }
    }

    for (int len = 1; len <= n; len++) {
        for (int j = 1; j <= m; j++) std::cout << dp[len][j] << " ";
        std::cout << std::endl;
    }
    int ans = 0;
    for (int j = 1; j <= m; j++) {
        ans += dp[n][j]; 
    }
    std::cout << ans << std::endl;

}