#include <iostream>
#include <vector>
#include <map>

void rec(std::vector<int> curr, int level, std::map<int, int> mp, int maxLevel, int& sum) {
    if (curr.size() < level) return;
    if (level == maxLevel) {
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
                curr.push_back(it.first);
                mp[it.first]--;
                sum += it.first;
                rec(curr, level+1, mp, maxLevel, sum);
                mp[it.first]++;
                sum -= it.first;
                curr.pop_back();
            }
        }
    }
}

void solve(int n) {
    std::map<int, int> mp;
    mp[-1] = n/2;
    mp[1] = n/2;
    std::vector<std::vector<int> > ans;
    std::vector<int> curr;
    int sum = 0;
    rec(curr, 0, mp, n, sum);
}

signed main() {
    int n;
    std::cin >> n;
    solve(n);
}


// void rec(std::vector<std::vector<int> > &ans, std::vector<int> curr, int level, std::map<int, int> mp, int maxLevel, int &sum) {
//     if (curr.size() < level) return;
//     if (level == maxLevel) {
//         if (curr.size() == maxLevel) {
//             ans.push_back(curr);
//         }
//         return;
//     }

//     for (auto it: mp) {
//         if (it.second != 0) {
//             if (sum < 0 || (sum == 0 && it.first == -1)) {
//                 curr.push_back(it.first);
//                 mp[it.first]--;
//                 sum += it.first;
//                 rec(ans, curr, level+1, mp, maxLevel, sum);
//                 mp[it.first]++;
//                 sum -= it.first;
//                 curr.pop_back();
//             }
//         }
//     }
// }

// void solve(int n) {
//     std::map<int, int> mp;
//     mp[-1] = n/2;
//     mp[1] = n/2;
//     std::vector<std::vector<int> > ans;
//     std::vector<int> curr;
//     int sum = 0;
//     rec(ans, curr, 0, mp, n, sum);
//     for (int i = 0; i < ans.size(); i++) {
//         for (auto it: ans[i]) {
//             if (it == 1) std::cout << ")";
//             else std::cout << "(";
//         }
//         std::cout << std::endl;
//     }
// }

// signed main() {
//     int n;
//     std::cin >> n;
//     solve(n);
// }