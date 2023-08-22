#include <iostream>
#include <vector>

void dfs(std::vector<std::vector<int> >& graph, std::vector<int>& visited, std::vector<int>& parent, std::vector<int>& cyclePrefixSum, std::vector<int>& order, int node) {
    visited[node] = 1;
    for (auto neighbour: graph[node]) {
        if (visited[neighbour] == 0) {
            parent[neighbour] = node;
            dfs(graph, visited, parent, cyclePrefixSum, order, neighbour);
        }
        else if (visited[neighbour] == 1) {
            cyclePrefixSum[node]++;
            cyclePrefixSum[parent[neighbour]]--;
        }
    }
    visited[node] = 2;
    order.push_back(node);
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
    std::vector<int> parent(n+1, 0);
    std::vector<int> cyclePrefixSum(n+1, 0);
    std::vector<int> order;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(graph, visited, parent, cyclePrefixSum, order, i);
        }
    }
    for (auto node: order) {
        cyclePrefixSum[parent[node]] += cyclePrefixSum[node];
    }
    for (int i = 1; i <= n; i++) {
        std::cout << "Node " << i << " is part of " << cyclePrefixSum[i] << " cycles" << std::endl;
    }
}