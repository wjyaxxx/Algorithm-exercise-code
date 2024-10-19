#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const int N=110;
int h[N<<1];
int dp[N<<1][N<<1];
int v[N<<1];
int n;
int main()
{
    read_fast
    cin>>n;
    for(int i=1;i<=n;i++) cin>>h[i],h[i+n]=h[i];
    
    for(int len=2;len<=n;len++){
        for(int l=1;l+len-1<=2*n;l++){
            int r=l+len-1;
            for(int k=l;k<r;k++){
                int v;
                if(r==2*n) v=h[1];
                else v=h[r+1];
                dp[l][r]=max(dp[l][r],dp[l][k]+dp[k+1][r]+h[l]*h[k+1]*v);
            }
        }
    }
    // for(int len=1;len<=n;len++){
    //     for(int l=1;l+len-1<=n*2;l++){
    //         int r=l+len-1;
    //         cout<<dp[l][r]<<' ';
    //     }
    //     cout<<"\n";
    // }
    int  ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,dp[i][n+i-1]);
    }
    cout<<ans<<"\n";
    return 0;
}