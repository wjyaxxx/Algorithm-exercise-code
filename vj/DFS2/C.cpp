
#include <bits/stdc++.h>
using namespace std;
const int N=10;
int a[N][N];
bool vis[N][N];
int n,m,ans;
int sx,sy,fx,fy;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
int dx[5]={0,0,-1,1},dy[5]={1,-1,0,0};
void dfs(int x,int y)
{
    if(x==fx&&y==fy) {
        ans++;
        return ;
    }
    if(x<=0||y<=0||x>n||y>m||a[x][y]==1||vis[x][y]==true) return ;
    vis[x][y]=true;
    for(int i=0;i<4;i++){

        dfs(x+dx[i],y+dy[i]);
       
    }
    vis[x][y]=false;
}
int main()
{
        cinquick();
        cin>>n>>m;
        int t;
        cin>>t;
     
        cin>>sx>>sy>>fx>>fy;
        while(t--)
        {
            int x,y;
            cin>>x>>y;
            a[x][y]=1;
        }

        if(a[fx][fy]==1||a[sx][sy]==1)
        {
            cout<<0<<endl;
            return 0;
        }
        dfs(sx,sy);
        cout<<ans<<endl;
        return 0;
}