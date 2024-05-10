#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m;
//char arr[N][N];
//bool st[N][N];
bool ok;
int a,b;

void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
bool check(int i,int j)
{
    return (i>=1&&i<=n&&j>=1&&j<=m);
}
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
void dfs(int i,int j,vector<vector<char>>&arr,vector<vector<bool>>&st)
{
    if(!check(i,j)) return ;
    if(st[i][j]||arr[i][j]=='0') return ;
    st[i][j]=true;
    if(arr[i][j]!='1') ok=true;
    for(int k=0;k<4;k++)
    {
        dfs(i+dx[k],j+dy[k],arr,st);
    }
}
int main()
{
        cinquick();
        cin>>n>>m;
        vector<vector<char>> arr(n+1,vector<char>(m+1));
        vector<vector<bool>> st(n+1,vector<bool>(m+1));
        for(int i=1;i<=n;i++) 
        {
            for(int j=1;j<=m;j++) cin>>arr[i][j];
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(arr[i][j]!='0'&&!st[i][j])
                {
                    a++;
                    ok=false;
                    dfs(i,j,arr,st);
                    if(ok) b++;
                }    
            }
        }
        cout<<a<<' '<<b<<endl;
        return 0;
}