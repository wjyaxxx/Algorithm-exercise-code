#include <bits/stdc++.h>
using namespace std;
#define int long long
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int n;
const int N=720,mod=1e9+7;
int cp[N];
char s[N];
int dp[N][N][3][3];
stack<int> sk;
void dfs(int l,int r){
    if(r==l+1){
        dp[l][r][0][1]=dp[l][r][0][2]=dp[l][r][1][0]=dp[l][r][2][0]=1;
        return ;
    }
    else if(cp[l]==r){
        dfs(l+1,r-1);

        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(j!=1) dp[l][r][0][1]=(dp[l][r][0][1]+dp[l+1][r-1][i][j])%mod;
                if(j!=2) dp[l][r][0][2]=(dp[l][r][0][2]+dp[l+1][r-1][i][j])%mod;
                if(i!=1) dp[l][r][1][0]=(dp[l][r][1][0]+dp[l+1][r-1][i][j])%mod;
                if(i!=2) dp[l][r][2][0]=(dp[l][r][2][0]+dp[l+1][r-1][i][j])%mod;

            }
        }
        return ;
    }else{
        dfs(l,cp[l]);
        dfs(cp[l]+1,r);
        for(int i=0;i<=2;i++)
            for(int j=0;j<=2;j++)
                for(int p=0;p<=2;p++)
                    for(int q=0;q<=2;q++){
                        if((j==1&&p==1)||(j==2&&p==2)) continue;
                        dp[l][r][i][q]=(dp[l][r][i][q]+dp[l][cp[l]][i][j]*dp[cp[l]+1][r][p][q]%mod)%mod;
                    }
        return ;
    }
    
}
signed main()
{
    //read_fast
    scanf("%s",s+1);
    n=strlen(s+1);
    for(int i=1;i<=n;i++){
        if(s[i]=='(') sk.push(i);
        else{
            cp[sk.top()]=i;
            cp[i]=sk.top();
            sk.pop();
        }
    }
    
    dfs(1,n);
    int ans=0;
    for(int i=0;i<=2;i++)
        for(int j=0;j<=2;j++)
            ans=(ans+dp[1][n][i][j])%mod;
    
    cout<<ans%mod<<"\n";

    return 0;
}