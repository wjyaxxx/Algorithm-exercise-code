#include <bits/stdc++.h>
using namespace std;
const int N=400;
int mp[N][N],st[N][N],t[N][N];
int dx[5]={0,0,0,1,-1};
int dy[5]={0,1,-1,0,0};//方便移动和处理陨石砸落
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
void bfs()
{
    queue<pair<int,int>> q;
    q.push({0,0});
    st[0][0]=true;
     while(!q.empty())
    {
        int x=q.front().first,y=q.front().second;
        q.pop();
        for(int i=1;i<=4;i++)
        {
            int xx=x+dx[i],yy=y+dy[i];
            if(xx>=0&&yy>=0&&!st[xx][yy]&&(t[x][y]+1<mp[xx][yy]||mp[xx][yy]==-1))
            {
                
                st[xx][yy]=true;
                q.push({xx,yy});
                t[xx][yy]=t[x][y]+1;
                if(mp[xx][yy]==-1)
                {
                    cout<<t[xx][yy]<<endl;
                    return ;
                }
            }
        }
    }
    cout<<-1<<endl;
    return ;
}
int main()
{
        cinquick();
        int m;
        cin>>m;
        memset(mp,-1,sizeof mp);
        while(m--)
        {
            int x,y,t;
            cin>>x>>y>>t;
            for(int i=0;i<5;i++)
            {
                int xx=x+dx[i],yy=y+dy[i];
                if(xx>=0&&yy>=0&&(mp[xx][yy]==-1||mp[xx][yy]>t))
                    mp[xx][yy]=t;
            }
        }

        bfs();
        
        return 0;
}