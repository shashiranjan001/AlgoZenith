#include <iostream>
#include <vector>

signed main () {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> array(n);
        for (int i = 0; i < n; i++) {
            std::cin >> array[i];
        }
        long long sum = 0;
        for (int i = 1; i < n; i++) {
            if (array[i-1] > array[i]) {
                sum += array[i-1] - array[i];
            }
        }
        std::cout << sum << std::endl;
    }
}