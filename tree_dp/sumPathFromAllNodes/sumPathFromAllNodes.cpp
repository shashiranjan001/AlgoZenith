#include <iostream>
#include <vector>

void dfsIn(int node, std::vector<std::vector<int> >& tree, std::vector<int>& sizeArr, std::vector<int>& inDP, int parent) {
    sizeArr[node] = 1;
    inDP[node] = 0;

    for (auto i: tree[node]) {
        if (i == parent) continue;
        dfsIn(i, tree, sizeArr, inDP, node);
        sizeArr[node] += sizeArr[i];
        inDP[node] += inDP[i] + sizeArr[i];
    }
}

void dfsOut(int node, std::vector<std::vector<int> >& tree, std::vector<int>& sizeArr, std::vector<int>& inDP, std::vector<int>& outDP, int parent) {
    if (node == 1)
        outDP[node] = 0;
    else
        outDP[node] = outDP[parent] + inDP[parent] - (inDP[node] + sizeArr[node]) + (tree.size() - 1 - sizeArr[node]);

    for (auto i: tree[node]) {
        if (i == parent) continue;
        dfsOut(i, tree, sizeArr, inDP, outDP,node);
    }
}

int main () {
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
    std::vector<int> sizeArr(n+1);
    std::vector<int> inDP(n+1);
    std::vector<int> outDP(n+1);
    dfsIn(1, tree, sizeArr, inDP, 0);
    dfsOut(1, tree, sizeArr, inDP, outDP, 0);
    for (int i = 1; i <=n; i++) {
        std::cout << i << " : " << inDP[i] + outDP[i] << std::endl;
    }
}