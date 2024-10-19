#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    int g=0;
    for(int i=0;i<n;i++) cin>>a[i],g=__gcd(g,a[i]);

    int ans=0,cur=0;
    for(int i=1;i<=n;i++){
        int mn=1e9;
        for(int j=0;j<n;j++) mn=min(mn,__gcd(a[j],cur));
        cur=mn;
        ans+=cur;
        if(cur==g){
            ans+=(n-i)*g;
            break;
        }
    }
    cout<<ans<<"\n";
}
signed main()
{
    read_fast;
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}