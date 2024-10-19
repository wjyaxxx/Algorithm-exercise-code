#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int main()
{
    read_fast
    int n;
    cin>>n;
    vector<array<int,2>> a(n+1);
    int l,r;
    for(int i=1;i<=n;i++){
        cin>>l>>r;
        a[i]={l,r};
    }
    vector<array<int,2>> dp(n+1);//dp[i][0]表示在左端点

    dp[1][0] = a[1][1] + a[1][1] - a[1][0] - 1;
    dp[1][1] = a[1][1] - 1;
    for(int i=2;i<=n;i++){
        int len=a[i][1]-a[i][0];
        dp[i][0]=min(dp[i-1][0]+abs(a[i-1][0]-a[i][1])+len,dp[i-1][1]+abs(a[i-1][1]-a[i][1])+len)+1;
        dp[i][1]=min(dp[i-1][0]+abs(a[i][0]-a[i-1][0])+len,dp[i-1][1]+abs(a[i-1][1]-a[i][0])+len)+1;
    }
    int ans=min(dp[n][0]+abs(n-a[n][0]),dp[n][1]+abs(n-a[n][1]));
    cout<<ans<<"\n";
    return 0;
}