#include <bits/stdc++.h>
using namespace std;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
/*

        dp[i][j]表示在前i个序列中，替换j次能形成的最小值
                而且会发现本题数据量巨小        
        对于第i个数来说
        1.不被替换 dp[i-1][j]
        2.被替换 被哪一个所替换呢？
        会发现对i替换k相当于 [i-k+1:i]全部被替换为最小值
        4 1 
        当到一时
        会被替换为 1 1
*/
typedef long long LL;
int n,k;
int ans;
LL inf=0x3f3f3f3f3f3f3f3f;
void solve()
{
   cin>>n>>k;
    vector<vector<LL>> dp(n+1,vector<LL>(k+1,inf));
    vector<LL> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=0;i<=k;i++) dp[0][i]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            dp[i][j]=min(dp[i][j],dp[i-1][j]+a[i]);
            LL mn=a[i];
            for(int m=1;m<=j&&i-m>=1;m++){
                mn=min(mn,a[i-m]);
                dp[i][j]=min(dp[i][j],dp[i-m-1][j-m]+mn*(m+1));
            }    
        }
    }
//     for(int i=0;i<=n;i++){
//         for(int j=0;j<=k;j++){
//              cout<<dp[i][j]<<' ';
//         }
//         cout<<endl;
//     }
//     cout<<"debug--------"<<endl;
    cout<<dp[n][k]<<endl;
}  
int main()
{
        cinquick();
        int t;
        cin>>t;
        while(t--) solve();
        return 0;
}