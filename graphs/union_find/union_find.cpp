#include <vector>
#include <iostream>

struct UnionFind {
    int n, comps;
    std::vector<int> parent, rank;
    UnionFind(int size) {
        n = size;
        for (int i = 0; i < n; i++) {
            parent.push_back(i);
            rank.push_back(1);
        }
        comps = size-1;
    }
    int find(int x) {
        if (parent[x] == x) return x;
        parent[x] = find(parent[x]);
        return parent[x];
    
    }
    void merge(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;
        int rankX = rank[x];
        int rankY = rank[y];
        if (rankX >= rankY) {
            parent[py] = px;
            rank[px] += rank[py];
        } else {
            parent[px] = py;
            rank[py] += rank[px];
        }
        comps--;
    }
};

int main () {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int n, m, q;
    std::cin >> n >> m >> q;
    UnionFind container(n+1);
    for (int i = 0; i < m; i++) {
        int v1, v2;
        std::cin >> v1 >> v2;
        container.merge(v1, v2);
    }
    for (int i = 0; i < q; i++) {
        int a, b, c;
        std::cin >> a;
        if (a == 1) {
            std::cin >> b;
            std::cout << container.rank[container.parent[b]] << std::endl;
        } else {
            std::cin >> b >> c;
            if (container.parent[b] == container.parent[c]) {
                std::cout << "YES" << std::endl;
            } else {
                std::cout << "NO" << std::endl;
            }
        }
    }
}