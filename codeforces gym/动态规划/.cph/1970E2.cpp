#include <bits/stdc++.h>
using namespace std;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
typedef long long LL;
int n,m;
const int N=1e3+10,mod=1e9+7;
int A[N][N],low[N],sup[N],sum[N],v[N];
int tmp1[N];
int tmp2[N][N];
/*
    dp[i][j]表示第i天到达j号屋的路径总数
    dp[i][j]=sum(dp[i-1][0-m]*(之间的路径总数))

*/
void qpow1(int a[N],int b[N],int c[][N]) //a=b*c
{
    
    memset(tmp1,0,sizeof tmp1);
    for(int i=1;i<=m;i++)
        for(int j=1;j<=m;j++)
            tmp1[i]=(tmp1[i]+(LL)v[j]*A[j][i]%mod)%mod;

    memcpy(a,tmp1,sizeof tmp1);
}
void qpow2(int a[][N],int b[][N],int c[][N])
{
 
    memset(tmp2,0,sizeof tmp2);
    for(int i=1;i<=m;i++)
        for(int j=1;j<=m;j++)
            for(int k=1;k<=m;k++)
                tmp2[i][j]=(tmp2[i][j]+(LL)b[i][k]*c[k][j]%mod)%mod;
    
    memcpy(a,tmp2,sizeof tmp2);
}
int main()
{
        cinquick();
        cin>>m>>n;
        for(int i=1;i<=m;i++) cin>>low[i];
        for(int i=1;i<=m;i++) cin>>sup[i];
        for(int i=1;i<=m;i++) sum[i]=low[i]+sup[i];
        //计算A
        for(int i=1;i<=m;i++)
            for(int j=1;j<=m;j++)
                A[i][j]=((LL)sum[j]*sum[i]%mod-(LL)sup[j]*sup[i]%mod+mod)%mod;

        
       
       //初始V
        v[1]=1;
        while(n){
            if(n&1) qpow1(v,v,A);//f*A=f
            qpow2(A,A,A);
            n>>=1;
        }        
        int ans=0;
        for(int i=1;i<=m;i++)
            ans=(ans+v[i])%mod;
        cout<<ans<<endl;
        return 0;
}
/*
    将第k天所有小木屋i看成是一个向量
    将sum[j]*sum[k]-sup[j]*sup[k]看成是一个m*m的矩阵
    (𝐯𝑘+1)𝑖=∑(𝑡𝑖𝑡𝑗−𝑙𝑖𝑙𝑗)(𝐯𝑘)𝑗.
    改写为 1*m X m*m的矩阵乘法
    取v的整行取m*m的第j列得到
    A[j][k]表示sum[j]*sum[k]-sup[j]*sup[k]
    则新形成的v[j]=v[1]*A[1][j]+v[2]*A[2][j]+.....+v[m]*A[m][j]
            然后与dp方程等价
            v=v*A
            再用矩阵快速幂计算
*/