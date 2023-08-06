#include <iostream>
#include <vector>
#include <algorithm>

signed main() {
    int n, s;
    std::cin >> n >> s;
    std::vector<int> coins(n);
    for (int i = 0; i <= n; i++) std::cin >> coins[i];
    std::vector<int> dp(s+1, 1e9);
    if (!s) {
        std::cout << "0" << std::endl;
        return 0;
    }
    dp[0] = 0;
    for (int i= 1; i <= s; i++) {
        for (int j = 0; j < n; j++) {
            if (i - coins[j] >= 0) {
                dp[i] = std::min(dp[i], 1 + dp[i - coins[j]]);
            } else {
                break;
            }
        }
    }
    if (dp[s] == 1e9)
        std::cout << "-1" << std::endl;
    else
        std::cout << dp[s] << std::endl;
}