#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

void solve(const std::vector<int> &array) {
    std::unordered_set<int> s;
    for (int i = 0; i < array.size(); i++) {
        s.insert(array[i]);
    }
    int distinct = s.size();
    int head = -1;
    int tail = 0;
    int answer = array.size();
    std::unordered_map<int, int> frequency;
    while (tail < array.size()) {
        while (head + 1 < array.size() && frequency.size() < distinct) {
            head++;
            frequency[array[head]]++;
        }
        if(frequency.size() == distinct) {
            answer = std::min(answer, head-tail+1);
        }
        if(head >= tail) {
            if(--frequency[array[tail]] == 0) {
                frequency.erase(array[tail]);
            }
            tail++;
        } else {
            tail++;
            head = tail - 1;
        }
    }
    std::cout<< answer<< std::endl;
}

signed main() {
    int t;
    std::cin>> t;
    while(t--) {
        int n;
        std::cin>> n;
        std::vector<int> array(n);
        for (int i = 0; i < n; i++) {
            std::cin>> array[i];
        }
        solve(array);
    }
}