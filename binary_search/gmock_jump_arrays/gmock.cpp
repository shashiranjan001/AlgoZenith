#include <vector>
#include <iostream>
#include <map>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> input(n);
    for (int i = 0; i < n ; i++){
        std::cin >> input[i];
    }

    for (int i = 0; i < n ; i++){
        std::cout << input[i] << "\t";
    }
    std::cout << std::endl;

    std::vector<std::pair<bool, bool> > jumps(n, std::make_pair(false, false));
    jumps[n-1].first = true;
    jumps[n-1].second = true;

    std::map<int, int> indexMap;
    indexMap[input[n-1]] = n-1;

    for (int i = n-2; i >= 0; i--) {
        auto bigger = indexMap.upper_bound(input[i]);
        if (bigger != indexMap.end()) {
            jumps[i].first = jumps[bigger->second].second;
        }

        auto smaller = indexMap.lower_bound(input[i]);
        if (smaller != indexMap.begin()) {
            smaller--;
            jumps[i].second = jumps[smaller->second].first;
        }
        indexMap[input[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        std::cout << jumps[i].first << "|" << jumps[i].second << "\t";
    }
    std::cout << std::endl;
}