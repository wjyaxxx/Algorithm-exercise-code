#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
void solve(){
    int n;
    cin>>n;
    vector<vector<char>> g(2,vector<char>(n));
    vector<vector<array<bool,2>>> st(2,vector<array<bool,2>>(n));
    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++) cin>>g[i][j];
    }
    int cnt=0;
    auto dfs=[&](auto self,int x,int y,int op)->bool{
        cnt++;
        if(x==1 && y==n-1) return true;
        if(st[x][y][op]) return false;
        st[x][y][op]=1;
        //cout<<x<<' '<<y<<" "<<cnt<<"\n";
        //if(cnt>=10) return false;
        if(!op){
            //这个点不具有抉择
            if(g[x][y]=='>'){
              
                return self(self,x,y+1,1);
                
            }else{
                
                return self(self,x,y-1,1);
            }
        }
        //这个点具有决策性
        bool ok=false;
        for(int i=0;i<4;i++){
            int nx=x+dx[i],ny=y+dy[i];
            //cout<<nx<<' '<<ny<<"\n"; 
            if(nx<0 || nx>=2 || ny<0 || ny>=n) continue;
            ok|=self(self,nx,ny,0);
            
        }
        return ok;
        
    };

    if(dfs(dfs,0,0,1)) cout<<"YES\n";
    else cout<<"NO\n";
}
int main()
{
    read_fast;
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}