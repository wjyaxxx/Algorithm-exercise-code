#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
typedef long long ll;
const ll mod=998244353;
ll p1,p2;
ll qpow(ll a,ll k){
    ll res=1,base=a;
    
    while(k){
        if(k&1) res=(res*base)%mod;
        
        base=(base*base)%mod;
        k>>=1;    
    }
    return res;
}
ll add_mod(ll a,ll b){
    return ((a%mod)+(b%mod))%mod;
}
ll sub_mod(ll a,ll b){
    return add_mod(a,mod-b%mod);
}
ll dfs(ll a,ll b,ll p){
    
    if(!a) return 0;
    if(!b) return p;
    
    if(a>b){
        //有一场赢了，就赢了
        ll k=a/b;
        ll cur=qpow(p2,k);
        ll res=sub_mod(1ll,cur)*p%mod;
        res=add_mod(res,dfs(a%b,b,cur*p%mod));
        return res;
    }else{
        ll k=b/a;
        ll cur=qpow(p1,k);
        return dfs(a,b%a,p*cur%mod);
    }
}
void solve(){
    ll x,y;
    cin>>x>>y;
    ll a,b,c;
    cin>>a>>b>>c;
    c=a+b;
    ll invc=qpow(c,mod-2);
    
     p1=invc*a%mod;
     p2=invc*b%mod;
    ll ans=dfs(x,y,1ll);
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