#include <bits/stdc++.h>
#define int long long
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const int N=105,mod=998244353;
int cg[N][N];
int g[N][N];
int f[26][N][N];
int ans[N][N];
void mul(int a[N][N],int b[N][N],int c[N][N],int n){
    int tmp[N][N]={0};
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++){
            for(int k=0;k<=n;k++){
                tmp[i][j]=(tmp[i][j]+b[i][k]*c[k][j]%mod)%mod;
            }
        }

    memcpy(a,tmp,sizeof tmp);
}
void print(int a[N][N],int n){
    for(int i=0;i<=n;i++){
        for(int  j=0;j<=n;j++)
            cout<<a[i][j]<<' ';
        cout<<"\n";
    }
}
signed main()
{
    //read_fast
    char s[105],t[105];

    scanf("%s %s",s+1,t+1);
    int ns=strlen(s+1),nt=strlen(t+1);
    
    for(int i=0;i<26;i++)
        for(int j=0;j<=nt;j++)
            f[i][j][j]=1;
        
    
    //构造出了转移矩阵
    for(int i=1;i<=nt;i++){
        int idx=t[i]-'a';
        f[idx][i-1][i]=1;
    }
    
    for(int i=0;i<=nt;i++) g[i][i]=1;
    //print(f[0],nt);
    //转移
    for(int i=1;i<=ns;i++){
        memcpy(cg,g,sizeof g);
        mul(g,g,f[s[i]-'a'],nt);
        //print(g,nt);
        //cout<<"------------\n";
        mul(g,g,cg,nt);
        //print(g,nt);
    }
    
    ans[0][0]=1;
    mul(ans,ans,g,nt);
    cout<<ans[0][nt]<<"\n";
    return 0;
}