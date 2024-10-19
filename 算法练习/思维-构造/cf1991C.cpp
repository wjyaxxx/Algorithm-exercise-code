#include <bits/stdc++.h>
#define int long long
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int cnt=0;
    for(int i=0;i<n;i++){
        cnt+=(a[i]&1);
    }
    if(cnt!=0 && cnt!=n){
        cout<<-1<<"\n";
        return;
    }
    vector<int> ans;
    for(int i=29;i>=0;i--){
        int x=(1<<i);
        ans.push_back(x);
        bool ok=false;
        for(int j=0;j<n;j++){
            a[j]=abs(a[j]-x);
            if(a[j]!=0) ok=true;
        }
        if(!ok) break;
        
    }
    if(a[0]==1) ans.push_back(1);
    cout<<ans.size()<<"\n";
    for(auto&x :ans) cout<<x<<' ';
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