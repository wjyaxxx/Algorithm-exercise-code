#include <iostream>
using namespace std;
const int N=25;
char a[N][N];
int pre[N][N];
int n,m,ans;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
void dfs(int x,int y){

    if(x<=0||y<=0||x>m||y>n) return ;
    if(a[x][y]=='#') return ;
    if(pre[x][y]==-1) return ;

    pre[x][y]=-1;
    ans++;
    for(int i=0;i<4;i++) dfs(x+dx[i],y+dy[i]);

}
int main()
{
        cinquick();
        while(cin>>n>>m){
            if(n==0&&m==0) break;

            for(int i=1;i<=m;i++){
                for(int j=1;j<=n;j++){
                    cin>>a[i][j];
                    pre[i][j]=0;
                }
            }

            ans=0;
            bool ok=false;
            for(int i=1;i<=m;i++){
                for(int j=1;j<=n;j++){
                    if(a[i][j]=='@'){
                        ok=true;
                        dfs(i,j);
                        break;
                    }
                    if(ok==true) break; 
                }
            }
            cout<<ans<<endl;
            

        }
        

        return 0;
}

