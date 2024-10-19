#include <bits/stdc++.h>
#define int long long
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const int N=105,mod=998244353;
int dp[N][N][N];
signed main()
{
    //read_fast
    char s[105],t[105];

    scanf("%s %s",s+1,t+1);
    int ns=strlen(s+1),nt=strlen(t+1);
    //小规模的问题
    
    for(int i=0;i<=ns;i++)
        for(int j=0;j<=nt;j++)
            dp[i][j+1][j]=1;//与空串匹配
           
      
    for(int i=1;i<=ns;i++){
        for(int len=1;len<=nt;len++){
            for(int l=1;l+len-1<=nt;l++){
                int r=l+len-1;
                int &v=dp[i][l][r];
                for(int k=l-1;k<=r;k++){
                    v=(v+dp[i-1][l][k]*dp[i-1][k+1][r]%mod);
                    v%=mod;
                }

                for(int k=l;k<=r;k++){
                    if(s[i]==t[k]){
                        v=(v+dp[i-1][l][k-1]*dp[i-1][k+1][r]%mod);
                        v%=mod;
                    }
                }
            }
        }
    }
    
    cout<<dp[ns][1][nt];
    
    
    
    

    
    
    return 0;
}