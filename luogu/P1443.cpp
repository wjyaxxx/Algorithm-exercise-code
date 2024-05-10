#include <bits/stdc++.h>
using namespace std;
const int N=500;
bool st[N][N];
int step[N][N];
int res;
int n,m,x,y;
int dx[8]={-2,-2,2,2,1,-1,1,-1};
int dy[8]={-1,1,-1,1,2,-2,-2,2};
queue<pair<int,int>> q;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
void bfs()
{
    st[x][y]=true;
    step[x][y]=0;
    q.push({x,y});
    while(!q.empty())
    {
        pair<int,int> t=q.front();
        q.pop();
        int x1=t.first,y1=t.second;
        for(int i=0;i<8;i++)
        {
            int xx=x1+dx[i];
            int yy=y1+dy[i];
            if(xx>0&&yy>0&&xx<=n&&yy<=m&&!st[xx][yy]){
                st[xx][yy]=true;
                step[xx][yy]=step[x1][y1]+1;
                q.push({xx,yy});
            }
        }
    }

}
int main()
{
        cinquick();
        
        cin>>n>>m>>x>>y;
        bfs();
        for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
            if(st[i][j])
			printf("%-5d",step[i][j]);
            else printf("%-5d",-1);
		}
		printf("\n");
	}
        return 0;
}