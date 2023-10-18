#include <iostream>
#include <vector>
#include <string>

bool rec(std::string& s1, std::string& s2, std::vector<std::vector<std::vector<int> > >& dp, int l1, int r1, int l2) {
    int r2 = r1-l1+l2;

    //base case
    if (l1 > r1 || l2 > r2) return 0;    

    // cache
    if (dp[l1][r1][l2] != -1) return dp[l1][r1][l2];
    
    // compute and save
    if (s1.substr(l1, r1-l1+1) == s2.substr(l2, r1-l1+1)) {
        dp[l1][r1][l2] = 1;
        return 1;
    }

    int answer = 0;
    for (int mid = l1; mid < r1; mid++) {
        if (rec(s1, s2, dp, l1, mid, l2) && rec(s1, s2, dp, mid+1, r1, l2+mid-l1+1)) {
            answer = 1;
            break;
        }
        if (rec(s1, s2, dp, l1, mid, r2-mid+l1) && rec(s1, s2, dp, mid+1, r1, l2)) {
            answer = 1;
            break;
        }
    }
    dp[l1][r1][l2] = answer;
    return answer;
}

int main () {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int t;
    std::cin >> t;
    while(t--) {
        std::string s1, s2;
        std::cin >> s1 >> s2;
        int len = s1.length();
        std::vector<std::vector<std::vector<int> > > dp(len, std::vector<std::vector<int> >(len, std::vector<int>(len, -1)));
        int answer = rec(s1, s2, dp, 0, len-1, 0);
        std::cout << answer << std::endl;
    }
}