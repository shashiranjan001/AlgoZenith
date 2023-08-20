
// DFS DETECT CYCLE YES/NO
// #include <iostream>
// #include <vector>

// bool dfs(std::vector<std::vector<int> >& graph, std::vector<int>& visited, int node) {
//     visited[node] = 1;
//     for (auto neighbour: graph[node]) {
//         if (!visited[neighbour]) {
//             if (dfs(graph, visited, neighbour)) return true;
//         }
//         else if (visited[neighbour] == 1) return true;
//     }
//     visited[node] = 2;
//     return false;
// }

// signed main() {
//     int n;
//     std::cin >> n;
//     int e;
//     std::cin >> e;
//     std::vector<std::vector<int> > graph(n+1);
//     int v1, v2;
//     for (int i = 0; i < e; i++) {
//         std::cin >> v1 >> v2;
//         graph[v1].push_back(v2);
//     }
//     // for (int i = 1; i <= n; i++) {
//     //     std::cout << i << " : ";
//     //     for (auto it: graph[i]) std::cout << it << " ";
//     //     std::cout << std::endl;
//     // }
//     std::vector<int> visited(n+1, 0);
//     for (int i = 1; i <= n; i++) {
//         if (!visited[i]) {
//             if (dfs(graph, visited, i)) {
//                 std::cout << "YES\n";
//                 return 0;
//             }
//         }
//     }
//     std::cout << "NO";
//     std::cout << std::endl;
// }

// DFS DETECT AND PRINT CYCLE
#include <iostream>
#include <vector>

bool dfs(std::vector<std::vector<int> >& graph, std::vector<int>& visited, std::vector<int>& parent, int node) {
    visited[node] = 1;
    for (auto neighbour: graph[node]) {
        if (visited[neighbour] == 0) {
            parent[neighbour] = node;
            if (dfs(graph, visited, parent, neighbour)) return true;
        }
        else if (visited[neighbour] == 1) {
            int current = node;
            std::vector<int> cycle;
            while(current != neighbour) {
                cycle.push_back(current);
                current = parent[node];
            }
            cycle.push_back(current);
            std::reverse(cycle.begin(), cycle.end());
            std::cout << "CYCLE: ";
            for (auto it: cycle) std::cout << it << "->";
            std::cout << cycle[0] << std::endl;
            return true;
        }
    }
    visited[node] = 2;
    return false;
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
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (dfs(graph, visited, parent, i)) {
                // for (int j = 1; j <= n; j++) std::cout << j << ":" << parent[j] << std::endl;
                std::cout << "YES\n";
                return 0;
            }
        }
    }
    std::cout << "NO";
    std::cout << std::endl;
}