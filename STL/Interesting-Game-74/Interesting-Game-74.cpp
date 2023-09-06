#include <vector>
#include <iostream>
#include <algorithm>

bool customSort(std::pair<int, int>& a, std::pair<int, int>& b) {
    return a.first + a.second > b.first + b.second;
}

void solve (std::vector<int>& A, std::vector<int>& B) {
    std::vector<std::pair<int, int> > sum;
    for (int i = 0; i < A.size(); i++) {
        sum.push_back(std::make_pair(A[i], B[i]));
    }
    std::sort(sum.begin(), sum.end(), customSort);
    int sumA = 0, sumB = 0;
    int turn = 0;
    for (int i = 0; i < A.size(); i++) {
        if (!turn) sumA += sum[i].first;
        else sumB += sum[i].second;
        turn = 1 - turn;
    }
    if (sumA > sumB) std::cout << "Alice" << std::endl;
    else if(sumA < sumB) std::cout << "Bob" << std::endl;
    else std::cout << "Tie" << std::endl;
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int t; 
    std::cin >> t;
    while (t--) {
        int n; 
        std::cin >> n;
        std::vector<int> A(n), B(n);
        for (int i = 0; i < n; i++) {
            std::cin >> A[i];
        }
        for (int i = 0; i < n; i++) {
            std::cin >> B[i];
        }
        solve(A, B);
    }
}