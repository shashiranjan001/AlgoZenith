#include <iostream>
#include <vector>

long long int rec(int i, int match, std::vector<std::vector<long long int> >& dp) {
    int n = dp.size();
    if (i == n) return 1;

    if (dp[i][match] != -1) return dp[i][match];

    long long int answer = 0;
    if (match == 0) {
        answer += rec(i+1, 0, dp) + rec(i+1, 1, dp);
    } else if (match == 1) {
        answer += rec(i+1, 1, dp) + rec(i+1, 2, dp);
    } else if (match == 2) {
        answer += rec(i+1, 3, dp) + rec(i+1, 0, dp);
    } else {
        answer += rec(i+1, 2, dp);
    }

    dp[i][match] = answer;
    return answer;
}

int main() {
    std::ios::sync_with_stdio (0);
    std::cin.tie(0);
    std::cout.tie(0);

    int t;
    std::cin >> t;
    long long int mod = 1e9 + 7;

    while (t--) {
        int n;
        std::cin >> n;
        std::vector<std::vector<long long int> > dp(n, std::vector<long long int>(4, -1));
        long long int answer = rec(0, 0, dp);
        std::cout << answer % mod << std::endl;
    }
}