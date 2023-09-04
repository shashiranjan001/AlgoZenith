#include <iostream>
#include <vector>

void dfs(std::vector<std::vector<int> >& graph, std::vector<int>& visited, int node) {
    std::cout << node << "->";
    visited[node] = 1;
    for (auto neighbour: graph[node]) {
        if (!visited[neighbour]) dfs(graph, visited, neighbour);
    }
}

signed main() {
    int n;
    std::cin >> n;
    int e;
    std::cin >> e;
    std::vector<std::vector<int> > graph(n+1);
    int v1, v2;
    for (int i = 0; i < e; i++) {
        std::cin >> v1 >> v2;
        graph[v1].push_back(v2);
    }
    // for (int i = 1; i <= n; i++) {
    //     std::cout << i << " : ";
    //     for (auto it: graph[i]) std::cout << it << " ";
    //     std::cout << std::endl;
    // }
    std::vector<int> visited(n+1, 0);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) dfs(graph, visited, i);
    }
    std::cout << std::endl;
}