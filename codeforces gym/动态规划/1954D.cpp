#include <bits/stdc++.h>
using namespace std;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
typedef long long LL;
const int N=5010,mod=998244353;
int a[N];
int n,sum;
LL ans;

/*
    假设第i组中有k个颜色,数量分别为a1,a2,a3,a4....ak
        ans+=min(sum(ai)/2,max(a1:ak));
    
    注意到答案的贡献大部分都与球的总数有关(题目中给出的信息)
    枚举球的总数，在枚举在j的条件下,前n个球选择的方案数(01背包问题)
        dp[i][j]表示在用i个颜色，能凑出j个球的方案数
        dp[i][j]=dp[i-1][j]+dp[i-1][j-a[i]]
    解决完方案数后就可以计算答案贡献了
    遍历第i个元素
        ans+=dp[i][sum(a[1:i])]*K
        当其中遍历前i个数时出现了某个数比sum/2大，该数就是众数，则可以将该数排序

*/
//麻烦版本
void solve()
{
   vector<vector<LL>> dp(N,vector<LL>(N));
    //for(int i=0;i<N;i++) dp[0][i]=1;
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=sum;j++){
            dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
            if(j-a[i]>=0) dp[i][j]=(dp[i][j]+dp[i-1][j-a[i]])%mod;
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            cout<<dp[i][j]<<' ';
        }
        cout<<endl;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<N;j++){
            ans=(ans+dp[i-1][j]*max((j+a[i]+1)/2,a[i]))%mod;
        }
    }
     cout<<ans<<endl;
}
// void solve()
// {
//     vector<vector<LL>> dp(N,vector<LL>(N));
//     dp[0][0]=1;
// 	for(int i=1;i<=n;i++){
// 		for(int j=0;j<=5000;j++)ans=(ans+dp[i-1][j]*max((j+a[i]+1)/2,a[i]))%mod;
// 		for(int j=0;j<=5000;j++)dp[i][j]=(dp[i-1][j]+((j>=a[i])?dp[i-1][j-a[i]]:0))%mod;
// 	}
//     cout<<ans<<endl;
// }
int main()
{
        cinquick();
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i],sum+=a[i];
        sort(a+1,a+1+n);
        solve();
        return 0;
}