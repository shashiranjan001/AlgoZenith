// DFS DETECT AND PRINT CYCLE IN UNDIRECTED GRAPH
#include <iostream>
#include <vector>

void dfs(std::vector<std::vector<int> >& graph, std::vector<int>& visited, std::vector<int>& parent, int node, bool& is_cycle) {
    visited[node] = 1;
    for (auto neighbour: graph[node]) {
        if (neighbour == parent[node]) continue;
        if (visited[neighbour] == 0) {
            parent[neighbour] = node;
            dfs(graph, visited, parent, neighbour, is_cycle);
        }
        else if (visited[neighbour] == 1) {
            int current = node;
            std::vector<int> cycle;
            while(current != neighbour) {
                cycle.push_back(current);
                current = parent[current];
            }
            cycle.push_back(current);
            std::reverse(cycle.begin(), cycle.end());
            std::cout << "CYCLE: ";
            for (auto it: cycle) std::cout << it << "->";
            std::cout << cycle[0] << std::endl;
            is_cycle = true;
        }
    }
    visited[node] = 2;
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
        graph[v2].push_back(v1);
    }
    // for (int i = 1; i <= n; i++) {
    //     std::cout << i << " : ";
    //     for (auto it: graph[i]) std::cout << it << " ";
    //     std::cout << std::endl;
    // }
    std::vector<int> visited(n+1, 0);
    std::vector<int> parent(n+1, 0);
    bool is_cycle = false;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(graph, visited, parent, i, is_cycle);
        }
    }
    if (is_cycle) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
}