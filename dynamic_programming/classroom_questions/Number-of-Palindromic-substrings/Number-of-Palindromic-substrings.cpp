#include <iostream>
#include <vector>
#include <string>

signed main() {
    std::string s;
    std::cin >> s;
    int n = s.length();
    std::vector<std::vector<int> > dp(n, std::vector<int>(n, 0));
    int ans = 0;
    for (int l = 1; l <= n; l++) {
        for (int i = 0; i+l-1 < n; i++) {
            int j = i+l-1;
            if (s[i] == s[j]) {
                if (j <= i || (j > i && dp[i+1][j-1])) {
                    dp[i][j] = 1;
                    std::cout << s.substr(i, l) << std::endl;
                    ans++;
                }
            }
        }
    }
    std::cout << ans << std::endl;
}