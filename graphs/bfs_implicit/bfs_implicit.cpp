#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

bool valid(const std::vector<std::string>& grid, const std::pair<int, int>& node, int n, int m) {
    if (node.first < 0 || node.first >= n || node.second < 0 || node.second >= m || grid[node.first][node.second] == '#') return false;
    return true;
}

int bfs (const std::vector<std::string>& grid,  const std::pair<int, int>& start, const std::pair<int, int>& end) {
    int n = grid.size();
    int m = grid[0].length();
    std::cout << "n = " << n << " m = " << m << std::endl;
    int dirX[] = {0, 1, 1, 1, 0, -1, -1, -1};
    int dirY[] = {1, 1, 0, -1, -1, -1, 0, 1};
    std::vector<std::vector<int> > distance(n, std::vector<int> (m, 100));
    std::vector<std::vector<std::pair<int, int> > > parent(n, std::vector<std::pair<int, int> > (m, std::make_pair(-1,-1)));
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j++) std::cout << distance[i][j] << " ";
        std::cout << std::endl;
    }
    distance[start.first][start.second] = 0;
    std::queue<std::pair<int, int> > bfsQ;
    bfsQ.push(start);
    while(!bfsQ.empty()) {
        std::pair <int, int> current = bfsQ.front();
        std::cout << "current = " << current.first << ","  << current.second << std::endl;
        for (int i = 0; i < 8; i++) {
            std::pair<int, int> neighbor = std::make_pair(current.first + dirX[i], current.second + dirY[i]);
            if (!valid(grid, neighbor, n, m)) continue;
            if (distance[neighbor.first][neighbor.second] > distance[current.first][current.second] + 1) {
                parent[neighbor.first][neighbor.second] = current;
                distance[neighbor.first][neighbor.second] = distance[current.first][current.second] + 1;
                bfsQ.push(neighbor);
            }
        }
        bfsQ.pop();
        // if (distance[end.first][end.second] < 100) break;
    }
    if (distance[end.first][end.second] == 1e9) return -1;
    std::vector<std::pair<int, int> > path;
    std::pair<int, int> current = end;
    while (current != start) {
        path.push_back(current);
        current = parent[current.first][current.second];
    }
    path.push_back(current);
    reverse(path.begin(), path.end());
    for (auto it: path) {
        std::cout << it.first << "," << it.second << " -> ";
    }
    std::cout << std::endl;
    return distance[end.first][end.second];
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> grid(n);
    for (int i = 0; i < n; i++) std::cin >> grid[i];
    std::pair<int, int> start, end;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'S') {
                start = std::make_pair(i,j);
            } else if (grid[i][j] == 'E') {
                end = std::make_pair(i,j);
            }
        }
    }
    for (int i = 0; i < n; i++) std::cout << grid[i] << std::endl;
    std::cout << "start = " << start.first << ","  << start.second << " end = " << end.first << "," << end.second << std::endl;
    std::cout << bfs(grid, start, end) << std::endl;
}