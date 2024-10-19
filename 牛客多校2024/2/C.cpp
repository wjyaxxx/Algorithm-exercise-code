#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n;
const int N=1e6+10;
char s[2][N];
int dp[2][N];//能达到(i,j)时走过的最大的R的数量
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};

void solve()
{
    cin>>n;
    cin>>(s[0]+1)>>(s[1]+1);
    
    

    for(int i=1;i<=n;i++){
        for(int j=0;j<2;j++){
            if(s[j][i]=='R') dp[j][i]=dp[j][i-1]+1;
            else dp[j][i]=0;
        }
        if(s[0][i]==s[1][i] && s[0][i]=='R')
        {
            int t=dp[0][i];
            dp[0][i]=max(dp[0][i],dp[1][i]+1);
            dp[1][i]=max(dp[1][i],t+1);
        }
    }
    int ans=0;
        for(int j=0;j<2;j++){
            for(int i=0;i<=n;i++){
                ans=max(ans,dp[j][i]);  
        }
    }
    cout<<max(0,ans-1)<<"\n";
    
}
int main()
{

    int t=1;
    //cin>>t;
    while(t--) solve();
    
    return 0;
}