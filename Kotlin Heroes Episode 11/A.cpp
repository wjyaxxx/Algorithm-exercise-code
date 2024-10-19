#include <bits/stdc++.h>
#define int long long
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int fact[1000],sz;
void solve(){
    int n,k;
    cin>>n>>k;
    if(n<k || k==1) cout<<n<<"\n";
    else{
        sz=0;
        for(int i=1;i<=1e9;i*=k) fact[sz++]=i;
        int cnt=0;
        for(int i=sz-1;i>=0;i--){
            cnt+=(n/fact[i]);
            n%=fact[i];
        }
        cout<<cnt<<"\n";
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