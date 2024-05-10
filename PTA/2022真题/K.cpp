#include <bits/stdc++.h>
using namespace std;
const int N=1e6;
int root;
vector<int> g[N];
int dis[N],vis[N],f[N];
int n,m;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}

void dfs(int u)
{
    for(auto j:g[u])
    {
        dis[j]=dis[u]+1;
        dfs(j);
    }
}
int main()
{
        cinquick();
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            int x;
            cin>>x;
            if(x==-1) root=i;
            else{
                g[x].push_back(i);
                f[i]=x;
            }
        }

        dfs(root);
        int maxn=0;
        int s=0;
        while(m--)
        {
            int u;
            cin>>u;
            
            maxn=max(maxn,dis[u]);

            while(u!=root&&!vis[u])
            {
                vis[u]=1;
                s+=2;
                u=f[u];
            }
            
            cout<<s-maxn<<endl;
        }
        return 0;
}