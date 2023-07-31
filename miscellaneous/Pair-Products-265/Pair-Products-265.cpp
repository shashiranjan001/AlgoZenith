#include <iostream>
#include <vector>
#include <cstdlib>

long long solve(const std::vector<int>& input, int m) {
    if (input.size() > m) return 0;
    long long product = 1;
    for (int i = 0; i < input.size()-1; i++) {
        for (int j = i+1; j < input.size(); j++){
            product = (product*(std::abs(input[i] - input[j])))%m;
            if (!product) return 0;
        }
    } 
    return product;
}

signed main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> array(n);
    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
    }
    std::cout << solve(array, m) << std::endl;
}