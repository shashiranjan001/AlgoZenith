#include <iostream>
#include <vector>
#include <map>

void solve(const std::vector<int> &input, int k) {
    
    int head = -1;
    int tail = 0;
    long long answer = 0;
    int currentSum = 0;
    while (tail < input.size()) {
        while(head + 1 < input.size()) {
            if (input[head+1] + currentSum > k) {
                break;
            }
            head++;
            currentSum += input[head];
        }
        // std::cout<< "Frequency Map\n";
        // for (auto it:frequency) {
        //     std::cout<< it.first<< "\t"<< it.second<< std::endl;
        // }
        // std::cout<< "\n";
        // std::cout<< tail<< "\t"<< head<< std::endl;
        answer += head-tail+1;
        if (head >= tail) {
            currentSum -= input[tail];
            tail++;
        } else {
            tail++;
            head = tail-1;
        }
        // std::cout<< "\n\n\n";
    }

    std::cout<< answer<< std::endl;
}

signed main() {
    int t;
    std::cin>> t;
    // std::cout<< "t = "<< t<< "\n";
    while (t--) {
        int n, k;
        std::cin>> n>> k;
        std::vector<int> input(n);
        for (int i = 0; i < n; i++) {
            std::cin>> input[i];
        }
        solve(input, k);
    }
}