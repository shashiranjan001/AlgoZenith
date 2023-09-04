#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>


signed main(){
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> x(n), y(n);
        for (int i = 0; i < n; i ++) {
            std::cin >> x[i];
            std::cin >> y[i];
        }
        // std::sort(x.begin(), x.end());
        // std::sort(y.begin(), y.end());
        double sumx = 0.0, sumy = 0.0;
        for (int i = 0; i < n; i++) {
            sumx += x[i];
            sumy += y[i];
        }
        int x_cor = round(sumx/n);
        int y_cor = round(sumy/n);
        std::cout << x_cor << " " << y_cor << std::endl;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += abs(x_cor-x[i]) + abs(y_cor-y[i]);
        }
        std::cout << sum << std::endl;
    }
}
