#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

void solve(const std::vector<int> &input, int d) {
    int head = -1, tail = 0;
    std::unordered_map<int, int> mp;
    int penalty = d;
    int currPenalty = 0;
    while (input.size()-tail+1 >= d) {
        std::cout<<tail<<"\t"<<head<<std::endl;
        if (head < input.size()) {
            std::cout<<"head less than size\n";
        }
        if (head-tail+1 < d) {
            std::cout<<"length of subarray less than d\n";
        }
        while (head < input.size() && head-tail+1 < d) {
            std::cout<<"ran once"<<std::endl;
            if (mp.find(input[head+1]) == mp.end()) {
                currPenalty++;
                mp[input[head+1]]++;
            }
            head++;
            std::cout<<head<<std::endl;
        }
        std::cout<<tail<<"\t"<<head<<std::endl;
        penalty = std::min(penalty, currPenalty);
        if (head >= tail) {
            if(--mp[input[tail]] == 0) {
                mp.erase(input[tail]);
            }
            tail++;
        } else {
            tail++;
            head = tail -1;
        }
    }
    std::cout<< penalty<< "\n\n\n\n"<<std::endl;
}

signed main() {
    int t;
    std::cin>> t;
    while (t--) {
        int n, d;
        std::cin>> n>> d;
        std::vector<int> array(n);
        for (int i=0; i<n; i++) {
            std::cin>> array[i];
        }
        solve(array, d);
    }
}