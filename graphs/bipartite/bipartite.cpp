#include <iostream>
#include <vector>

bool dfs(std::vector<std::vector<int> > graph, std::vector<int>& color, int node) {
    for (auto i: graph[node]) {
        if (color[i] == color[node]) return true;
        if (color[i]) continue;
        if (color[node]%2) color[i] = color[node] + 1;
        else color[i] = color[node] - 1;
        if (dfs(graph, color, i)) return true;
    }
    return false;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int> > graph(n);
    int v1, v2;
    for (int i = 0; i < m; i++) {
        std::cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    std::vector<int> color(n, 0);
    int parentColor = 1;
    bool isBipartite = true;
    for (int i = 0; i < n; i++) {
        if (!color[i]) {
            color[i] = parentColor;
            if (dfs(graph, color, i)) {
                isBipartite = false;
                break;
            }
        }
        parentColor += 2;
    }
    for (auto i: color) std::cout << i << " ";
    std::cout << std::endl;
    if (isBipartite) {
        std::cout <<"Graph is bipartite" << std::endl;
    } else {
        std::cout <<"Graph is not bipartite" << std::endl;
    }
}