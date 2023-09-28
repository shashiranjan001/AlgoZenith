#include <iostream>
#include <vector>

long long int mod = 1e9 + 7;

long long int reachable(int i, int j, int k, std::vector<std::vector<int> >& grid, std::vector<std::vector<std::vector<int> > >& dp) {
    int n = grid.size();
    int m = grid[0].size();

    //prune
    if (i < 0 || i >= n || j < 0 || j >= m || k < 0) return 0;
    if (grid[i][j] && k == 0) return 0;

    //baseCase
    if (i == n-1 && j == m-1) return 1;

    //cacheCheck
    if (dp[i][j][k] != -1) return dp[i][j][k];

    //computeAndSave
    long long int answer = 0;
    answer += reachable(i+1, j, k - (grid[i][j] == 1), grid, dp);
    answer += reachable(i, j+1, k - (grid[i][j] == 1), grid, dp);

    dp[i][j][k] = answer;

    //return
    return dp[i][j][k];
}

int main () {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int t;
    std::cin >> t;

    while (t--) {
        int n, m, k;
        std::cin >> n >> m >> k;
        std::vector<std::vector<int> > grid(n, std::vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                std::cin >> grid[i][j];
            }
        }

        std::vector<std::vector<std::vector<int> > > dp(n, std::vector<std::vector<int> >(m, std::vector<int>(k,-1)));
        int answer = reachable(0, 0, k, grid, dp);
        std::cout << answer << std::endl;
    }
}