#include <bits/stdc++.h>
using namespace std;
const int N=1010;
int cnt=1;
 int n,m;
int a[N][N],mp[N][N];
char q[N][N];
int ans[1000010];
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
void dfs(int i,int j)
{
       if(i<=0||j<=0||i>n||j>n) return ;
       if(mp[i][j]) return ;
       mp[i][j]=cnt;
       if(a[i][j]+a[i-1][j]==1){
              dfs(i-1,j);
       }
       if(a[i][j]+a[i+1][j]==1){
              dfs(i+1,j);
       }
       if(a[i][j]+a[i][j-1]==1){
              mp[i][j]=cnt;
              dfs(i,j-1);
       }
       if(a[i][j]+a[i][j+1]==1){
              dfs(i,j+1);
       }
       ans[cnt]++;
       
}
int main()
{
       cinquick();
       
      
       cin>>n>>m;
       for(int i=1;i<=n;i++)
       {
              cin>>q[i];
              for(int j=0;j<n;j++)
              {
                     a[i][j+1]=(q[i][j]-'0');
              }
       }

       

       while(m--)
       {
              int x,y;
              cin>>x>>y;
              if(!mp[x][y]) {
                     cnt++;
                     dfs(x,y);
              }
              cout<<ans[mp[x][y]]<<endl;
       }


       
       return 0;
}