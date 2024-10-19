#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const int N=200010;
typedef pair<int,int> PII;
vector<pair<int,int>> g[N];
int sum[N],ans[N];
//求出以某个节点为根的路劲之和
int dfs(int u,int f){
    
    int res=0;
    for(auto [v,w]:g[u]){
        if(v==f) continue;
        res+=dfs(v,u);//将w权值加入
        res+=w;
    }
    sum[u]=res;
    return res;
}
void solve()
{
    
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) g[i].clear();
    int u,v,x;
    for(int i=1;i<=n-1;i++){
        cin>>u>>v>>x;
        g[u].push_back({v,x});
        g[v].push_back({u,x});
    }

    dfs(1,-1);
    for(int i=1;i<=5;i++) cout<<sum[i]<<' ';
    cout<<"\n";
}
int main()
{
    read_fast;
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}