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
int dp[N][N],low[N],sup[N],sum[N];
/*
    dp[i][j]表示第i天到达j号屋的路径总数
    
    dp[i][j]=sum(dp[i-1][0-m]*(之间的路径总数))

*/
int main()
{
        cinquick();
        cin>>m>>n;
        for(int i=1;i<=m;i++) cin>>low[i];
        for(int i=1;i<=m;i++) cin>>sup[i];
        for(int i=1;i<=m;i++) sum[i]=low[i]+sup[i];

        //初始化
        dp[0][1]=1;
        for(int i=1;i<=n;i++){
            //从k到j
            for(int j=1;j<=m;j++){
                for(int k=1;k<=m;k++){
                    dp[i][j]=(dp[i][j]+((LL)dp[i-1][k]*((LL)sum[j]*sum[k]%mod-(LL)sup[j]*sup[k]%mod+mod)%mod)%mod)%mod;//组合数学，反面就是
                }
            }
        }
        int ans=0;
        for(int i=1;i<=m;i++) ans=(ans+dp[n][i])%mod;
        cout<<ans<<endl;
        return 0;
}
/*

[           ]
            
[           ]





*/