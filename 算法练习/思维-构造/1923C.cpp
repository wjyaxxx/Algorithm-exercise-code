#include <bits/stdc++.h>
#define int long long
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> a(n+1);
    vector<int> s(n+1);
    vector<int> cnt(n+1);
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        cnt[i]=cnt[i-1];
        s[i]=s[i-1];
        if(a[i]==1) cnt[i]++;
        else s[i]+=a[i];
    }

    while(q--){
        int l,r;
        cin>>l>>r;
        if(l==r){
            cout<<"NO\n";
            continue;
        }
        int res=(s[r]-s[l-1])-(r-l+1);
        if(res>=0) cout<<"YES\n";
        else cout<<"NO\n";
    }

}
signed main()
{
    read_fast;
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}