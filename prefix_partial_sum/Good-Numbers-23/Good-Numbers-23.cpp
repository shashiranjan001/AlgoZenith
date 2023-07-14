#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007;
ll N = 1e6+7;

signed main(){
    ios_base::sync_with_stdio(false);
    ll n, k,l,r,q;
    cin>>n>>k>>q;
    vector<ll> likes(N,0);
    for(ll i=1; i<=n; i++){
        cin>>l>>r;
        likes[l]++;
        likes[r+1]--;
    }
    for(ll i=1; i<N; i++){
        likes[i] += likes[i-1];
        likes[i-1] = likes[i-1]>=k;
    }
 
    for(ll i=1; i<N; i++){
        likes[i] += likes[i-1];
    }
    while(q--){
        cin>>l>>r;
        cout<<likes[r]-likes[l-1]<<"\n";
    }
}

// #include<bits/stdc++.h>
// using namespace std;

// int N = 1e6+7;

// int main(){
//     int n,k,q,l,r;
//     cin>>n>>k>>q;
//     vector<int> arr(N,0);
//     for(int i=0;i<n;i++){
//         cin>>l>>r;
//         arr[l]++;
//         arr[r+1]--;
//     }
    
// 	for(int i=1;i<N;i++){
//         arr[i] += arr[i-1];
//         arr[i-1] = arr[i-1]>=k;
//     }
    
//     for(int i=1;i<N;i++){
//         arr[i]+=arr[i-1];
//     }
    
//     for(int i=0;i<q;i++){
//         cin>>l>>r;
//         cout<<arr[r]-arr[l-1]<<"\n";
//     }
//     return 0;
// }