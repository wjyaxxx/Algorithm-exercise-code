#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const int N=55,M=N<<1,finf=-0x3f3f3f3f,inf=0x3f3f3f3f;
char op[M][M];
int v[M];
int f[M][M],g[M][M];//f维护最大值，g维护最小值
int n;
int main()
{
    read_fast
    cin>>n;
    for(int i=1;i<=n;i++){
        if(i==1) cin>>op[n][n+1];
        else cin>>op[i-1][i];
        cin>>v[i];
    }
    
    for(int i=n+1;i<(n<<1);i++){
        v[i]=v[i-n];
        op[i][i+1]=op[i-n][i+1-n];
    }
    
    //区间dp了
    int m=(n<<1);
    fill(f[0],f[0]+M*M,finf);
    fill(g[0],g[0]+M*M,inf);
    for(int i=1;i<=m;i++) f[i][i]=g[i][i]=v[i];
    for(int len=2;len<=m;len++)
        for(int i=1;i+len-1<=m;i++){
            int j=i+len-1;
            for(int k=i;k<j;k++){
                if(op[k][k+1]=='x'){
                    f[i][j]=max(f[i][j],max(f[i][k]*f[k+1][j],max(g[i][k]*g[k+1][j],max(f[i][k]*g[k+1][j],g[i][k]*f[k+1][j]))));
                    g[i][j]=min(g[i][j],min(f[i][k]*f[k+1][j],min(g[i][k]*g[k+1][j],min(f[i][k]*g[k+1][j],g[i][k]*f[k+1][j]))));
                }
                else if(op[k][k+1]=='t'){
                    f[i][j]=max(f[i][j],f[i][k]+f[k+1][j]);
                    g[i][j]=min(g[i][j],g[i][k]+g[k+1][j]);
                }
            }
        }
    int ans=INT_MIN;
    for(int i=1;i<=n;i++) ans=max(ans,f[i][i+n-1]);
    cout<<ans<<"\n";
    for(int i=1;i<=n;i++)
        if(ans==f[i][i+n-1])
            cout<<i<<' ';
    return 0;
}