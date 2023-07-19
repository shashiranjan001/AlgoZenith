#include <bits/stdc++.h>

using namespace std;

bool check(vector<int> &v, int index) {
    return v[index]>v[index+1];
}

int findPeakIndex(vector<int> &v) {
    int low=0, high=v.size()-2, ans=v.size()-1;
    while(low<=high) {
        int mid = low + (high-low)/2;
        if (check(v,mid)) {
            ans=mid;
            high=mid-1;
        } else {
            low=mid+1;
        }
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n,q,k;
        cin>>n>>q;
        vector<int> arr(n);
        for(int i=0; i<n; i++) {
            cin>>arr[i];
        }
        int peakID = findPeakIndex(arr);
        sort(arr.begin()+peakID+1, arr.end());
        while(q--){
            cin>>k;
            int leftId = lower_bound(arr.begin(), arr.begin()+peakID+1, k) - arr.begin();
            if (leftId<=peakID) {
                if (arr[leftId]==k){
                    cout<<leftId+1<<" ";
                }
            }
            int rightId = lower_bound(arr.begin()+peakID+1, arr.end(), k)-arr.begin();
            if (rightId<arr.size()) {
                if (arr[rightId] == k) {
                    cout<<peakID+arr.size()-rightId+1;
                }
            }
            cout<<endl;
        }
    }
}