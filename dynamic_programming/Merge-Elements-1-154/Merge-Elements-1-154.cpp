#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

int main () {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int n;
    std::cin >> n;
    std::vector<int> input(n+1);
    for (int i = 1; i <= n; i++) {
        std::cin >> input[i];
    }

    // for (int i = 1; i <= n; i++) {
    //     std::cout << input[i] << " ";
    // }
    // std::cout << std::endl;

    int mod = 100;

    std::vector<int> prefixSum(n+1);
    prefixSum[0] = 0;
    for (int i = 1; i <= n; i++) {
        prefixSum[i] = (prefixSum[i-1] + input[i]) % mod;
    }

    // for (int i = 1; i <= n; i++) {
    //     std::cout << prefixSum[i] << " ";
    // }
    // std::cout << std::endl;

    std::vector<std::vector<long long int> > dp(n+1, std::vector<long long int>(n+1));

    for (int len = 1; len <= n; len++) {
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            if (i==j) {
                dp[i][j] = 0;
            } else {
                long long int best = LLONG_MAX;
                for (int mid = i; mid < j; mid++) {
                    long long int current = dp[i][mid] + dp[mid+1][j] + (prefixSum[mid]-prefixSum[i-1])*(prefixSum[j]-prefixSum[mid]);
                    best = std::min(best, current);
                }
                dp[i][j] = best;
            }
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         std::cout << dp[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }
    // std::cout << std::endl;
    std::cout << dp[1][n] << std::endl;
}