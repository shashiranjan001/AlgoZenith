#include <iostream>
#include <vector>

struct node {
    int min;
    int count;
    node(int minn, int countt) {
        min = minn;
        count = countt;
    }
};

node merge(node a, node b) {
    if(a.min == b.min) {
        return node(a.min, a.count+b.count);
    }
    if (a.min < b.min) return a;
    return b;
}

void buildTree(std::vector<int>& input, std::vector<node>& segTree, int index, int l, int r) {
    if (l == r) {
        segTree[index] = node(input[l], 1);
        return;
    }
    int mid = (l+r)/2;
    buildTree(input, segTree, 2*index, l, mid);
    buildTree(input, segTree, 2*index + 1, mid+1, r);
    segTree[index] = merge(segTree[2*index], segTree[2*index + 1]);
}

void update(std::vector<int>& input, std::vector<node>& segTree, int index, int l, int r, int pos, int val) {
    if (pos < l || pos > r) return;
    if (l == r) {
        input[pos] = val;
        segTree[index].min = val;
        return;
    }
    int mid = (l + r)/2;
    update(input, segTree, 2*index, l, mid, pos, val);
    update(input, segTree, 2*index + 1, mid + 1, r, pos, val);
    segTree[index] = merge(segTree[2*index], segTree[2*index + 1]);
}

node query(std::vector<node>& segTree, int index, int l, int r, int lq, int rq) {
    if (lq > r || rq < l) return node(1e9, 1);
    if (lq <= l && r <= rq) return segTree[index];
    int mid = (l + r)/2;
    return merge(query(segTree, 2*index, l, mid, lq, rq), query(segTree, 2*index + 1, mid + 1, r, lq, rq));

}

int main() {
    int n; 
    std::cin >> n;
    std::vector<int> input(n);
    for (int i = 0; i < n; i++) std::cin >> input[i];
    for (auto i: input) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::vector<node> segTree(4*n, node(1e9, 1));
    buildTree(input, segTree, 1, 0, n-1);

    for (auto i: segTree) {
        std::cout << i.min << " " << i.count << std::endl;
    }
    std::cout << std::endl;
    int q;
    std::cin >> q;
    for (int i = 0; i < q; i++) {
        int tp;
        std::cin >> tp;
        if (tp == 1) {
            int x, v;
            std::cin >> x >> v;
            update(input, segTree, 1, 0, n-1, x, v);
        } else {
            int l, r;
            std::cin >> l >> r;
            node ans = query(segTree, 1, 0, n-1, l, r);
            std::cout << ans.min << " " << ans.count << std::endl;
        }
    }
}