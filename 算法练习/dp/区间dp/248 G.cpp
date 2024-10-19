#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int dp[250][250]; 
int main()
{
    read_fast
    int n;
    cin>>n;
        
    for(int i=1;i<=n;i++) cin>>dp[i][i];
    int ans=0;
    for(int len=2;len<=n;len++){
        for(int l=1;l+len-1<=n;l++){
            int r=l+len-1;
            for(int k=l;k<r;k++){
                if(dp[l][k] && dp[l][k]==dp[k+1][r]) dp[l][r]=max(dp[l][r],dp[l][k]+1);
                
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++)
            ans=max(ans,dp[i][j]);
    }
    
    cout<<ans<<"\n";
    
    return 0;
}