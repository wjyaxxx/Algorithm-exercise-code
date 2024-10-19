#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
typedef long long ll;
void solve(){
    ll n;
    cin>>n;
    vector<ll> ans;
    ans.push_back(n);
    
    for(int i=0;i<=63;i++){
        if((n>>i)&1){
            ll x=~(1ll<<i);
            if(n&x)
            ans.push_back(n&x);
        }
    }
    cout<<ans.size()<<"\n";
    reverse(ans.begin(),ans.end());
    for(auto x:ans) cout<<x<<' ';
    cout<<"\n";
}
int main()
{
    read_fast;
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}