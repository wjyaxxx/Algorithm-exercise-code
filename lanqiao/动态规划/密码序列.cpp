#include <bits/stdc++.h>
using namespace std;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
/*
    //分析出来就是找到 在这个里面找到一个最长回文子序列

    回文就是求该字符串与它的反转字符串的公共子序列长度

    dp[i][j] 表示该字符串枚举到第i个字符，反转字符串枚举到第j个字符 的公共子序列的长度的集合
            属性就是 max

    选i个也选第j个 dp[i-1][j-1]+1 (s1[i]==s2[j])

    如果两者字符不相同(s1[i]!=s2[j])

    dp[i][j]=max(dp[i-1][j],dp[i][j-1])
    包含了选i不选j 选j不选i 两个都不选
    
*/
const int N=1100;
int dp[N][N];
string s1,s2;
int main()
{
        cinquick();
        cin>>s1;
        int n=s1.size();
        s2=s1;
        reverse(s2.begin(),s2.end());
        
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]) {
                    dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
                    
                }
                dp[i][j]=max(dp[i][j],max(dp[i-1][j],dp[i][j-1]));
            } 
        }
        
        cout<<n-dp[n][n];
        return 0;
}