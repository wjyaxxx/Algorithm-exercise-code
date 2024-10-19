#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const int N=105;
int g[N][N];
int  n;
int dis[N];//其他点到最小生成树的距离
int vis[N];//该点是否在最小生成树中
struct S {
  int u, d;
};

bool operator<(const S &x, const S &y) { return x.d > y.d; }

priority_queue<S> q;
int main()
{
    read_fast
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>g[i][j];

    //prime算法
    memset(dis,0x3f,sizeof dis);
    dis[1]=0;
    
    q.push({1,dis[1]});
    int ans=0;
    while(q.size()){
       auto u=q.top().u,d=q.top().d;
       q.pop();
       if(vis[u]) continue;
        vis[u]=1;
        ans+=d;
        for(int i=1;i<=n;i++)
            if(i!=u){
                if(dis[i]>g[u][i]){
                    q.push({i,g[u][i]});
                }
            }
    }
    cout<<ans<<"\n";
    return 0
}
