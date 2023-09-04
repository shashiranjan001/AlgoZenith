// #include <iostream>

// void rec(int level, int array[], int n, int curr[], int index, int &count, int k) {
//     if (level > index) return;
//     if (count > k) return;

//     if (level == n) {
//         // if (curr[n-1]) {
//             if (count == k-1) {
//                 for (int i = 0; i < n; i++) std::cout << curr[i] << " ";
//                 std::cout << std::endl;
//             }
//             count++;
//         // }
//         return;
//     }

//     for (int i = 0; i < n; i++) {
//         if (array[i] == 0) {
//             array[i] = 1;
//             curr[index] = i+1;
//             rec(level+1, array, n, curr, index+1, count, k);
//             array[i] = 0;
//             curr[index] = 0;
//         }
//     }
// }

// signed main() {
//     int n, k;
//     std::cin >> n >> k;
//     int array[n], curr[n];
//     memset(array, 0, sizeof(array));
//     memset(curr, 0, sizeof(curr));
//     int count = 0;
//     rec(0, array, n, curr, 0, count, k);
// }


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
    std::map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[i+1]++;
    }
    std::vector<int> curr;
    int count = 0;
    rec(curr, 0, mp, count, n, k);
}

