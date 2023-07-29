#include <iostream>
#include <vector>
#include <algorithm>

#define int long long

std::vector<int> generateAllSubsetsModulo( std::vector<int>& input, int m) {
    int n = input.size();
    std::vector<int> subSetModulos;
    for (int i = 0; i<(1<<n); i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            if ((i>>j)&1) {
                input[j] = input[j]%m;
                sum = (sum + input[j])%m;
            }
        }
        subSetModulos.push_back(sum);
    }
    return subSetModulos;
}

signed main() {
    // int t;
    // std::cin >> t;
    // while (t--) {
        int n, m;
        std::cin >> n >> m;
        int size_a = n/2;
        int size_b = n/2;
        if (n%2) size_a = (n+1)/2;
        std::vector<int> a(size_a), b(size_b);
        for (int i = 1; i <= n; i++) {
            if (i%2) std::cin >> a[i/2];
            else std::cin >> b[i/2 - 1];
        }
        std::vector<int> s1 = generateAllSubsetsModulo(a, m);
        std::vector<int> s2 = generateAllSubsetsModulo(b, m);
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        int maximum = -1e15;
        for (int i = 0; i < s1.size(); i++) {
            auto it = std::upper_bound(s2.begin(), s2.end(), (m-1)-s1[i]);
            if (it != s2.end()) {
                maximum = m-1;
            } else {
                --it;
                maximum = std::max(maximum, s1[i]+*it);
            }
        }
        std::cout << maximum << std::endl;
    // }
}