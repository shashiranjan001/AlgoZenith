#include <iostream>
#include <vector>
#include <algorithm>

signed main() {
    int n;
    std::cin >> n;
    std::vector<int> points(n);
    for (int i = 0; i < n; i++) {
        std::cin >> points[i];
    }
    std::vector<std::vector<int> > dp(n, std::vector<int>(n,0));
    for (int l = 1; l <= n; l++) {
        for(int i = 0; i+l-1 < n; i++) {
            int j = i+l-1;
            if (i==j) dp[i][j] = points[i];
            else {
                dp[i][j] = std::max(points[i] - dp[i+1][j], points[j] - dp[i][j-1]);
            }
        }
    }
    std::cout << dp[0][n-1] << std::endl;
}