#include <bits/stdc++.h>
using namespace std;
const int N=505;
 int n,m;
char a[N][N];
int pre[N][N];
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
void dfs(int x,int y){
    if(x<0||y<0||x>n+1||y>m+1||a[x][y]=='*'||pre[x][y]==1) return ;

    pre[x][y]=1;
    for(int i=0;i<4;i++) 
        dfs(x+dx[i],y+dy[i]);
}
int main()
{
        cinquick();
        
       
        cin>>n>>m;
      for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];

    for(int i=0;i<=n+1;i++){
        a[i][0]='0';
        a[i][m+1]='0';
    }
    for(int j=0;j<=m+1;j++){
        a[0][j]='0';
        a[n+1][j]='0';
    }

        dfs(0,0);
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(!pre[i][j]&&a[i][j]=='0') ans++;
            }
        }

         cout<<ans<<endl;
        return 0;
}