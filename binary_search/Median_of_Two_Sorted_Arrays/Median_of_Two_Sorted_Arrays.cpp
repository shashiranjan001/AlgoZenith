#include <iostream>
#include <vector>
#include <algorithm>

double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::vector<int> a, b;
    if (nums1.size() >= nums2.size()) {
        a = nums1;
        b = nums2;
    } else {
        a = nums2;
        b = nums1;
    }
    int n = a.size(), m = b.size();
    int low = 0;
    int high = n-1;
    int mid;
    int elementsA;
    int elementsB;
    int leftA=INT_MIN, leftB=INT_MIN, rightA=INT_MAX, rightB=INT_MAX;
    while (low <= high) {
        mid = (low + high)/2;
        elementsA = mid + 1;
        elementsB = (n + m + 1)/2 - elementsA;
        leftA = a[mid];
        if (mid + 1 < n) rightA = a[mid+1];
        if (elementsB >= 0) leftB = b[elementsB - 1];
        if (elementsB < n) rightB = b[elementsB];

        if (leftA <= rightB && leftB <= rightB) break;

        if (leftA > rightB) high = mid - 1;
        else low = mid + 1;
    }
    if ((n + m) % 2 != 0) {
        double answer = std::max (leftA, leftB);
        return answer;
    }
    return (std::max(leftA, leftB) + std::min(rightA, rightB))/2.0;
}

signed main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        std::vector<int> a(n), b(m);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            std::cin >> b[i];
        }
        double answer = findMedianSortedArrays(a, b);
        std::cout << answer << std::endl;
    }
}