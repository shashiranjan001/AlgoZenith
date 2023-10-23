#include <iostream>
#include <vector>
#include <map>

std::vector<int> solve(std::vector<int>& input, std::unordered_map<int, int>& counter, int pattern_size) {
    int n = input.size();
    int low = 0, high = -1;
    int mismatch = counter.size();
    std::vector<int> answer;
    while (low < n) {
        while (high + 1 < n && high + 1 - low + 1 <= pattern_size) {
            high++;
            if (counter.find(input[high]) == counter.end() || counter[input[high]] == 0) mismatch++;
            counter[input[high]]--;
            if (counter[input[high]] == 0) mismatch--;
        }

        if (mismatch == 0)  answer.push_back(low);
        if (low <= high) {
            if (counter[input[low]] == 0) mismatch++;
            counter[input[low]]++;
            if (counter[input[low]] == 0) mismatch--;
            low++;
        } else {
            low++;
            high = low - 1;
        }
    }
    return answer;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> input(n);

    for (int i = 0; i < n; i++) {
        std::cin >> input[i];
    }

    int m;
    std::cin >> m;
    std::vector<int> pattern(m);
    std::unordered_map<int, int> counter;
    for (int i = 0; i < m; i++) {
        std::cin >> pattern[i];
        counter[pattern[i]]++;
    }

    std::vector<int> answer  = solve(input, counter, m);
    for (int i: answer) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}