//dp[i]表示还剩下i行和i列的情况
//1.如果走到了第i行对角线的位置-->从dp[i-1]
//2.如果走到了不是第i行对角线的位置-->在（i，j）或者（j,i）放置 (i-1)*2*dp[i-2]
//其中j一定要小于i
#include <bits/stdc++.h>
using namespace std;
const int N=3*1e5+10,mod=1e9+7;
int n,k;
int dp[N];
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=k;i++){
        int x,y;
        cin>>x>>y;
        n-=(2-(x==y));
    }

   
    dp[0]=dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=(dp[i-1]+((long long)dp[i-2]*(i-1)*2)%mod)%mod;
    }
    cout<<dp[n]<<endl;
}
int main()
{
        cinquick();
        int t;
        cin>>t;
        while(t--) solve();
        return 0;
}