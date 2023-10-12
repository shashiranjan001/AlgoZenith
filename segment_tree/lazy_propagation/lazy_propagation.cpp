#include <iostream>
#include <vector>

struct node {
    int sum;
    int maxx;
    int lazy;
    node() {
        sum = 0;
        maxx = 0;
        lazy = 0;
    }
};

node merge(node a, node b) {
    node temp;
    temp.sum = a.sum + b.sum;
    temp.maxx = std::max(a.maxx, b.maxx);
    return temp;
}

void build(std::vector<int>& input, std::vector<node>& segTree, int index, int l, int r) {
    if (l == r) {
        segTree[index].sum = input[l];
        segTree[index].maxx = input[l];
        return;
    }

    int mid = (l + r)/2;
    build(input, segTree, index << 1, l, mid);
    build(input, segTree, index << 1 | 1, mid + 1, r);
    segTree[index] = merge(segTree[index << 1], segTree[index << 1 | 1]);
}

void push(std::vector<node>& segTree, int index, int l, int r) {
    if (segTree[index].lazy) {
        segTree[index].sum = segTree[index].lazy*(r - l + 1);
        segTree[index].maxx = segTree[index].lazy;
        if (l != r) {
            segTree[index << 1].lazy = segTree[index].lazy;
            segTree[index << 1 | 1].lazy = segTree[index].lazy;
        }
        segTree[index].lazy = 0;
    }
}

void update(std::vector<node>& segTree, int index, int l, int r, int lq, int rq, int v) {
    push(segTree, index, l, r);
    if (l > rq || r < lq) return;
    if (lq <= l && r <= rq) {
        segTree[index].lazy = v;
        push(segTree, index, l, r);
        return;
    }

    int mid = (l + r)/2;
    update(segTree, index << 1, l, mid, lq, rq, v);
    update(segTree, index << 1 | 1, mid + 1, r, lq, rq, v);
    segTree[index] = merge(segTree[index << 1], segTree[index << 1 | 1]);
}

node query(std::vector<node>& segTree, int index, int l, int r, int lq, int rq) {
    push(segTree, index, l, r);
    if (lq > r || rq < l) return node();
    if (lq <= l && r <= rq) return segTree[index];
    int mid = (l + r)/2;
    return merge(query(segTree, index << 1, l, mid, lq, rq), query(segTree, index << 1 | 1, mid + 1, r, lq, rq));
}

void printt(std::vector<node>& segTree) {
    for (auto n: segTree) {
        std::cout << n.sum << ":" << n.maxx << ":" << n.lazy << std::endl;
    }
    std::cout << "--------------" << std::endl;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> input(n);
    for (int i = 0; i < n; i++) {
        std::cin >> input[i];
    }

    std::vector<node> segTree(4*n, node());
    build(input, segTree, 1, 0, n-1);
    int q;
    std::cin >> q;
    for (int i = 0; i < q; i++) {
        int tp;
        std::cin >> tp;
        if (tp == 1) {
            int l, r, v;
            std::cin >> l >> r >> v;
            update(segTree, 1, 0, n-1, l , r, v);
        } else {
            int l, r;
            std::cin >> l >> r;
            node ans = query(segTree, 1, 0, n-1, l ,r);
            std::cout << "sum = " << ans.sum << " max = " << ans.maxx << std::endl;
        }
    }
} 