#include <bits/stdc++.h>
using namespace std;
const int N=105;
char a[N][N];
int vis[N][N];
int n;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
int dit[8][2]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
char q[8]="yizhong";
int dfs(int i,int j,int u,int dit1,int dit2)
{
    if(u==7) return 1;
    if(i<=0||j<=0||i>n||j>n) return 0;
    if(a[i][j]!=q[u]) return 0;
    if(dit1==0&&dit2==0)
    {
        for(int k=0;k<7;k++)
        {
            int x=i+dit[k][0],y=j+dit[k][1];
            if(a[x][y]==q[u+1])
                if(dfs(x,y,u+1,dit[k][0],dit[k][1]))
                    vis[i][j]=1;
        }
    }
    if(dfs(i+dit1,j+dit2,u+1,dit1,dit2)) vis[i][j]=1;
}
int main()
{
        cinquick();
       
        cin>>n;
       fill(a[0],a[0]+N*N,0);
       fill(vis[0],vis[0]+N*N,0);
        for(int i=1;i<=n;i++) cin>>a[i]+1;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
            {
                dfs(i,j,0,0,0);
            }
        }

       for(int i=1;i<=n;i++)
       {
            for(int j=1;j<=n;j++)
            {
                if(!vis[i][j]) cout<<'*';
                else cout<<a[i][j];
            }
            cout<<endl;
       }
        return 0;
}