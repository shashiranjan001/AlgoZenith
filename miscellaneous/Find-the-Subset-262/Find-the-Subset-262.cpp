#include <iostream>
#include <vector>
#include <map>

bool solve(const std::vector<int>& input) {
    int n = input.size();
    std::map<int, int> mp;
    mp[0] = -1;
    std::vector<long long> prefixSum(n);
    prefixSum[0] = input[0];
    mp[prefixSum[0]%n] = 0;
    for (int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i-1] + input[i];
        if (mp.find(prefixSum[i]%n) != mp.end()) {
            return true;
        }
        mp[prefixSum[i]%n] = i;
    }
    return false;
}

signed main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> array(n);
        for (int i = 0; i < n; i++) {
            std::cin >> array[i];
        }
        // if (solve(array)) {
        //     std::cout << "YES\n";
        // } else {
        //     std::cout << "NO\n";
        // }
        std::cout << "YES\n";
    }
}