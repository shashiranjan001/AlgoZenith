#include <iostream>
#include <string>
#include <set>

void solve(const std::string &s, int n) {
    long long ans = 0;
    int head = -1;
    int tail = 0;
    std::set<int> charSet;
    while (tail < n) {
        while (head + 1 < n) {
            if (charSet.find(s[head+1]-'a') != charSet.end()) {
                break;
            }
            head++;
            charSet.insert(s[head]-'a');
        }
        long long length = head - tail + 1;
        ans += (length*(length+1))/2;
        if (head >= tail) {
            charSet.erase(s[tail]-'a');
            tail++;
        } else {
            tail++;
            head = tail - 1;
        }
    }
    std::cout<< ans<< std::endl;
}

signed main() {
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