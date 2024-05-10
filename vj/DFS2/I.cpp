#include <bits/stdc++.h>
using namespace std;
const int N=100;
int n,m;
int h[N],ne[N],st[N],idx;
int ans,sum;
struct point
{
    int p;
    int w;
}e[N];

void add(int a,int b,int d)
{
    e[idx].w=d,e[idx].p=b,ne[idx]=h[a],h[a]=idx++;
}
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
void dfs(int u,int sum)//以该节点出发走过路径的距离
{
    for(int i=h[u];i!=-1;i=ne[i])
    {
        int j=e[i].p;
        if(!st[j])
        {
            st[j]=true;
            sum+=e[i].w;
            dfs(j,sum);
            st[j]=false;
            sum-=e[i].w;
        }
    }
    ans=max(sum,ans);
}
int main()
{
        cinquick();
       
        cin>>n>>m;
        memset(h,-1,sizeof h);
        for(int i=1;i<=m;i++)
        {
            int a,b,d;
            cin>>a>>b>>d;
            add(a,b,d);
            add(b,a,d);
        }
        for(int i=1;i<=n;i++)
        {
            fill(st,st+n+1,0);
            st[i]=true;
            dfs(i,0);
        }
        cout<<ans<<endl;
        return 0;
}