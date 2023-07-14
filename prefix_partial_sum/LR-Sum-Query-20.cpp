#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1000000007;

signed main(){
    ios_base::sync_with_stdio(false);
    ll n, q, inp;
    cin >> n >> q;
    vector<ll> prefixSum(n+1);
    prefixSum[0] = 0;
    for(int i=1; i<=n; i++) {
        cin>>inp;
        prefixSum[i] = (prefixSum[i-1]+(inp%mod))%mod;
        if (prefixSum[i]<0){
            prefixSum[i] += mod;
        }
    }

    // for(int i=0;i<=n;i++){
    //     cout<<prefixSum[i]<<" ";
    // }
    // cout<<"\n";

    ll l,r, ans;
    while(q--){
        cin>>l>>r;
        ans = prefixSum[r]-prefixSum[l-1];
        if (ans<0) {
            ans +=mod;
        }
        cout<<ans<<"\n";
    }
}