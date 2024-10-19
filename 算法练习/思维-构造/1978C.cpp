#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using ll=long long;
void solve(){
    ll n,k;
    cin>>n>>k;
    ll mx=0;
    for(int i=1,j=n;i<=n;i++,j--){
        mx+=abs(i-j);
    }
    if(k&1 || k>mx){
        cout<<"NO\n";
        return;
    }else{
        cout<<"YES\n";
        vector<ll> ans(n+1);
        for(int i=1;i<=n;i++) ans[i]=i;
        k/=2;
        int id=1;
        ll mac=n-1,last=n;
        while(k){
            if(k>=mac) swap(ans[id],ans[last]),k-=mac;
            else swap(ans[id],ans[id+k]),k=0;
            id++;
            mac-=2;
            last--;
        } 

        for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
        cout<<"\n";
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