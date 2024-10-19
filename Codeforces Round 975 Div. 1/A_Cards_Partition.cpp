#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using ll=long long;
void solve(){
    ll n,k;
    cin>>n>>k;

    vector<ll> a(n);
    ll s=0,maxv=0;
    for(int i=0;i<n;i++) cin>>a[i],s+=a[i],maxv=max(maxv,a[i]);
    for(int i=n;i>=1;i--){
        
    }
    
    
}
int main()
{
    read_fast;
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}