#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const int N=5e5+10,mod=1e9+7;
using ll=long long;
ll pre[N],a[N],tt;
ll pres[N];
int q;
int main()
{
    read_fast
    cin>>q;
    int u,v;
    
    while(q--){
        cin>>u>>v;
        tt-=u;
        tt++;
        a[tt]=v;
        pre[tt]=pre[tt-1]+a[tt];
        pres[tt]=pres[tt-1]+pre[tt];
        for(int i=1;i<u;i++){
            a[tt+i]=0;
            pre[tt+i]=pre[tt+i-1]+a[tt+i];
            pres[tt+i]=pres[tt+i-1]+pre[tt+i];
        }
        ll ans=(tt*pre[tt]%mod+mod-pres[tt-1])%mod;
        cout<<ans<<"\n";
    }
    return 0;
}