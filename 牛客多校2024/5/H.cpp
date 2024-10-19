#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const int N=45;
vector<int> g[N];
int vis[N],e[N];//访问到的值
int n,m;
int ans,res;
void dfs(int u,int step){
   vis[u]=1;
   bool ok=false;

    for(auto x:g[u]){
        //int x=g[u][i];
        if(vis[x] || e[x]) continue;
        ok=true;
        //就走x,删除其他的边，除了父亲外的点
        for(auto s:g[u]){
            //int s=g[u][j];
            if(vis[s] || s==x) continue;
            e[s]++;//删除这个点
        }
        dfs(x,step+1);
        //恢复现场
        for(auto s:g[u]){
            //int s=g[u][j];
            if(vis[s] || s==x ) continue;
            e[s]--;//删除这个点
        }
    }
    if(!ok) res=max(res,step+1);
    vis[u]=0;
    return ;
}
int main()
{
    read_fast
    cin>>n>>m;
    int u,v;
    for(int i=1;i<=m;i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i=1;i<=n;i++){
        res=0;
        fill(vis,vis+N,0);
        dfs(i,0);
        ans=max(ans,res);
    }
    cout<<ans<<"\n";
    return 0;
}