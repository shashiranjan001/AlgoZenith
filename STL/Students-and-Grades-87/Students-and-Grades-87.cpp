#include <iostream>
#include <vector>
#include <unordered_set>


signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        std::unordered_set<long long int> classA;
        for (int i = 0; i < n; i++) {
            long long int marks;
            std::cin >> marks;
            classA.insert(marks) ;
        }
        for (int i = 0; i < m; i++) {
            long long int marks;
            std::cin >> marks;
            if (classA.find(marks) == classA.end()) {
                std::cout << "NO" << std::endl;
                classA.insert(marks);
                continue;
            }
            classA.insert(marks);
            std::cout << "YES" << std::endl;
        }
    }
}
