#include <iostream>
#include <vector>
#include <math.h>

int main () {
    std::ios::sync_with_stdio (0);
    std::cin.tie(0);
    std::cout.tie(0);

    int n, q, k;
    std::cin >> n >> q >> k;
    std::vector<long long int> final(n+2, 0);
    long long int mod = 1e9+7;
    long long int a, l, r;
    for (int i = 0; i < q; i++) {
        std::cin >> a >> l >> r;
        final[l] += a;
        final [r+1] -= a*std::pow(k, r+1-l);
    }

    for (int i = 1; i < n; i++) {
        final[i] += final[i-1]*k;
    }
    for (int i = 1; i < n; i++) {
        std::cout << final[i]%mod << " ";
    }
}