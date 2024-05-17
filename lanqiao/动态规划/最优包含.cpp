#include <bits/stdc++.h>
using namespace std;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
/*

    A B C D E A B C D
    X A A B Z 

    dp[i][j]表示S串中前i个字符,包含有T串中前j个字符最少需要修改的字符所形成的集合
            count

    1.当s[i]==t[j]时        
        dp[i][j]=min(dp[i-1][j-1],dp[i-1][j])
    2.当s[i]!=t[j]时 
        要么s前面包含了t[j],要么修改t[j]
        dp[i][j]=min(dp[i-1][j-1]+1,dp[i-1][j]);
*/
const int N=1100;
int dp[N][N];
string s,t;
int main()
{
        cinquick();
        cin>>s>>t;
        fill(dp[0],dp[0]+N*N,0x3f3f3f3f);
       
        for(int i=0;i<=s.size();i++) dp[i][0]=0;
        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=t.size();j++){
                if(s[i-1]==t[j-1])
                    dp[i][j]=min(dp[i-1][j-1],dp[i-1][j]);
                else{
                    dp[i][j]=min(dp[i-1][j-1]+1,dp[i-1][j]);
                }
            }
        }
        cout<<dp[s.size()][t.size()]<<endl;
        return 0;
}