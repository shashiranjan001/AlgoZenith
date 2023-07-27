#include <iostream>
#include <vector>
#include <cstdlib>

int n;

bool checkConflict(int level, const std::vector<int>& curr, int pos) {
    for (int i = 0; i < curr.size(); i++) {
        int x1 = i;
        int y1 = curr[i];
        int x2 = level;
        int y2 = pos;
        if (abs(x1-x2) == abs(y1-y2) || y1 == y2) return true;
        int X[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
        int Y[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
        for (int i = 0; i < 8; i++) {
 
        // Position of knight after move
        int x = x2 + X[i];
        int y = y2 + Y[i];
 
        // count valid moves
        if (x >= 0 && y >= 0 && x < n && y < n && x==x1 && y==y1) return true;
    }
 
    }
    return false;
}

void rec(int level, std::vector<int> &curr, int &count) {
    if (level == n) {
        if (curr.size() == n) {
            count++;
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        // if (board[level][i] == 0) {
            if (!checkConflict(level, curr, i)) {
                curr.push_back(i);
                // std::cout<<" Level = " << level << ": ";
                // for (auto it: curr) {
                //     std::cout << it << " ";
                // }
                // std::cout << std::endl; 
                rec(level+1, curr, count);
                curr.pop_back();
            }
        // }
    }
}

signed main() {
    std::cin >> n;
    // std::vector<std::vector<int> > board(n, std::vector<int>(n,0));
    // char c;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         std::cin >> c;
    //         if (c == '*') board[i][j] = 1;
    //     }
    // }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         if (board[i][j]) std::cout << "1 ";
    //         else std::cout << "0 ";
    //     }
    //     std::cout << std::endl;
    // }

    
    std::vector<int> curr;
    int count = 0;
    rec(0, curr, count);
    std::cout << count << std::endl;
}