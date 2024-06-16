#include <bits/stdc++.h>
using namespace std;
const int K=1100,N=K,mod=998244353;
int c[27];
int k;
typedef long long LL;
LL dp[K];//选到第i个字母时,能凑出j个字符串的方案数量（选择性问题，就很dp，怪我往组合数学方向去思考）
LL com[K][K];
int main()
{
      
        ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
       //预处理组合数
       for(int i=0;i<K;i++){
          com[i][0]=1;
          for(int j=1;j<=i;j++)
               com[i][j]=(com[i-1][j-1]+com[i-1][j])%mod;
       }
       cin>>k;
       for(int i=1;i<=26;i++) cin>>c[i];
       
       dp[0]=1;

     //第i个字符选多少个
       for(int i=1;i<=26;i++){
          for(int j=k;j>=0;j--){
               for(int cn=1;cn<=c[i]&&j+cn<=k;cn++){
                    dp[j+cn]=(dp[j+cn]+dp[j]*com[j+cn][cn])%mod;
               }
          }
       }
       LL ans=0;
       for(int i=1;i<=k;i++) ans=(ans+dp[i])%mod;
          cout<<ans<<"\n";
        return 0;
}


