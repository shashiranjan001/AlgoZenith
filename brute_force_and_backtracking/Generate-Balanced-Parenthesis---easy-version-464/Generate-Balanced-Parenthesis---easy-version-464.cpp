// #include <iostream>
// #include <vector>
// #include <map>

// void rec(std::vector<int> curr, int level, std::map<int, int> mp, int maxLevel, int& sum) {
//     if (curr.size() < level) return;
//     if (level == maxLevel) {
//         for (auto it: curr) {
//             if (it==1) std::cout << ")";
//             else std::cout << "(";
//         }
//         std::cout << std::endl;
//         return;
//     }

//     for (auto it: mp) {
//         if (it.second != 0) {
//             if (sum < 0 || (sum == 0 && it.first == -1)) {
//                 curr.push_back(it.first);
//                 mp[it.first]--;
//                 sum += it.first;
//                 rec(curr, level+1, mp, maxLevel, sum);
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
//     rec(curr, 0, mp, n, sum);
// }

// signed main() {
//     int n;
//     std::cin >> n;
//     solve(n);
// }


// // void rec(std::vector<std::vector<int> > &ans, std::vector<int> curr, int level, std::map<int, int> mp, int maxLevel, int &sum) {
// //     if (curr.size() < level) return;
// //     if (level == maxLevel) {
// //         if (curr.size() == maxLevel) {
// //             ans.push_back(curr);
// //         }
// //         return;
// //     }

// //     for (auto it: mp) {
// //         if (it.second != 0) {
// //             if (sum < 0 || (sum == 0 && it.first == -1)) {
// //                 curr.push_back(it.first);
// //                 mp[it.first]--;
// //                 sum += it.first;
// //                 rec(ans, curr, level+1, mp, maxLevel, sum);
// //                 mp[it.first]++;
// //                 sum -= it.first;
// //                 curr.pop_back();
// //             }
// //         }
// //     }
// // }

// // void solve(int n) {
// //     std::map<int, int> mp;
// //     mp[-1] = n/2;
// //     mp[1] = n/2;
// //     std::vector<std::vector<int> > ans;
// //     std::vector<int> curr;
// //     int sum = 0;
// //     rec(ans, curr, 0, mp, n, sum);
// //     for (int i = 0; i < ans.size(); i++) {
// //         for (auto it: ans[i]) {
// //             if (it == 1) std::cout << ")";
// //             else std::cout << "(";
// //         }
// //         std::cout << std::endl;
// //     }
// // }

// // signed main() {
// //     int n;
// //     std::cin >> n;
// //     solve(n);
// // }











#include <vector>
#include <iostream>
#include <map>

void rec(std::map<int, int>& counter, int sum, int level, int number, int max_level) {
	if (level == max_level) {
        if (sum == 0) {
            for (int i = 0; i < max_level; i++) {
                if (number & 1 << i) {
                    std::cout << ")";
                } else {
                    std::cout << "(";
                }
            }
            std::cout << std::endl;
        }
        return;
    }

    for (auto element: counter) {
        if (element.second > 0) {
            if (element.first > 0 && sum == 0) continue;
            if (element.first > 0) number |= 1 << level;
            element.second--;
            sum += element.first;
            rec(counter, sum, level + 1, number, max_level);
            if (element.first > 0) number ^= 1 << level;
            element.second++;
            sum -= element.first;
        }
    }
}

int main() {
	int n;
	std::cin >> n;
    // stores count of ( and ) parenthesis
	std::map<int, int> counter;
	counter[-1] = n/2;
	counter[1] = n/2;
	
    // sum is used to track if parenthesis is balanced or not
	int current_sum = 0;
	int number = 0;
	int level = 0;

    rec(counter, current_sum, level, number, n);
}
