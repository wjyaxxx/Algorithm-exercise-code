#include <bits/stdc++.h>
using namespace std;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
const int N=2*1e5+10;

typedef long long LL;
void solve()
{
    LL n,m;
    cin>>n>>m;
    LL l=max(0ll,n-m),r=n+m;
    LL ans=0;
    int idx=-1;
    for(int i=32;i>=0;i--){
        if(((l>>i)&1)==((r>>i)&1)){
            ans|=(((l>>i)&1)?1<<i:0);
        }
        else{
            idx=i;
            break;
        }
    }

    for(int i=0;i<=idx;i++){
        ans|=(1ll<<i);
    }
    cout<<ans<<endl;
    
}
int main()
{
        cinquick();
        int t;
        cin>>t;
        while(t--) solve();
        return 0;
}