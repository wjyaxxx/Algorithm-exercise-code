#include <bits/stdc++.h>
#define int long long
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    vector<int> s(n+1);
    vector<int> e(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]+a[i];
        e[i]=e[i-1];
        if(a[i]&1) e[i]++;
    }

    vector<int> ans(n+1);
    ans[1]=a[1];
    for(int i=2;i<=n;i++){
        int d=e[i]/3;
        int m=e[i]%3;
        if(m==1) d++;
        ans[i]=s[i]-d;
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
    cout<<"\n";
}
signed main()
{
    read_fast;
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}