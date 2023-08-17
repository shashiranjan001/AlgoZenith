#include <iostream>
#include <vector>

signed main () {
    int x;
    std::cin >> x;
    int n;
    std::cin >> n;
    std::vector<int> moves(n);
    for (int i = 0; i < n; i++) {
        std::cin >> moves[i];
    }
    std::cout << std::endl;
    std::vector<bool> dp(x + 1);
    for (int i = 0; i <= x; i++) {
        if (!i) dp[i] = false;
        bool winning = false;
        for (auto it: moves) {
            if (i - it >=0 && !dp[i-it]) {
                winning = true;
                break;
            }
        }
        dp[i] = winning;
    }
    std::cout << dp[x] << std::endl;
}