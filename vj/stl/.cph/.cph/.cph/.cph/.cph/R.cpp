#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
int dp[100010];//dp表示选到i时，凑出j元时，第i枚硬币的剩余数量
int a[100 + 16];
int c[100 + 16];
//朴素dp
//记录bool状态
//这个就不细做了
/*
    观察发现，bool只记录了每个硬币是否能被凑出来
    
    一定不能被凑出来的情况
    如果我想用第i枚硬币去凑j的话，肯定需要凑出j-a[i]，但是如果连j-a[i]都凑不出来，就不需要去枚举需要几枚k
    
    如果自己凑自己的话，只需要看看自身的硬币够不够

    换句话说，把k的状态放在了数组记录的值中，优化掉了

*/
int n,m;
void solve(int &n,int &m)
{
    memset(dp,-1,sizeof dp);
    dp[0]=0;
    
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(dp[j]>=0) dp[j]=c[i];
            else if(j<a[i]||dp[j-a[i]]<=0) dp[j]=-1;
            else dp[j]=dp[j-a[i]]-1;

        }
    }
    //答案为 
    int ans=0;
    for(int i=1;i<=m;i++){
        if(dp[i]>=0) ans++;

    }
    printf("%d\n",ans);
}
int main()
{
    while(scanf("%d%d",&n,&m)&&(n||m)){
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) scanf("%d",&c[i]);
        solve(n,m);
    }    
        
    return 0;
}
