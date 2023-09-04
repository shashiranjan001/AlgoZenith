#include <iostream>
#include <vector>

// signed main() {
//     int n;
//     std::cin >> n;
//     std::vector<int> dp(n+1, 0);
//     dp[0] = 1;
//     if (!n) {
//         std::cout << "0" << std::endl;
//         return 0;
//     }

//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j<=6; j++) {
//             if (i-j >= 0) {
//                 dp[i] += dp[i-j];
//             } 
//         }
//     }
//     std::cout << dp[n] << std::endl;
// }

signed main() {
    int n;
    std::cin >> n;
    std::vector<int> dp(6,0);
    dp[0] = 1;
    if (!n) {
        std::cout << "0" << std::endl;
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        int curr = 0;
        for (int j = 1; j<=6; j++) {
            if (i-j >= 0) {
                curr += dp[j-1];
            } else {
                break;
            }
        }
        for (int j = 5; j > 0; j--) {
            dp[j] = dp[j-1];
        }
        dp[0] = curr;
    }
    std::cout << dp[0] << std::endl;
}