#include <bits/stdc++.h>
using namespace std;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
/*
    LCS变式
    dp[i][j] 表示在前i个字符所构成的序列中以j为结尾的序最长上升子序列的集合
             count

    状态计算 
    1.选第i个字符(str[i-1]==j)(j>k) dp[i][j]+=dp[i-1][k]

                自己单干 dp[i][j]=1

    2.不选第i个 dp[i][j]+=dp[i-1][j]
*/
const int N=210;
string str;
int dp[N];
int main()
{
        cinquick();
        cin>>str;
        
        int n=str.size();
        
        fill(dp,dp+1+n,1);

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(str[i]>str[j]) dp[i]+=dp[j];//将str[i]拼在str[j]的后面
                else if(str[i]==str[j]) dp[i]-=dp[j]; //后面一定包含前面
            }
        }
        
        int ans=0;
        for(int j=0;j<n;j++){
            ans+=dp[j];
        }
        cout<<ans<<endl;
        return 0;
}