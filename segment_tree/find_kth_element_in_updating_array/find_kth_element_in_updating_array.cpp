#include <iostream>
#include <vector>

#define ll long long int

void add(std::vector<ll>& segTree, ll index, ll l, ll r, ll pos) {
    if (pos < l || pos > r) return;
    if (l == r) {
        segTree[index]++;
        return;
    }
    ll mid = (l + r)/2;
    add(segTree, 2*index, l, mid, pos);
    add(segTree, 2*index + 1, mid + 1, r, pos);
    segTree[index] = segTree[2*index] + segTree[2*index + 1];
}

void remove(std::vector<ll>& segTree, ll index, ll l, ll r, ll pos) {
    if (l > pos || r < pos) return;
    if (l == r) {
        segTree[index]--;
        return;
    }
    ll mid = (l + r)/2;
    remove(segTree, 2*index, l, mid, pos);
    remove(segTree, 2*index + 1, mid + 1, r, pos);
    segTree[index] = segTree[2*index] + segTree[2*index + 1];
}

ll find(std::vector<ll>& segTree, ll index, ll l, ll r, ll k) {
    if (l == r) return  l;
    ll mid = (l + r)/2;
    if (k <= segTree[2*index]) {
        return find(segTree, 2*index, l, mid, k);
    }
    return find(segTree, 2*index + 1, mid + 1, r, k - segTree[2*index]);
}

int main() {

    std::vector<ll> segTree(400001, 0);
    // std::cout << "Hello\n";
    ll q;
    std::cin >> q;
    for (ll i = 0; i < q; i++) {
        ll tp, num;
        std::cin >> tp >> num;
        // std::cout << tp << " " << num << std::endl;
        if (tp == 1) {
            add(segTree, 1, 0, 100000, num);
            // std::cout << "Query1\n";
        } else if (tp == 2) {
            remove(segTree, 1, 0, 100000, num);
        } else {
            std::cout << find(segTree, 1, 0, 100000, num) << std::endl;
        }
    }
}