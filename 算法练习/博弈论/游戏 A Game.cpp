#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int a[210],s[210];
int dp[210][210];//表示先手在第i到j能够获得的最大利润
int dfs(int l,int r){
    if(dp[l][r]) return dp[l][r];
    if(l>r) return 0;
    if(l==r) return dp[l][r]=a[l];
    if(l<r){
        
        dp[l][r]=max(s[r]-s[l]-dfs(l+1,r)+a[l],s[r-1]-s[l-1]-dfs(l,r-1)+a[r]);
        return dp[l][r];
    }
}
int main()
{
    read_fast
    int n;
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++) cin>>a[i],s[i]=s[i-1]+a[i];
    
    dp[1][n]=dfs(1,n);
    
    cout<<dp[1][n]<<' '<<s[n]-dp[1][n]<<"\n";
   
    
    
    return 0;
} 
