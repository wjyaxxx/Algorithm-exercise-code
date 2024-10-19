#include <bits/stdc++.h>
using namespace std;
const int N=40010;
vector<int> g[N];
int dt[N],df[N],dn[N],v[N];
bool vis[N];
int  te,fe,s;
int n,m,t,f;
typedef long long LL;
LL ans=0x3f3f3f3f3f3f3f3f;
void bfs(int u,int dis[]){
    memset(vis,0,sizeof vis);
    queue<int> q;
    q.push(u);
    vis[u]=true;
    dis[u]=0;
    while(!q.empty()){
        int t=q.front();
        q.pop();
        v[t]++;
        for(auto x:g[t]){
            if(!vis[x]){
                q.push(x);
                dis[x]=dis[t]+1;
                vis[x]=true;
            }            
        }
    }
}
int main()
{
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>te>>fe>>s;
        cin>>t>>f>>n>>m;
        s=te+fe-s;
        int u,v1;
        for(int i=1;i<=m;i++){
            cin>>u>>v1;
            g[u].push_back(v1);
            g[v1].push_back(u);
        }
        
        bfs(n,dn);
        if(!vis[t]||!vis[f]) {
            cout<<"-1"<<endl;
            return 0;
        }

        bfs(t,dt);
        bfs(f,df);

        for(int i=1;i<=n;i++){
            if(v[i]){
                ans=min(ans,(LL)dt[i]*te+(LL)df[i]*fe+(LL)dn[i]*s);
            }
        }
        cout<<ans<<endl;
        return 0;
}