#include <bits/stdc++.h>
using namespace std;
const int N=110;
char a[N][N];
int n,m,ans;
int b[N][N];
int dx[3]={-1,0,1};
int dy[3]={-1,0,1};
void dfs(int x,int y,int ans)
{
    if(x<0||x>n||y<0||y>m) return ;
    
    b[x][y]=-1;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(i==1&&j==1) continue;
            int xx=x+dx[i];
            int yy=y+dy[j];
            
            if(a[xx][yy]=='@'&&b[xx][yy]!=-1)
            {
                b[xx][yy]=-1;
                dfs(xx,yy,ans);
            }
        }
    }
}
int main()
{

    while(cin>>n>>m){
        if(n==0&&m==0) break;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            b[i][j]=0;        
        }
    }
    ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]=='@'&&b[i][j]!=-1) dfs(i,j,ans++);
        }
        cout<<ans<<endl;
    }
    return 0;
}