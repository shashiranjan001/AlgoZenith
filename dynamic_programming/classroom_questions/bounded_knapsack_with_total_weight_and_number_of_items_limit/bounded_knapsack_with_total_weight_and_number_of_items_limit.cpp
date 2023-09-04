#include <iostream>
#include <vector>
#include <algorithm>

signed main() {
    int t;
    std::cin >> t;
    while(t--) {
        int n;
        std::cin >> n;
        std::vector<std::pair<int, int> > items(n+1);
        for (int i = 1; i <= n; i++) {
            std::cin >> items[i].first;
            std::cin >> items[i].second;
        }
        int budget, numItems;
        std::cin >> budget >> numItems;

        for (int i = 1; i <= n; i++) {
            std::cout << items[i].first << " ";
            std::cout << items[i].second << std::endl;
        }
        std::cout << std::endl << std::endl;
        std::cout << budget << " " << numItems << std::endl;


        std::vector<std::vector<std::vector<int> > > dp(n+1, std::vector<std::vector<int> >(budget+1, std::vector<int>(numItems+1,0)));
        for (int i = n; i > 0; i--) {
            for (int b = 1; b <= budget; b++) {
                for (int k = 1; k <= numItems; k++) {
                    if(i==n) {
                        if(items[i].first <= b) dp[i][b][k] = items[i].second;
                    } else {
                        dp[i][b][k] = dp[i+1][b][k];
                        if(items[i].first <= b && k > 0) dp[i][b][k] = std::max(dp[i][b][k], items[i].second + dp[i+1][b-items[i].first][k-1]);
                    }
                }
            }
        }
        std::cout << dp[1][budget][numItems] << std::endl;
    }
}