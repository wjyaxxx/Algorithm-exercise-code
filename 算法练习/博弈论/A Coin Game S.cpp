#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int dp[2005][2005];
int a[2005];
int last[2005];
int main()
{
    read_fast
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],a[i]+=a[i-1];

    for(int i=n;i;i--){
        for(int j=1;j<=n-i+1;j++){
            // int maxv=0;
            // for(int k=1;k<=min(j<<1,n-i-j+1);k++){
            //     maxv=max(maxv,dp[i+j][k]);
            // }
            dp[i][j]=a[n]-a[i-1]-dp[i+j][min(j<<1,n-i-j+1)];
            dp[i][j]=max(dp[i][j-1],dp[i][j]);
        }
    }
    cout<<max(dp[1][2],dp[1][1])<<"\n";
    return 0;
}