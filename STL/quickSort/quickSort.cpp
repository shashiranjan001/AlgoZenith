#include <vector>
#include <iostream>
#include <algorithm>

void swap(std::vector<int>& input, int i, int j) {
    int temp = input[i];
    input[i] = input[j];
    input[j] = temp;
}

int partition(std::vector<int>& input, int st, int en) {
    int pivotElement = input[en];
    int wall = st-1;
    for (int j = st; j <= en-1; j++) {
        if (input[j] <= pivotElement) {
            wall++;
            swap(input, wall, j);
        }
    }
    swap(input, wall+1, en);
    return wall+1;
}

void quickSort(std::vector<int>& input, int st, int en) {
    if (st < en) {
        int pivot = partition(input, st, en);
        quickSort(input, st, pivot-1);
        quickSort(input, pivot+1, en);
    }
}

int main () {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> array(n);
        for (int i = 0; i < n; i++) {
            std::cin >> array[i];
        }

        quickSort(array, 0, n-1);
        for (auto i: array) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

}
