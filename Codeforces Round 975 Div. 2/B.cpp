#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
typedef long long ll;
void solve(){
    int n,q;
    cin>>n>>q;
    vector<ll> x(n);
    for(int i=0;i<n;i++) cin>>x[i];
    unordered_map<ll,ll> mp;
    ll s=n-1;
    for(int i=1;i<n;i++){
        ll cnt=x[i]-x[i-1]-1;
        if(cnt) mp[s*i]+=cnt;
        s--;
    }
    s=n-1;
    ll z=0;
    for(int i=0;i<n;i++){
        mp[s*(i+1)+z]++;
        s--;
        z++;
    }
    ll id;
    while(q--){
        cin>>id;
        auto it=mp.find(id);
        if(it!=mp.end()) cout<<mp[id]<<" ";
        else cout<<0<<' ';
    }
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