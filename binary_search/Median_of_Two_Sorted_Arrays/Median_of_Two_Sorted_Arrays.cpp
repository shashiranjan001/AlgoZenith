#include <iostream>
#include <vector>
#include <algorithm>

    double findMedianSortedArrays(std::vector<int>& a, std::vector<int>& b) {
        int n = a.size(), m = b.size();
        if (n<m) return findMedianSortedArrays(b, a);
        // std::cout << "Array A : ";
        // for (int i = 0; i < n; i++) {
        //     std::cout << a[i] << " ";
        // }
        // std::cout << "\nArray B : ";
        // for (int i = 0; i < m; i++) {
        //     std::cout << b[i] << " ";
        // }
        // std::cout<<std::endl;
        int low = 0;
        int high = n-1;
        int mid;
        int elementsA;
        int elementsB;
        int leftA, leftB, rightA, rightB;
        while (low <= high) {
            leftA=INT_MIN, leftB=INT_MIN, rightA=INT_MAX, rightB=INT_MAX;
            mid = (low + high)/2;
            elementsA = mid + 1;
            elementsB = (n + m + 1)/2 - elementsA;
            elementsB = elementsB > m ? m:elementsB;
            elementsB = elementsB < 0 ? 0:elementsB;
            if (elementsA + elementsB < (n+m+1)/2) {
                low = mid+1;
                continue;
            }
            if ((n-elementsA) + (m-elementsB) < (n+m)/2){
                high = mid - 1;
                continue;
            } 
            leftA = a[mid];
            if (mid + 1 < n) rightA = a[mid+1];
            if (elementsB > 0) leftB = b[elementsB - 1];
            if (elementsB < m) rightB = b[elementsB];

            if (leftA > rightB) high = mid - 1;
            if (leftB > rightA) low = mid + 1;

            if (leftA <= rightB && leftB <= rightA) {
                if (elementsA + elementsB == (n+m+1)/2) {
                    break;
                } else if (elementsA + elementsB > (n+m+1)/2) {
                    high = mid-1;
                } else {
                    low = mid + 1;
                }
            }
        }
        // std::cout<< "mid = " << mid << " elementsA " << elementsA << " elementsB " << elementsB << " leftA " << leftA <<" leftB " << leftB << " rightA " << rightA << " rightB " << rightB << std::endl;
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