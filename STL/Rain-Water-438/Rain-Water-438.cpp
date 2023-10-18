#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> input(n);
        for (int i = 0; i < n; i++) {
            std::cin >> input[i];
        }
        std::vector<int> leftRightMaximums(n);
        int maxx = -1;
        for (int i = 0; i < n; i++) {
            leftRightMaximums[i] = maxx;
            maxx = std::max(maxx, input[i]);
        }

        maxx = -1;
        for (int i = n-1; i >= 0; i--) {
            leftRightMaximums[i]= std::min(maxx, leftRightMaximums[i]);
            maxx = std::max(maxx, input[i]);
        }

        long long int water = 0;
        for (int i = 1; i < n-1; i++) {
            int addition = leftRightMaximums[i] - input[i];
            if (addition > 0) water += addition;
        }
        std::cout << water << std::endl;
    }   
}