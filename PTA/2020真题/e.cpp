#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int e[N],ne[N],h[N],idx;
int st[510],dis[510];
int n,m,sum,sum1;
bool ok;
int st1,ed;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
int dfs(int u)
{
    
    st[u]=1;
    if(dis[u]) return dis[u];
    for(int i=h[u];i!=-1;i=ne[i]){
        int j=e[i];
            dis[u]+=dfs(j);
    }
    return dis[u];
}
int main()
{
        cinquick();
        cin>>n>>m;
        fill(h,h+N,-1);
        for(int i=1;i<=m;i++)
        {
            int x,y;
            cin>>x>>y;
            add(x,y);
        }
        
        cin>>st1>>ed;
        dis[ed]=1;
        sum=dfs(st1);
         cout<<sum<<' ';
         for(int i=1;i<=n;i++){
            if(st[i]&&!dis[i]){
                ok=true;
                break;
            }
         }
        if(ok) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;

        return 0;
}