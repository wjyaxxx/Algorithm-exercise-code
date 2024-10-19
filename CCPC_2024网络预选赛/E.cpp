#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
typedef long long LL;
LL ans,e;
LL mod=998244353;


int main()
{
    read_fast
    
    LL n,m;
    cin>>n>>m;
    auto qmi=[&](LL a,LL b,LL mod){
        LL res=1,base=a;
        while(b){
            if(b&1) res=res*base%mod;
            base=base*base%mod;
            b>>=1;
        }
        return res;
    };
   
    for(int i=0,res=1;i<=m;i++,res*=26){
        if(res>n) res=n;
        ans=(ans+res)%mod;
    }
    for(int i=0,res=1;i<=m;i++){
        LL x=qmi(26,i,mod);
        LL z=(1-qmi(x,mod-2,mod)+mod)%mod;
        LL s=(1-qmi(z,n,mod)+mod)%mod;
        LL w=s*qmi(26,i,mod)%mod;
        e=(e+w)%mod;
    }
    cout<<ans<<' '<<e<<"\n";
    return 0;
}