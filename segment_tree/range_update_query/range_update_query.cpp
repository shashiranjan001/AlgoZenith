#include <iostream>
#include <vector>

void buildTree(std::vector<int>& input, std::vector<int>& segTree, int index, int l, int r) {
    if (l == r) {
        segTree[index] = input[l];
        return;
    }
    int mid = (l+r)/2;
    buildTree(input, segTree, 2*index, l, mid);
    buildTree(input, segTree, 2*index + 1, mid+1, r);
    segTree[index] = segTree[2*index] + segTree[2*index + 1];
}

void update(std::vector<int>& input, std::vector<int>& segTree, int index, int l, int r, int pos, int val) {
    if (pos < l || pos > r) return;
    if (l == r) {
        input[pos] = val;
        segTree[index] = val;
        return;
    }
    int mid = (l + r)/2;
    update(input, segTree, 2*index, l, mid, pos, val);
    update(input, segTree, 2*index + 1, mid + 1, r, pos, val);
    segTree[index] = segTree[2*index] + segTree[2*index + 1];
}

int query(std::vector<int>& segTree, int index, int l, int r, int lq, int rq) {
    if (lq > r || rq < l) return 0;
    if (lq <= l && r <= rq) return segTree[index];
    int mid = (l + r)/2;
    return query(segTree, 2*index, l, mid, lq, rq) + query(segTree, 2*index + 1, mid + 1, r, lq, rq);

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

    std::vector<int> segTree(4*n);
    buildTree(input, segTree, 1, 0, n-1);

    for (auto i: segTree) {
        std::cout << i << " ";
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
            std::cout << query(segTree, 1, 0, n-1, l, r) << std::endl;
        }
    }
}