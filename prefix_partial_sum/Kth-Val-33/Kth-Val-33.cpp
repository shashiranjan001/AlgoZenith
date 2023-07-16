#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
    ios_base::sync_with_stdio(false);
    ll t, n, m, q, l, r, k;
    cin>>t;
    while(t--){
        cin>>n>>m>>q;
        vector<ll> arr(n+1);
        vector<ll> countPrefixSum(n+2,0);
        for(int i=1; i<=n; i++){
            cin>>arr[i];
        }
        // cout<<"array = ";
        // for(int i=1; i<=n; i++) {
        //     cout<<arr[i]<<" ";
        // }
        // cout<<endl;

        for(int i=0; i<m; i++) {
            cin>>l>>r;
            countPrefixSum[l]++;
            countPrefixSum[r+1]--;
        }
        for(int i=1; i<=n; i++){
            countPrefixSum[i] += countPrefixSum[i-1];
        }
        // cout<<"countPrefixSum = ";
        // for(int i=1; i<=n; i++) {
        //     cout<<countPrefixSum[i]<<" ";
        // }
        // cout<<endl;

        vector<pair<ll,ll> > countIndex;
        for(int i=1; i<=n; i++) {
            countIndex.push_back(make_pair(arr[i], countPrefixSum[i]));
        }
        // cout<<"countIndex = ";
        // for(int i=0; i<n; i++) {
        //     cout<<countIndex[i].first<<":"<<countIndex[i].second<<"|";
        // }
        // cout<<endl;

        sort(countIndex.begin(), countIndex.end());
        // cout<<"sorted countIndex = ";
        // for(int i=0; i<n; i++) {
        //     cout<<countIndex[i].first<<":"<<countIndex[i].second<<"|";
        // }
        // cout<<endl;


        for(int i=1;i<n;i++){
            countIndex[i].second += countIndex[i-1].second;
        }

        vector<ll> final(n);
        for(int i=0; i<n; i++){
            final[i]=countIndex[i].second;
        }
        // cout<<"final = ";
        // for(int i=0; i<n; i++) {
        //     cout<<final[i]<<" ";
        // }
        // cout<<endl;

        for(int i=0; i<q; i++) {
            cin>>k;
            if (lower_bound(final.begin(), final.end(), k) != final.end()) {
                int x = lower_bound(final.begin(), final.end(), k) - final.begin();
                cout << countIndex[x].first << " ";
            } else {
                cout << "-1 ";
            }
        }
        cout << endl;
        // cout<<"t="<<t+1<<"\n\n\n";
    }
}
