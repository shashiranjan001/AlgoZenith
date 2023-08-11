#include <iostream>
#include <vector>

// signed main() {
//     int t;
//     std::cin >> t;
//     while (t--) {
//         int n, w;
//         std::cin >> n >> w;
//         std::vector<int> weights(n);
//         std::vector<int> profits(n);

//         for (int i = 0; i < n; i++) {
//             std::cin >> weights[i];
//         }

//         for (int i = 0; i < n; i++) {
//             std::cin >> profits[i];
//         }

//         std::vector<std::vector<int> > dp(n+1, std::vector<int>(w+1, 0));
//         for (int i = 0; i <= n; i++) dp[i][0] = 0;
//         for (int i = 0; i <= w; i++) dp[0][i] = 0;

//         for (int i = 1; i <= n; i++) {
//             for (int j = 1; j <= w; j++) {
//                 dp[i][j] = dp[i-1][j];
//                 if (j - weights[i] >= 0) {
//                     dp[i][j] = std::max(dp[i][j], dp[i-1][j - weights[i]]  + profits[i]);
//                 }
//             }
//         }
//         std::cout << dp[n][w] << std::endl;
//     }
// }


// space efficient algorithm
signed main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, w;
        std::cin >> n >> w;
        std::vector<int> weights(n);
        std::vector<int> profits(n);

        for (int i = 0; i < n; i++) {
            std::cin >> weights[i];
        }

        for (int i = 0; i < n; i++) {
            std::cin >> profits[i];
        }

        std::vector<int> dp(w+1, 0);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            std::vector<int> tempDP(w+1, 0);
            for (int j = 1; j <= w; j++) {
                tempDP[j] = dp[j];
                if (j - weights[i] >= 0) {
                    tempDP[j] = std::max(tempDP[j], dp[j - weights[i]]  + profits[i]);
                }
            }
            dp = tempDP;
        }

        std::cout << dp[w] << std::endl;
    }
}