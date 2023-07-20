// Copyright 2023 Shashi

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximumElement(const vector<int> &array) {
    int ans = array[0];
    for (int i = 1; i < array.size(); i++) {
        ans = max(ans, array[i]);
    }
    return ans;
}

int sumArray(const vector<int> &array) {
    int64_t sum = 0;
    for (int i = 0; i < array.size(); i++) {
        sum += array[i];
    }
    return sum;
}

bool checkForV(const vector<int> &array, int v, int k) {
    int64_t sum = array[0];
    int index = 1, painters = 1;
    while (index < array.size()) {
        if (sum + array[index] > v) {
            sum = array[index];
            painters++;
            if (painters > k) {
                return false;
            }
        } else {
            sum += array[index];
        }
        index++;
    }
    return true;
}

void solve(const vector<int> &array, int k) {
    int size = array.size();
    int64_t maximum = maximumElement(array);
    int64_t sum = sumArray(array);

    int64_t low = maximum;
    int64_t high = sum;

    int64_t ans = sum;

    while (low <= high) {
        int64_t mid = low + (high-low)/2;
        if (checkForV(array, mid, k)) {
            ans = mid;
            high = mid-1;
        } else {
            low = mid+1;
        }
    }
    cout<< ans<< endl;
}

signed main() {
    int t, n, k;
    cin >> t;
    while (t--) {
        cin>> n>> k;
        vector<int> array(n);
        for (int i = 0; i < n; i++) {
            cin>> array[i];
        }
        solve(array, k);
    }
}
