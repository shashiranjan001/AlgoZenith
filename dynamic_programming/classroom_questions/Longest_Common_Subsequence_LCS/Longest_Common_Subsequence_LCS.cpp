#include <iostream>
#include <vector>
#include <string>


signed main() {
    std::string s1, s2;
    std::cin >> s1 >> s2;
    int n = s1.length();
    int m = s2.length();

    std::vector<std::vector<int> > dp(n+1, std::vector<int>(m+1, 0));
    std::vector<std::vector<int> > dpDirection(n+1, std::vector<int>(m+1, -1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                dpDirection[i][j] = 1;
            } else {
                if (dp[i-1][j] > dp[i][j-1]) {
                    dp[i][j] = dp[i-1][j];
                    dpDirection[i][j] = 2;
                } else {
                    dp[i][j] = dp[i][j-1];
                    dpDirection[i][j] = 0;
                }
            }
        }
    }

    std::cout << dp[n][m] << std::endl;
    std::string ans = "";
    int i = n, j = m; 
    while(i && j) {
        if (dpDirection[i][j] == 0) {
            j--;
        } else if (dpDirection[i][j] == 1) {
            ans += s1[i-1];
            i--;
            j--;
        } else {
            i--;
        }
    }
    std::reverse(ans.begin(), ans.end());
    std::cout << ans << std::endl;
}