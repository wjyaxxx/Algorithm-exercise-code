#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int n;
const int N=55;
int a[N],dp[N][N];//dp[i][j]表示在第i个切割点和第j个切割点构成的最小花费
//w[i][j]为i到j的长度
void solve(int len){
    cin>>n;
    memset(dp,0x3f,sizeof dp);
    for(int i=1;i<=n;i++) cin>>a[i];
    a[n+1]=len;
    //初始条件
    for(int i=1;i<=n+1;i++) dp[i-1][i]=0;
    
    for(int l=2;l<=n+1;l++)
        for(int i=0;i+l<=n+1;i++){
            int j=i+l;
            for(int k=i+1;k<j;k++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
            dp[i][j]+=a[j]-a[i];
        }
    printf("The minimum cutting is %d.\n",dp[0][n+1]);
}
int main()
{
    //read_fast
    int len;
    while(cin>>len && len){
        solve(len);
    }
    return 0;
}