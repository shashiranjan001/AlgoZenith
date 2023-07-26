#include <iostream>
#include <vector>
#include <map>

void rec(std::vector<std::vector<int> > &ans, std::vector<int> curr, int level, std::map<int, int> mp, int maxLevel) {
    if (level == maxLevel) {
        if (curr.size() == maxLevel) {
            ans.push_back(curr);
        }
        return;
    }

    for (auto it: mp) {
        if (it.second != 0) {
            curr.push_back(it.first);
            mp[it.first]--;
            rec(ans, curr, level+1, mp, maxLevel);
            mp[it.first]++;
            curr.pop_back();
        }
    }
}

void solve(const std::vector<int> &array) {
    std::map<int, int> mp;
    for (int i = 0; i < array.size(); i++) {
        mp[array[i]]++;
    }
    std::vector<std::vector<int> > ans;
    std::vector<int> curr;
    rec(ans, curr, 0, mp, array.size());
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < array.size(); j++) {
            std::cout << ans[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

signed main() {
    int n;
    std::cin >> n;
    std::vector<int> array(n);
    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
    }
    solve(array);
}