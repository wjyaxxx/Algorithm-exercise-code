#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int n,sx,sy,ex,ey;
const int N=305;
int vis[N][N],dis[N][N];
int dicx[]={2,2,1,1,-1,-1,-2,-2},dicy[]={-1,1,-2,2,-2,2,-1,1};
queue<pair<int,int>> q;
void solve()
{
    while(q.size()) q.pop();
    memset(vis,0,sizeof vis);
    memset(dis,0,sizeof dis);
    cin>>n;
    cin>>sx>>sy>>ex>>ey;
    vis[sx][sy]=1;
    vis[ex][ey]=2;
    q.push({sx,sy});
    q.push({ex,ey});
    int ans=0;
    bool ok=false;
    while(q.size()){
        auto t=q.front();
        q.pop();
        int x=t.first,y=t.second;
        for(int i=0;i<8;i++){
            int nx=x+dicx[i],ny=y+dicy[i];
            if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
            if(vis[x][y] && vis[nx][ny] && vis[x][y]!=vis[nx][ny]){
                ans=dis[x][y]+dis[nx][ny]+1;
                ok=true;
                break;
            }
            if(ok) break;
            if(!vis[nx][ny]){
                vis[nx][ny]=vis[x][y];
                dis[nx][ny]=dis[x][y]+1;
                q.push({nx,ny});
            }
        }
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