#include <iostream>

void solve(long long x, long long y) {
    if (x >= y) {
        std::cout << x-y << std::endl;
        return;
    }
    long long steps = 0;
    while (y > x) {
        if (y %2 != 0) {
            y = y+1;
            steps++;
        }
        y /= 2;
        steps++;
    }
    std::cout << (steps + (x-y)) << std::endl;
    return;
}

signed main() {
    int t;
    std::cin >> t;
    while (t--) {
        long long x, y;
        std::cin >> x >> y;
        solve(x, y);
    }
}