#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

signed main() {
    int t;
    std::cin >> t;
    while(t--) {
        std::string s1, s2;
        std::cin >> s1 >> s2;
        int n = s1.length();
        int m = s2.length();
        std::vector<std::vector<int> > dp(n+1, std::vector<int>(m+1, 1));
        for (int i = 1; i <=n; i++) dp[i][0] = i;
        for (int j = 1; j <=m; j++) dp[0][j] = j;
        for (int i = 1; i <= n; i++) {
            for (int j =1; j <= m; j++) {
                if (s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
                else {
                    dp[i][j] = std::min(dp[i-1][j-1], std::min(dp[i-1][j], dp[i][j-1])) + 1;
                }
            }
        }
        std::cout << dp[n][m] << std::endl;
    }
}