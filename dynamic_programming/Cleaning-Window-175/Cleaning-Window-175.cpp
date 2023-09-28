// #include <iostream>
// #include <vector>
// #include <algorithm>

// int main () {
//     std::ios::sync_with_stdio(0);
//     std::cin.tie(0);
//     std::cout.tie(0);
//     int t;
//     std::cin >> t;
//     while (t--) {
//         int n, m;
//         std::cin >> n >> m;
//         std::vector<std::vector<int> > grid(n, std::vector<int> (m));
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 std::cin >> grid[i][j];
//             }
//         }
//         std::vector<std::vector<int> > dp(n, std::vector<int> (m, INT_MIN));
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 if (i-1 >=0 && j-1 >=0) dp[i][j] = std::max(dp[i][j], dp[i-1][j-1]);
//                 if (i-1 >=0) dp[i][j] = std::max(dp[i][j], dp[i-1][j]);
//                 if (i-1 >=0 && j+1 < m) dp[i][j] = std::max(dp[i][j], dp[i-1][j+1]);
//                 int x = grid[i][j];
//                 if (grid[i][j] > dp[i][j]) grid[i][j] = 1;
//                 else grid[i][j] = 0;
//                 dp[i][j] = std::max(dp[i][j], x);
//             }
//         }

//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 std::cout << grid[i][j];
//             }
//             std::cout << std::endl;
//         }
//     }
// }



#include <iostream>
#include <vector>
#include <algorithm>

bool mySort(std::pair<int, std::pair<int, int> > a, std::pair<int, std::pair<int, int> > b) {
    return a.first > b.first;
}

int main () {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        std::vector<std::vector<int> > answer(n, std::vector<int> (m, -1));
        std::vector<std::pair<int, std::pair<int, int> > >  allTimes;
        int x;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                std::cin >> x;
                allTimes.push_back(std::make_pair(x, std::make_pair(i, j)));
            }
        }
        std::sort(allTimes.begin(), allTimes.end(), mySort);
        for (int i = 0; i < allTimes.size(); i++) {
            int x = allTimes[i].second.first;
            int y = allTimes[i].second.second;
            
            if (answer[x][y] == -1) answer[x][y] = 1;
            if (x+1 < n && y-1 >= 0) {
                if (answer[x+1][y-1] == -1) answer[x+1][y-1] = 0;
            }

            if (x+1 < n) {
                if (answer[x+1][y] == -1) answer[x+1][y] = 0;
            }

            if (x+1 < n && y+1 < m) {
                if (answer[x+1][y+1] == -1) answer[x+1][y+1] = 0;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                std::cout << answer[i][j];
            }
            std::cout << std::endl;
        }
    }
}