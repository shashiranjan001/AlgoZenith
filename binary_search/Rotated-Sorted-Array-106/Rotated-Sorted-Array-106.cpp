#include <bits/stdc++.h>

using namespace std;

bool check(int curr, int zero) {
    return curr<zero;
}

signed main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0; i<n; i++) {
            cin>>arr[i];
        }
        int low = 0, high = n-1, ans=0;
        while(low<=high) {
            int mid = low + (high-low)/2;
            if(check(arr[mid], arr[0])){
                high = mid-1;
                ans = mid;
            } else {
                low=mid+1;
            }
        }
        cout<<ans<<endl;
    }

}