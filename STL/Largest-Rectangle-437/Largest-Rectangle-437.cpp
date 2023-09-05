#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

int main () {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> input(n);
        for (int i = 0; i <n; i++) {
            std::cin >> input[i];
        }
        std::vector<std::pair<int, int> > leftRightMinimums(n, std::make_pair(n, -1));
        std::stack<std::pair<int, int> > rightMin, leftMin;

        rightMin.push(std::make_pair(input[n-1], n-1));
        for (int i = n-2; i >=0; i--) {
            while (!rightMin.empty()) {
                if (rightMin.top().first < input[i]) {
                    leftRightMinimums[i].first = rightMin.top().second;
                    break;
                }
                rightMin.pop();
            }
            rightMin.push(std::make_pair(input[i], i));
        }

        leftMin.push(std::make_pair(input[0], 0));
        for (int i = 1; i < n; i++) {
            while (!leftMin.empty()) {
                if (leftMin.top().first < input[i]) {
                    leftRightMinimums[i].second = leftMin.top().second;
                    break;
                }
                leftMin.pop();
            }
            leftMin.push(std::make_pair(input[i], i));
        }
        long long int maxx = -1;
        for (int i = 0; i < n; i++) {
            long long int rectangles = (1LL*input[i])*(leftRightMinimums[i].first - leftRightMinimums[i].second - 1);
            maxx = std::max(rectangles, maxx);
        }
        std::cout << maxx << std::endl;
    }
}