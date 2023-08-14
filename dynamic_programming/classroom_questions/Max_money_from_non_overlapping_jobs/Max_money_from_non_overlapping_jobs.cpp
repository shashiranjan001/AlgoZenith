#include <iostream>
#include <vector>
#include <algorithm>

struct job {
    int start;
    int end;
    int money;
};

bool ascendingStartJobs(job A, job B) {
    return A.start < B.start;
}

signed main() {
    int t;
    std::cin >> t;
    while(t--) {
        int n;
        std::cin >> n;
        std::vector<job> jobs(n);
        for (int i = 0; i < n; i++) {
            std::cin >> jobs[i].start;
            std::cin >> jobs[i].end;
            std::cin >> jobs[i].money;
        }
        std::sort(jobs.begin(), jobs.end(), ascendingStartJobs);
        std::vector<int> dp(n);
        for (int i = n-1; i >= 0; i--) {
            dp[i] = jobs[i].money;
            int f = -1;
            int l = i+1;
            int r = n-1;
            while(l<=r) {
                int mid = (l+r)/2;
                if (jobs[i].end <= jobs[mid].start) {
                    f = mid;
                    r = mid-1;
                } else {
                    l = mid+1;
                }
            }
            if (f != -1) {
                dp[i] = std::max(dp[i], dp[f] + jobs[i].money);
            }
            if (i+1 < n) {
                dp[i] = std::max(dp[i], dp[i+1]);
            }
        }
        std::cout << dp[0] << std::endl;
    }
}