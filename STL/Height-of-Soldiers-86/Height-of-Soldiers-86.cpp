#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

int main () {
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

        std::vector<int> left(n);
        left[0] = -1;
        std::stack<int> leftStack;
        leftStack.push(0);
        for (int i = 1; i < n; i++) {
            while(leftStack.size() && input[leftStack.top()] >= input[i]) leftStack.pop();
            if (leftStack.size()) left[i] = leftStack.top();
            else left[i] = -1;
            leftStack.push(i);
        }

        std::vector<int> right(n);
        right[n-1] = n;
        std::stack<int> rightStack;
        rightStack.push(n-1);
        for (int i = n-2; i >= 0; i--) {
            while(rightStack.size() && input[rightStack.top()] >= input[i]) rightStack.pop();
            if (rightStack.size()) right[i] = rightStack.top();
            else right[i] = n;
            rightStack.push(i);
        }

        std::vector<int> answer(n, -1);
        for (int i = 0; i < n; i++) {
            int len = right[i] - left[i] - 1;
            answer[len-1] = std::max(answer[len-1], input[i]);
        }

        for (int i = n-2; i >= 0; --i) {
            answer[i] = std::max(answer[i], answer[i+1]);
        }

        for (auto i: answer) {
            std::cout << i << " "; 
        }
        std::cout << std::endl;
    }
}
