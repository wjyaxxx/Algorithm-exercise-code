#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const int N=2*1e5+10,mod=998244353;
int dp[N][55<<1];
int to[55<<1];
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    if(!m){
        cout<<1<<"\n";
        return ;
    }
    vector<pair<int,int>> g[n+1];
    vector<int> p;
    map<int,int> mp;
    p.emplace_back(1);
    auto dis=[&](int u,int v)->int{
        return (v-u+n)%n;
    };
    int u,v;
    for(int i=1;i<=m;i++){
        cin>>u>>v;
        g[u].push_back({v,1});
        p.emplace_back(u);
        p.emplace_back(v);        
    }
    sort(p.begin(),p.end());
    p.erase(unique(p.begin(),p.end()), p.end());
    
    int ns=p.size();
    for(int i=0;i<ns-1;i++){
        mp[p[i]]=i;
        int dist=dis(p[i],p[i+1]);
        g[p[i]].push_back({p[i+1],dist});
        to[i]=dis(p[i],p[i+1]);
    }
    mp[p[ns-1]]=ns-1;
    //最后一个点
    g[p[ns-1]].push_back({p[0],dis(p[ns-1],p[0])});
    //cout<<p[0]<<' '<<p[ns-1]<<' '<<dis(p[ns-1],p[0])<<"\n";
    to[ns-1]=dis(p[ns-1],p[0]);
    


    dp[0][0]=1;
    for(int i=0;i<=k;i++){
        for(int j=0;j<ns;j++){
            int u=p[j];
            for(auto x:g[u]){
                int v=x.first,dist=x.second;
                if(i+dist<=k) 
                    dp[i+dist][mp[v]]=(dp[i][j]+dp[i+dist][mp[v]])%mod;
            }
        }
    }

    int ans=0;
    for(int i=0;i<ns;i++){
        for(int j=k-to[i]+1;j<=k;j++){
            //cout<<"p[i]="<<p[i]<<' '<<"j="<<j<<' '<<"dp[j][i]="<<dp[j][i]<<"\n";
            ans=(ans+dp[j][i])%mod;
        }
    }
    cout<<ans<<"\n";

}

int main()
{
    read_fast;
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}