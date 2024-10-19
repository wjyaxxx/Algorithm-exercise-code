#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=10000+10;
const int maxm=2000+10;
int n,m,p;
int x[maxn],y[maxn];   //i位置，上升x[i],下降y[i] 
int low[maxn],high[maxn];   //i位置能通过的范围是low[i]-high[i] 
int f[maxn][maxm];   //到(i,j)的最少点击次数 
bool e[maxn];    //e[i]表示i位置有没有管道 
int main() {
    scanf("%d%d%d",&n,&m,&p);
    for(int i=1; i<=n; ++i) scanf("%d%d",&x[i],&y[i]);
    for(int i=1; i<=n; ++i) {
        low[i]=1;
        high[i]=m;
    }
    int a,b,c;
    for(int i=1; i<=p; ++i) {
        scanf("%d%d%d",&a,&b,&c);
        e[a]=1;
        low[a]=b+1;
        high[a]=c-1;
    }
    memset(f,0x3f,sizeof(f));
    for(int i=1; i<=m; ++i) f[0][i]=0;
    for(int i=1; i<=n; ++i) {
        for(int j=x[i]+1; j<=m+x[i]; ++j)
            f[i][j]=min(f[i-1][j-x[i]]+1,f[i][j-x[i]]+1);
        for(int j=m+1; j<=m+x[i]; ++j)
            f[i][m]=min(f[i][m],f[i][j]);
        for(int j=1; j<=m-y[i]; ++j)
            f[i][j]=min(f[i][j],f[i-1][j+y[i]]);
        for(int j=1; j<low[i]; ++j)
            f[i][j]=f[0][0];   //不能通过(INF) 
        for(int j=high[i]+1; j<=m; ++j)
            f[i][j]=f[0][0];   //不能通过(INF)
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++)
            cout<<f[i][j]<<' ';
        cout<<"\n";
   }
    return 0;
}