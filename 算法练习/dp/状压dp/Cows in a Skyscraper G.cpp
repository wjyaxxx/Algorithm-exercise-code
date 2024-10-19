#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int n,v;
int w[20];
int dp[1<<20],g[1<<20];
int main()
{
    read_fast
    cin>>n>>v;
    for(int i=1;i<=n;i++) cin>>w[i];

    memset(dp,0x3f,sizeof  dp);
    dp[0]=1;//至少有一个组
    g[0]=v;

    for(int i=0;i<(1<<n);i++){
        for(int j=1;j<=n;j++){
            if(i& (1<<(j-1))) continue;
            if(g[i]>=w[j]){
                if(dp[i | (1<<(j-1))]>=dp[i]){
                    dp[i | (1<<(j-1))]=dp[i];
                    g[i | (1<<(j-1))]=max(g[i | (1<<(j-1))],g[i]-w[j]);
                }
            }
            else{
                if(dp[i | (1<<(j-1))]>=dp[i]+1){
                    dp[i | (1<<(j-1))]=dp[i]+1;
                    g[i | (1<<(j-1))]=max(g[i| (1<<(j-1))],v-w[j]);
                }

            }
        }
    }

    cout<<dp[(1<<n)-1]<<"\n";
    return 0;
}