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

        for (int i = 0; i < n; i++) {
            std::cout << jobs[i].start << " ";
            std::cout << jobs[i].end << " ";
            std::cout << jobs[i].money << " ";
            std::cout << std::endl;
        }

        std::vector<int> dp(n);
        dp[n-1] = jobs[n-1].money;
        for (int j = n-2; j >= 0; j--) {
            int l = j+1;
            int r = n-1;
            int answer = -1;
            while(l <= r) {
                int mid = (l+r)/2;
                if (jobs[j].end <= jobs[mid].start) {
                    answer = mid;
                    r = mid-1;
                } else {
                    l = mid+1;
                }
            }

            if (answer == -1) dp[j] = std::max(jobs[j].money, dp[j+1]);
            else dp[j] = std::max(jobs[j].money + dp[answer], dp[j+1]);
        }

        std::cout << dp[0] << std::endl;
    }
}