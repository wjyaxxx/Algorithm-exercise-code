#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using  ll=long long;
void solve(){
    int n;
    cin>>n;
    vector<int> k(n);
    for(int i=0;i<n;i++) cin>>k[i];
    ll l=1,r=5e10;
    auto check=[&](ll x)->bool{
        ll sum=x;
        for(int i=0;i<n-1;i++){
            ll s=(x+k[i])/k[i];
            sum-=s;
            if(sum<=0) return false;
        }
        return (sum*k[n-1])>x;
    };
    while(l<r){
        ll mid=(l+r)>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    if(check(l)){
         vector<ll> ans;
         ll sum=l;
        for(int i=0;i<n-1;i++){
            ll s=(l+k[i])/k[i];
            sum-=s; 
            ans.push_back(s);
        }
        ans.push_back(sum);
        for(auto x:ans) cout<<x<<' ';
        cout<<"\n";
    }
    else cout<<-1<<"\n";
}
int main()
{
    read_fast;
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}