#include <iostream>
#include <vector>

struct node {
    int addition;
    node() {
        addition = 0;
    }
    node(int _addition) {
        addition = _addition;
    }
};

node merge(node a, node b) {
    return node(a.addition + b.addition);
}

void buildTree(std::vector<int>& input, std::vector<node>& segTree, int index, int l, int r) {
    if (l == r) {
        segTree[index] = node(0);
        return;
    }
    int mid = (l+r)/2;
    buildTree(input, segTree, 2*index, l, mid);
    buildTree(input, segTree, 2*index + 1, mid + 1, r);
    segTree[index] = merge(segTree[2*index], segTree[2*index + 1]);
}

void update(std::vector<node>& segTree, int index, int l, int r, int lq, int rq, int addVal) {
    if (l > rq || r < lq) return;
    if (lq <= l && r <= rq) {
        segTree[index].addition += addVal;
        return;
    }
    int mid = (l + r)/2;
    update(segTree, 2*index, l, mid, lq, rq, addVal);
    update(segTree, 2*index + 1, mid + 1, r, lq, rq, addVal);
}

int query(std::vector<node>& segTree, int index, int l, int r, int pos) {
    if (pos < l || pos > r) return 0;
    if (l == r) return segTree[index].addition;
    int mid = (l+r)/2;
    int left = query(segTree, 2*index, l, mid, pos);
    int right = query(segTree, 2*index + 1, mid + 1, r, pos);
    return left + right + segTree[index].addition;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> input(n);
    for (int i = 0; i < n; i++) std::cin >> input[i];
    for (int i = 0; i < n; i++) std::cout << input[i] << " ";
    std::cout << std::endl;
    std::cout << std::endl;

    std::vector<node> segTree(4*n, node());

    buildTree(input, segTree, 1, 0, n-1);
    for (node& i: segTree) {
        std::cout << i.addition << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    int q;
    std::cin >> q;
    for (int i = 0; i < q; i++) {
        int tp;
        std::cin >> tp;
        if (tp == 1) {
            int l, r, v;
            std::cin >> l >> r >> v;
            update(segTree, 1, 0, n-1, l, r, v);
            for (node& i: segTree) {
                std::cout << i.addition << " ";
            }
            std::cout << std::endl;
        } else {
            int pos;
            std::cin >> pos;
            std::cout << query(segTree, 1, 0, n-1, pos) + input[pos] << std::endl;
        }
    }

}