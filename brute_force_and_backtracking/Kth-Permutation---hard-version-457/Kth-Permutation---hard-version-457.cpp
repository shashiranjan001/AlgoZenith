#include <iostream>
#include <vector>
#include <map>

void rec(std::vector<int> curr, int level, std::map<int, int> mp, int& count, int maxLevel, int k) {
    if (count >= k) return;
    if (level == maxLevel) {
        count++;
        if (count == k) {
            for (int i = 0; i < maxLevel; i++) std::cout << curr[i] << " ";
            std::cout << std::endl; 
        }
        return;
    }

    for (auto it: mp) {
        if (it.second != 0) {
            curr.push_back(it.first);
            mp[it.first]--;
            rec(curr, level+1, mp, count, maxLevel, k);
            mp[it.first]++;
            curr.pop_back();
        }
    }
}

signed main() {
    int n, k;
    std::cin >> n >> k;
    long long product = 1;
    int j;
    for (j = 1; j <= n; j++) {
        product *= j;
        if (product > k) break;
    }

    // std::cout<<"j = "<<j<<std::endl;

    std::map<int, int> mp;
    for (int i = (n+1-j); i <= n; i++) {
        mp[i]++;
    }
    std::vector<int> curr;
    int count = 0;
    for (int i=1; i<(n+1-j); i++) std::cout<<i<<" ";
    rec(curr, 0, mp, count, j, k);
}