#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;
const int N=510,maxv=0x3f3f3f3f;
int e[N][N];
int n,m,w;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
bool floyd()
{
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
                if(e[i][j]>e[i][k]+e[k][j])//（用min会超时）
                    e[i][j]=e[i][k]+e[k][j];
            if(e[i][i]<0) return true;
        }
        
    }
    
    return false;
}
void solve()
{
    cin>>n>>m>>w;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i==j) e[i][j]=0;
            else e[i][j]=maxv;
    int a,b,c;
    for(int i=1;i<=m;i++)
    {
       
        cin>>a>>b>>c;

        if(e[a][b]>c){
            e[a][b]=c;
            e[b][a]=c;
        }
    }
    for(int i=1;i<=w;i++)
    {
        cin>>a>>b>>c;
        e[a][b]=-c;
    }
    if(floyd()) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
int main()
{
        cinquick();
        int t;
        cin>>t;
        while(t--) solve();
        return 0;
}