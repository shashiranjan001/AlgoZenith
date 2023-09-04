// // Priority Queue implementation
// #include <iostream>
// #include <vector>
// #include <queue>

// signed main() {
//     std::ios::sync_with_stdio(0);
//     std::cin.tie(0);
//     std::cout.tie(0);
//     int t;
//     std::cin >> t;
//     while (t--) {
//         int n, k;
//         std::cin >> n >> k;
//         std::priority_queue<std::pair<int, int> > pq;
//         int j = 0;
//         for (int i = 0; i < n; i++) {
//             int x;
//             std::cin >> x;
//             pq.push(std::make_pair(x,i));
//             if (i >= k-1) {
//                 while (!pq.empty()) {
//                     std::pair<int, int> tp = pq.top();
//                     if (!(tp.second >= j && tp.second <= j+k-1)) pq.pop();
//                     else break;
//                 }
//                 std::cout << pq.top().first << " ";
//                 j++;
//             }
//         }
//         std::cout << std::endl;
//     }
// }


// Dequeue Implementation
#include <iostream>
#include <deque>


signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int t;
    std::cin >> t;
    while (t--) {
        int n, k;
        std::cin >> n >> k;
        std::deque<std::pair<int, int> > dq;
        int x;
        for (int i = 0; i < k; i++) {
            std::cin >> x;
            while (!dq.empty()) {
                if (dq.back().first <= x) dq.pop_back();
                else break;
            }
            dq.push_back(std::make_pair(x, i));
        }

        for (int i = k; i < n; i++) {
            std::cout << dq.front().first << " ";
            std::cin >> x;
            if (i - dq.front().second + 1 > k) dq.pop_front();
            while (!dq.empty()) {
                if (dq.back().first < x) dq.pop_back();
                else break;
            }
            dq.push_back(std::make_pair(x,i));
        }
        std::cout << dq.front().first << " ";
        std::cout << std::endl;
    }
}