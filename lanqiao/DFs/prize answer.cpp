#include <bits/stdc++.h>
using namespace std;
const int N=50;
int dp[N][N];//第i分答了j道
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
int main()
{
        cinquick();
        dp[0][1]=1;
        dp[1][1]=1;

        for(int j=2;j<=30;j++)
        {
           for(int i=0;i<=9;i++)
           {
                if(i==0)
                {
                   for(int k=0;k<=9;k++) dp[i][j]+=dp[k][j-1];     
                }
                else dp[i][j]+=dp[i-1][j-1];
           }
        }
        long long ans=0;
        for(int i=1;i<=30;i++){
                ans+=dp[7][i];
        }
        cout<<ans<<endl;
        return 0;
}