#include <iostream>
#include <vector>

bool recursion (std::vector<int>& array, int q, int level) {
    if (level == array.size()) return false;
    if (array[level] == q) {
        return true;
    }
    return recursion(array, q, level+1);
}

signed main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, q;
        std::cin >> n >> q;
        std::vector<int> input(n);
        for (int i = 0; i< n; i++) {
            std::cin >> input[i];
        }
        if (recursion(input, q, 0)) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
}

// level -> 0 .... -> n-1