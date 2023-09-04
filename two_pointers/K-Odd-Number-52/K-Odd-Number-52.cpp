#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#define int ll
#define ll long long

void solve(const std::vector<int> &array, int k , int d) {
    int n = array.size();
    std::vector<int> prefixSum(n);
    for (int i = 0; i < n; i++) {
        prefixSum[i] = array[i];
        if (i) {
            prefixSum[i] += prefixSum[i-1];
        }
    }

    int oddCount = 0;
    long long best = -1e15;
    std::multiset<int> prefixContainer;
    int head = -1;
    int tail = 0;
    while (tail < n) {
        while (head+1 < n) {
            // std::cout<<"1. "<<tail<<"\t"<<head<<"\n";
            // std::cout<<"oddCount = "<<oddCount<<"\t array[head+1] = "<<array[head+1]<<" array[head+1]%2 = "<<array[head+1]%2<<"\n";
            if (oddCount==k && array[head+1]%2!=0) {
                // std::cout<<"2. "<<tail<<"\t"<<head<<"\n";
                break;
            }
            head++;
            if (!array[head]%2 != 0) oddCount++;
            prefixContainer.insert(prefixSum[head]);
        }
        // std::cout<<"3. "<<tail<<"\t"<<head<<"\n";
        int base = 0;
        if (tail) base = prefixSum[tail-1];
        auto it = prefixContainer.upper_bound(base+d);
        if (it != prefixContainer.begin()) {
            it--;
            best =  best < *it-base ? *it-base : best;
        }

        if (head >= tail) {
            if (array[tail]%2 != 0) oddCount--;
            prefixContainer.erase(prefixSum[tail]);
            tail++;
        } else {
            tail++;
            head = tail-1;
        }
    }
    // std::cout<< "best = "<< best<< std::endl;
    if (best == -1e15) std::cout<< "IMPOSSIBLE\n";
    else std::cout<< best<< std::endl;
}

signed main() {
    int t;
    std::cin>> t;
    while(t--) {
        int n, k, d;
        std::cin>> n>> k>> d;
        std::vector<int> array(n);
        for (int i = 0; i < n; i++) {
            std::cin>> array[i];
        }
        solve(array, k, d);
    }
}