#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

signed main() {
    std::string s;
    std::cin >> s;
    int n = s.length();
    std::vector<std::vector<int> > isPalindrome(n, std::vector<int>(n, 0));
    int ans = 0;
    for (int l = 1; l <= n; l++) {
        for (int i = 0; i+l-1 < n; i++) {
            int j = i+l-1;
            if (s[i] == s[j]) {
                if (l<=2 || isPalindrome[i+1][j-1]) {
                    isPalindrome[i][j] = 1;
                }
            }
        }
    }

    for (int l = 1; l <= n; l++) {
        std::cout << "l = " << l << std::endl;
        for (int i = 0; i+l-1 < n; i++) {
            std::cout << isPalindrome[i][i+l-1] << " "; 
        }
        std::cout << std::endl;
    }

    std::vector<int> dp(n, 1e9);
    for (int i = 0; i < n; i++) {
        for (int j = i; j >= 0; j--) {
            if (isPalindrome[j][i]) {
                dp[i] = std::min(dp[i], (j?dp[j-1]:0) + 1);
            }
        }
    }
    std::cout << dp[n-1] - 1 << std::endl;
}