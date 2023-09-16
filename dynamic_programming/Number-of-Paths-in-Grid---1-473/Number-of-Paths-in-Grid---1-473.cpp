// #include <iostream>
// #include <vector>

// int main(){
//     std::ios::sync_with_stdio(0);
//     std::cin.tie(0);
//     std::cout.tie(0);

//     long long int mod = 1e9+7;

//     int t;
//     std::cin >> t;
//     while (t--) {
//         int n, m;
//         std::cin >> n >> m;
//         std::vector<std::vector<int> > grid(n, std::vector<int>(m));
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 std::cin >> grid[i][j];
//             }
//         }

//         if(grid[0][0] || grid[n-1][m-1]) {
//             std::cout << 0 << "\n";
//             continue;
//         }

//         std::vector<std::vector<long long int> > dp(n, std::vector<long long int>(m, 0));
//         dp[n-1][m-1] = 1;
//         for (int i = n-1; i >= 0; i--) {
//             for (int j = m-1; j >=0 ; j--) {
//                 if (i+1 < n && !grid[i][j]) dp[i][j] = (dp[i][j] + dp[i+1][j]) % mod ;
//                 if (j+1 < m && !grid[i][j]) dp[i][j] = (dp[i][j] + dp[i][j+1]) % mod;
//             }
//         }

//         std::cout << dp[0][0] << std::endl;
//     }

// }



#include <iostream>
#include <vector>

long long int mod = 1e9+7;
int n, m;

long long int calculatePaths(int x, int y, std::vector<std::vector<int> >& grid, std::vector<std::vector<long long int> >& dp) {
    if (x >= n || y >= m || grid[x][y]) {
        return 0;
    }

    if (x == n-1 && y == m-1) {
        return 1;
    }

    if (dp[x][y] != -1) return dp[x][y];

    long long totalWays = (calculatePaths(x+1, y, grid, dp) + calculatePaths(x, y+1, grid, dp)) % mod;

    dp[x][y] = totalWays;
    return dp[x][y];
}


int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int t;
    std::cin >> t;
    while (t--) {
        std::cin >> n >> m;
        std::vector<std::vector<int> > grid(n, std::vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                std::cin >> grid[i][j];
            }
        }

        std::vector<std::vector<long long int> > dp(n, std::vector<long long int>(m, -1));
        std::cout << calculatePaths(0, 0, grid, dp) << std::endl;
    }
}