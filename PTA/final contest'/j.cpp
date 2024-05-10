#include <bits/stdc++.h>
using namespace std;
int ans,res;
int n,m;
bool ok;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
void dfs(vector<vector<char>>&mp,int i,int j,int ans,vector<vector<bool>>&st)
{
    if(i<=0||i>n||j<=0||j>m) return ;
    if(mp[i][j]=='0'||st[i][j]) return ;
    st[i][j]=true;
    if(mp[i][j]>'1'&&!ok) {
        ok=true;
    }
    for(int d=0;d<4;d++)
    {
        int x=i+dx[d],y=j+dy[d];
        dfs(mp,x,y,ans,st);
    }
}
int main()
{
        cinquick();
        
        while(cin>>n>>m){
            ans=0,res=0;
        vector<vector<char>> mp(n+10,vector<char>(m+10));
        vector<vector<bool>> st(n+10,vector<bool>(m+10));
        for(int i=1;i<=n;i++) 
            for(int j=1;j<=m;j++)
                cin>>mp[i][j];

        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(mp[i][j]>'0'){
                    if(!st[i][j]){
                        ok=false;
                        dfs(mp,i,j,++ans,st);
                        if(ok) res++;
                    }
                }
        cout<<ans<<' '<<res<<endl;
        }
        return 0;
}