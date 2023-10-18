#include <iostream>
#include <vector>
#include <string>

long long int mod = 1e9 + 7;



long long int rec(std::string& s1, std::string& s2, int level, int l_tight, int r_tight, int sum, int d, std::vector<std::vector<std::vector<std::vector<long long int> > > >& dp) {
    if (level == s1.length()) {
        return sum==0;
    }

    if (dp[level][l_tight][r_tight][sum] != -1) {
        return dp[level][l_tight][r_tight][sum];
    }

    int low = 0;
    if (l_tight) {
        low = s1[level] - '0' ;
    }

    int high = 9;
    if (r_tight) {
        high = s2[level] - '0';
    }

    long long int ans = 0;
    for (int i = low; i <= high; i++) {
        int n_l_tight = 1;
        if (i != s1[level] - '0') n_l_tight = 0;

        int n_r_tight = 1;
        if (i != s2[level] - '0') n_r_tight = 0;

        ans += rec(s1, s2, level + 1, n_l_tight, n_r_tight, (sum + i)%d, d, dp);
        ans %= mod;
    }
    dp[level][l_tight][r_tight][sum] = ans;
    return ans;
}

int main() {
    std::string s2;
    std::cin >> s2;
    int d;
    std::cin >> d;
    int zeros = s2.length() - 1;
    std::string z(zeros, '0');
    std::string s1 = z + '1';
    std::cout << s2 << std::endl << s1 << std::endl << d << std::endl;
    // long long int dp[10000][2][2][100];
    std::vector<std::vector<std::vector<std::vector<long long int> > > > 
        dp(10000, std::vector<std::vector<std::vector<long long int> > >(2, std::vector<std::vector<long long int> >(2, std::vector<long long int>(100, -1))));
    // memset(dp, -1, sizeof(dp));
    std::cout << rec(s1, s2, 0, 1, 1, 0, d, dp) << std::endl;
}