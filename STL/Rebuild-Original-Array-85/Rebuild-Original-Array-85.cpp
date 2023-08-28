#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        int m = 1 << n;
        std::vector<long long int> inp(m);
        for (int i = 0; i < m; i++) {
            std::cin >> inp[i];
        }
        std::vector<long long int> answer;
        std::vector<long long int> globalSubSetSums;
        std::sort(inp.begin(), inp.end());
        std::map<long long int, int> done;
        done[0] = 1;
        globalSubSetSums.push_back(0);
        for (int i = 0; i < m; i++) {
            if (done[inp[i]]) done[inp[i]]--;
            else {
                answer.push_back(inp[i]);
                std::vector<long long int> subsetSums;
                for (auto it: globalSubSetSums) {
                    subsetSums.push_back(it + inp[i]);
                    done[it + inp[i]]++;
                }
                for (auto sums: subsetSums) {
                    globalSubSetSums.push_back(sums);
                }
            }
        }
        for (auto it: answer) std::cout << it << " ";
        std::cout << std::endl;
    }
}