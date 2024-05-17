#include <bits/stdc++.h>
using namespace std;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
char q[100][100];
int dp[100][100];
int main()
{
        cinquick();
        for(int i=1;i<=30;i++) cin>>(q[i]+1);
        
        for(int i=1;i<=30;i++){
            
            for(int j=1;j<=60;j++){
                dp[i][j]=max(dp[i-1][j],dp[i][j-1])+(q[i][j]-'0');
            }
        }

        cout<<dp[30][60]<<endl;
        return 0;
}