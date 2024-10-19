#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using vi=vector<int>;
void solve(){
    int n;
    cin>>n;
    vector<int> g[n+1];
    int u,v;
    for(int i=1;i<n;i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> deep(n+1);
    vector<int> md(n+1);    
    vector<int> cntd(n+1);
    vector<int> mcntd(n+1);
    int maxd=0;
    auto dfs=[&g,&deep,&cntd,&mcntd,&md,&maxd](auto self,int u,int f)->void{
        md[u]=deep[u];
        for(auto x:g[u]){
            if(x==f) continue;
            deep[x]=deep[u]+1;
            self(self,x,u);
            md[u]=max(md[u],md[x]);
        }
        cntd[deep[u]]++;
        mcntd[md[u]]++;
    };
    dfs(dfs,1,-1);
    
    for(int i=md[1];i;i--){
        cntd[i-1]+=cntd[i];
    }
   
    for(int i=1;i<=md[1];i++){
        mcntd[i]+=mcntd[i-1];
    }
    

    int ans=1e9;
    
    for(int d=1;d<=md[1];d++){
        //需要删除的点数
        int res=cntd[d+1]+mcntd[d-1];
        ans=min(ans,res);
    }
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