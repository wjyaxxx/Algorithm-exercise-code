#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int main()
{
    read_fast
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<vector<int>> dp(n+1,vector<int>(m+1));
    int mod=1e6+7;
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            for(int k=0;k<=a[i]&& j>=k;k++){
                dp[i][j]=(dp[i][j]+dp[i-1][j-k])%mod;
            }
        }
    }
    cout<<dp[n][m]%mod<<"\n";
    
    return 0;
}