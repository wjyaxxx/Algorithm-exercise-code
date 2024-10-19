#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
typedef long long ll;
int main()
{
    read_fast
    int n;
    cin>>n;
    vector<ll> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];

    
    vector<array<ll,2>> dp(n+1);
    dp[1][0]=0,dp[1][1]=a[1];
    for(int i=2;i<=n;i++){
        dp[i][0]=max(dp[i-1][0],dp[i-1][1]+a[i]*2);
        dp[i][1]=max(dp[i-1][1],dp[i-1][0]+a[i]);
    }
    ll ans=0;
    ans=max(dp[n][0],dp[n][1]);
    cout<<ans<<"\n";
    return 0;
}