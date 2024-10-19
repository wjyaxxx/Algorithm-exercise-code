#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using ll=long long;
void solve(){
    int n;
    cin>>n;
    vector<int> l(n),r(n),c(n);
    vector<int> p(n);
    for(int i=0;i<n;i++) cin>>l[i];
    for(int i=0;i<n;i++) cin>>r[i];
    for(int i=0;i<n;i++) cin>>c[i];
    sort(l.begin(),l.end());
    sort(r.begin(),r.end());
    sort(c.begin(),c.end(),greater<int>());
    set<int> s;//中记录的是l值
    for(int i=0;i<n;i++) s.insert(r[i]);
    for(int i=n-1;i>=0;i--){
        int x=*s.upper_bound(l[i]);
        p[i]=x-l[i];
        s.erase(x);
    }
    //区间长度不一定
    sort(p.begin(),p.end());
    ll ans=0;
    for(int i=0;i<n;i++){
        ans+=(ll)p[i]*c[i];
    }
    cout<<ans<<"\n";
}   
int main()
{
    read_fast;
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}