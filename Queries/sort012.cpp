#include <iostream>
#include <vector>

void swap(std::vector<int>& input, int i, int j) {
    int temp = input[i];
    input[i] = input[j];
    input[j] = temp;
}

signed main() {
    int n;
    std::cin >> n;
    std::vector<int> array(n); 
    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
    }
    int zeroStPtr = -1;
    int zeroEnPtr = -1;
    int oneStPtr = -1;
    int oneEnPtr = -1;
    int twoStPtr = -1;
    int twoStPtr = -1;
    for (int i = 0; i < n; i++) {
        if (array[i] == 0) {
            if(zeroPtr+1 < n) {
                swap(array, zeroPtr+1, i);
                zeroPtr++;
            }
        }
        if (array[i] == 1) {
            if(onePtr+1 < n) {
                swap(array, onePtr+1, i);
                onePtr++;
            }
        }
        if (array[i] == 2) {
            if(twoPtr+1 < n) {
                swap(array, twoPtr+1, i);
                twoPtr++;
            }
        }
    }

    for(auto it: array) std::cout << it << " ";
    std::cout << std::endl;
}

// 5621389
// 215689

//120200121000121
// 000000012121211
// 00000001111112222

how to partiotion an array on an element