#include <iostream>
#include <vector>
#include <algorithm>

void dfsIn(std::vector<std::vector<int> >& tree, std::vector<int>& inDP, int node, int parent) {
    inDP[node] = 0;
    int max1 = -1, max2 = -1;
    for (auto i: tree[node]) {
        if (i == parent) continue;
        dfsIn(tree, inDP, i, node);
        inDP[node] = std::max(inDP[node], 1 + inDP[i]);
    }
}

void dfsOut(std::vector<std::vector<int> >& tree, std::vector<int>& inDP,std::vector<int>& outDP, int node, int parent, int outVal) {
    outDP[node] = outVal;
    
    int max1 = -1, max2 = -1;
    for (auto i: tree[node]) {
        if (i == parent) continue;
        if (inDP[i] > max1) {
            max2 = max1;
            max1 = inDP[i];
        } else if (inDP[i] > max2) {
            max2 = inDP[i];
        }
    }

    for (auto i: tree[node]) {
        if (i == parent) continue;
        if (max1 == inDP[i]) {
            dfsOut(tree, inDP, outDP, i, node, std::max(max2 + 2, outDP[node] + 1));
        } else {
            dfsOut(tree, inDP, outDP, i, node, std::max(max1 + 2, outDP[node] + 1));
        }
    }
}

int main() {
    int n;
    int e;
    std::cin >> n >> e;
    std::vector<std::vector<int> > tree(n+1);
    int v1, v2;
    for (int i = 0; i < e; i++) {
        std::cin >> v1 >> v2;
        tree[v1].push_back(v2);
        tree[v2].push_back(v1);
    }

    std::vector<int> inDP(n+1);
    std::vector<int> outDP(n+1);
    dfsIn(tree, inDP, 1, 0);
    dfsOut(tree, inDP, outDP, 1, 0, 0);

    for (int i = 1; i <= n; i++) {
        std::cout << i << " : " << std::max(inDP[i], outDP[i]) << std::endl;
    }
}