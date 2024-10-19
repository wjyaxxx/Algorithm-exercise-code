#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const int N=800*1000+10,inf=0x3f3f3f3f;
int dp[N];
int n;
struct node{
    int x,y;
}a[N];
int main()
{
    read_fast
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y;
    }

    memset(dp,-0x3f,sizeof dp);
    dp[400000]=0;
    for(int i=1;i<=n;i++){
        if(a[i].x>=0){
            for(int j=800000;j>=a[i].x;j--) dp[j]=max(dp[j],dp[j-a[i].x]+a[i].y);
        }
        else{
            for(int j=0;j-a[i].x<=800000;j++) dp[j]=max(dp[j],dp[j-a[i].x]+a[i].y);
        }
    }
    int ans=-0x3f3f3f3f;
    for(int j=400000;j<=800000;j++) 
        if(dp[j]>=0) ans=max(ans,dp[j]+j-400000);
    cout<<ans<<"\n";
    return 0;
}