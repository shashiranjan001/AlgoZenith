#include <iostream>
#include <vector>
#include <algorithm>

#define int long long

std::vector<int> generateAllSubsetsSums(const std::vector<int>& input) {
    int n = input.size();
    std::vector<int> subSetSums;
    for (int i = 0; i<(1<<n); i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            if ((i>>j)&1) sum += input[j];
        }
        subSetSums.push_back(sum);
    }
    return subSetSums;
}

signed main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, x;
        std::cin >> n >> x;
        int size_a = n/2;
        int size_b = n/2;
        if (n%2) size_a = (n+1)/2;
        std::vector<int> a(size_a), b(size_b);
        for (int i = 1; i <= n; i++) {
            if (i%2) std::cin >> a[i/2];
            else std::cin >> b[i/2 - 1];
        }
        std::vector<int> s1 = generateAllSubsetsSums(a);
        std::vector<int> s2 = generateAllSubsetsSums(b);
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        int count = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] > x) break;
            count += std::upper_bound(s2.begin(), s2.end(), x-s1[i]) - s2.begin();
        }
        std::cout << count << std::endl;
    }
}