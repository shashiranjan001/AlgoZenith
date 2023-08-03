#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

signed main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        std::vector<int> b(n);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        for(int i = 0; i < n; i++) {
            std::cin >> b[i];
        }
        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += std::abs(a[i] - b[i]);
        }
        std::cout << sum << std::endl;
    }
}