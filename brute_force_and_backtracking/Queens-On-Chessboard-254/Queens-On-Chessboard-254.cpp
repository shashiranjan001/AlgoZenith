#include <iostream>
#include <vector>
#include <cstdlib>

bool checkConflict(int level, const std::vector<int>& curr, int pos) {
    for (int i = 0; i < curr.size(); i++) {
        int x1 = i;
        int y1 = curr[i];
        int x2 = level;
        int y2 = pos;
        if (abs(x1-x2) == abs(y1-y2) || y1 == y2) return true;
    }
    return false;
}

void rec(int level, std::vector<int> &curr, std::vector<std::vector<int> > &board, int &count) {
    if (level == board.size()) {
        if (curr.size() == board.size()) {
            count++;
        }
        return;
    }

    for (int i = 0; i < board.size(); i++) {
        if (board[level][i] == 0) {
            if (!checkConflict(level, curr, i)) {
                curr.push_back(i);
                // std::cout<<" Level = " << level << ": ";
                // for (auto it: curr) {
                //     std::cout << it << " ";
                // }
                // std::cout << std::endl; 
                rec(level+1, curr, board, count);
                curr.pop_back();
            }
        }
    }
}

signed main() {
    int n = 8;
    std::vector<std::vector<int> > board(n, std::vector<int>(n,0));
    char c;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> c;
            if (c == '*') board[i][j] = 1;
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         if (board[i][j]) std::cout << "1 ";
    //         else std::cout << "0 ";
    //     }
    //     std::cout << std::endl;
    // }

    
    std::vector<int> curr;
    int count = 0;
    rec(0, curr, board, count);
    std::cout << count << std::endl;
}