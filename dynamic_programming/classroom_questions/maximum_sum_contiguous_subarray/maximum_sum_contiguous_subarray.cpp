#include <iostream>
#include <vector>
#include <algorithm>

signed main() {
    int n;
    std::cin >> n;
    std::vector<int> array(n);
    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
    }

    // std::cout << "Array = \n";
    // for (auto i: array) std::cout << i << " ";
    // std::cout << std::endl;

    std::vector<int> dp(n);
    dp[0] = array[0];
    for (int i = 1; i < n; i++) {
        // std::cout << "\n\n";
        // std::cout << "i = " << i << "\n";
        // std::cout << "dp[i-1] + array[i] = " << dp[i-1] + array[i] << "\n";
        // std::cout << "array[i] = " << array[i] << "\n";
        dp[i] = std::max(dp[i-1] + array[i], array[i]);
        // std::cout << "dp[i] = " << dp[i] << "\n";
        // std::cout << "\n\n";
    }

    // std::cout << "DP = \n";
    // for (auto i: dp) std::cout << i << " ";
    // std::cout << std::endl;

    int ans = dp[0];
    for (int i = 1; i < n; i++) {
        ans = std::max(ans, dp[i]);
    }
    std::cout << ans << std::endl;
}