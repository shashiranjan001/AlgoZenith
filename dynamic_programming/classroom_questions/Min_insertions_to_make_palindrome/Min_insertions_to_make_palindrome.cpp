#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

signed main() {
    std::string s;
    std::cin >> s;
    int n = s.length();

    std::vector<std::vector<int> > dp(n, std::vector<int>(n, 1));
    for (int l = 1; l <= n; l++) {
        for (int i = 0; i+l-1 < n; i++) {
            int j = i+l-1;
            if (s[i] == s[j]) {
                if (l>2) dp[i][j] = dp[i+1][j-1];
                else if (l==2) dp[i][j] = 0;
                else dp[i][j] = 0;
            } else dp[i][j] = std::min(dp[i+1][j], dp[i][j-1]) + 1;
        }
    }
    std::cout << dp[0][n-1] << std::endl;
}