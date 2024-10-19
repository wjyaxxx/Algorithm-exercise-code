#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
void solve()
{
    int n;
    cin>>n;
    vector<int> val(n);
    int a,b;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        val[i]=((a==1)+(b==0));
    }
    //权值的排列
    vector<int> v(n);
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        x--;
        v[i]=val[x];
        
        
    }
    
    //cout<<"\n";
    // 找到最长下降子序列，最长下降子序列如何求解？动态规划可以求解，单调栈+二分
    // 动规解法,设f[i]以i元素结尾时的最长下降子序列的长度
    // vector<int> f(n);
    // f[0]=1;
    // int ans=1;
    // for(int i=1;i<n;i++){
        
    //     for(int j=0;j<i;j++)
    //         if(v[i]<=v[j]) f[i]=max(f[i],f[j]);
    //     f[i]++;
    //     ans=max(ans,f[i]);
    // }
    // cout<<n-ans<<"\n";

    //动规挂掉，贪心加二分去思考了
    //记f[i]为以长度为i的最长下降子序列的结尾元素的最大值
    // vector<int> f;
    
    // for(int i=0;i<n;i++){
    //     if(f.empty()||v[i]<=f.back()) f.push_back(v[i]);
    //     else{
    //         //否则我们就找到前面元素大于等于它的最后一个元素，即我们找到小于它的第一个元素
    //         int l=0,r=f.size()-1;
    //         while(l<r){
    //             int mid=l+r>>1;
    //             if(f[mid]<v[i]) r=mid;
    //             else l=mid+1;
    //         }
    //         f[r]=v[i];
    //     }
    // }
    // cout<<n-int(f.size())<<"\n";
    //优化动规，因为元素只有0 1 2三个值，那么怎么定义dp呢
    //dp[i][j]表示到第i个元素时最小元素为j的最长下降子序列的长度
    // vector<array<int,3>> dp(n);
    // dp[0][v[0]]=1;
    // for(int i=1;i<n;i++){
    //     for(int j=v[i];j<3;j++){
    //         dp[i][v[i]]=max(dp[i][v[i]],dp[i-1][j]);
    //     }
    //     dp[i][v[i]]++;
    //     for(int j=0;j<3;j++)
    //         if(j!=v[i]) dp[i][j]=dp[i-1][j];
    // }
    // int ans=0;
    // for(int i=0;i<3;i++) ans=max(ans,dp[n-1][i]);
    // cout<<n-ans<<'\n';
}
int main()
{
    read_fast;
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}