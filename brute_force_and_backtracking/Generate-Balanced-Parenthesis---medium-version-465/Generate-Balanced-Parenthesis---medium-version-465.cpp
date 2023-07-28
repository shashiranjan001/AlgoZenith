#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int maxDepth = INT_MIN;

int rec(std::vector<int> curr, int level, std::map<int, int> mp, int maxLevel, int& sum, int k, int &depth) {
    if (curr.size() < level) return;
    if (level == maxLevel && maxDepth == k) {
        for (auto it: curr) {
            if (it==1) std::cout << ")";
            else std::cout << "(";
        }
        std::cout << std::endl;
        return;
    }

    for (auto it: mp) {
        if (it.second != 0) {
            if (sum < 0 || (sum == 0 && it.first == -1)) {
                if (it.first == -1) {
                    depth += 1;
                    if (sum == 0) maxDepth = std::max(maxDepth, depth);
                }
                else depth -= 1;
                curr.push_back(it.first);
                mp[it.first]--;
                sum += it.first;
                rec(curr, level+1, mp, maxLevel, sum, k, depth);
                if (it.first == -1) depth -= 1;
                else depth += 1;
                mp[it.first]++;
                sum -= it.first;
                curr.pop_back();
            }
        }
    }
}

void solve(int n, int k) {
    std::map<int, int> mp;
    mp[-1] = n/2;
    mp[1] = n/2;
    std::vector<std::vector<int> > ans;
    std::vector<int> curr;
    int sum = 0;
    int depth = 0;
    rec(curr, 0, mp, n, sum, k, depth);
}

signed main() {
    int n, k;
    std::cin >> n >> k;
    solve(n, k);
}