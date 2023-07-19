#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll mod = 1e9+7;

signed main(){
    ios_base::sync_with_stdio(false);
    ll n, m, q, x1, x2, y1, y2, c;
    cin>>n>>m>>q;
    vector<vector<ll> > arr(n+2, vector<ll>(m+2,0));
    for(int i=0; i<q; i++) {
        cin>>x1>>y1>>x2>>y2>>c;
        arr[x1][y1] += c;
        arr[x2+1][y1] -= c;
        arr[x1][y2+1] -= c;
        arr[x2+1][y2+1] +=c;
    }
    ll maxx = -mod*mod;
    for(ull i=1; i<=n; i++){
        for(ull j=1; j<=m; j++){
            arr[i][j]  = (arr[i][j] + arr[i][j-1])/*%mod*/;
            arr[i][j]  = (arr[i][j] + arr[i-1][j])/*%mod*/;
            arr[i][j]  = (arr[i][j] - arr[i-1][j-1])/*%mod*/;
            // if(arr[i][j] < 0) arr[i][j] += mod;
            maxx = max(arr[i][j], maxx);
        }
    }

    ull count=0;
    for(ull i=1; i<=n; i++){
        for(ull j=1; j<=m; j++){
            if(arr[i][j] == maxx) ++count;
        }
    }

    cout<<maxx<<" "<<count<<endl;
}