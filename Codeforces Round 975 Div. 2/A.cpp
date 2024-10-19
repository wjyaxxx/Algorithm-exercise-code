#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using vi=vector<int>;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    
    for(int i=0;i<n;i++) cin>>a[i];
    vector<vi> dp(n,vi(n+1));
    if(n==1){
        cout<<a[0]+1<<"\n";
        return;
    }
    dp[0][1]=a[0];
    dp[1][1]=max(a[0],a[1]);
    for(int i=2;i<n;i++){
        for(int j=1;j<=i+1;j++){
            if(dp[i-1][j])
            dp[i][j]=max(dp[i-1][j],dp[i][j]);
            if(j>=2 && dp[i-2][j-1]) dp[i][j]=max(dp[i][j],max(dp[i-2][j-1],a[i]));
        }
    }
    
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<=maxv;j++){
    //         cout<<dp[i][j]<<' ';

    //     }
    //     cout<<"\n";
    // }
    
    int ans=0;
    for(int j=1;j<=n;j++){
        if(dp[n-1][j])
        ans=max(ans,dp[n-1][j]+j);
    }
    cout<<ans<<"\n";
}
int main()
{
    read_fast;
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}