#include <iostream>
#include <string>

void solve(const std::string &s, long long n) {
    long long ans = 0;
    for (int i = 0; i < 26; i++) {
        long long count = 0;
        int head = -1;
        int tail = 0;
        while (tail < n) {
            while (head+1 < n) {
                if (s[head+1] - 'a' == i) {
                    break;
                }
                head++;
            }
            if (head >= tail) {
                count += head - tail + 1;
                tail++;
            } else {
                tail++;
                head = tail - 1;
            }
        }
        long long contribution = (n*(n+1)/2) - count;
        ans += contribution;
    }
    std::cout<< ans<< std::endl;
}

signed main () {
    int t;
    std::cin>> t;
    while (t--) {
        int n;
        std::cin>> n;
        std::string s;
        std::cin>> s;
        solve(s, n);
    }
}