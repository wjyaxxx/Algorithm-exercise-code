#include <bits/stdc++.h>
using namespace std;
const int  mod=1e9+7,N=1e5+10;
typedef long long LL;
LL dp[33][N],s[N],a[N];
int n;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
void solve()
{
    //a^b>b^0
    //对于一个a来说我们只需要做到 将b二进制中为0的改变为1就可以影响b
    //换个思路想
    //枚举每个a  1 0 0 1  1 1 0 0 1
    //去思考下
    //只需要考虑a的最高位的1就ok
    //对于一个b来说 改变b的只有a中1的位置
    // 假设b中与a的最高位1对应的位置被改变  想要变大 则b中与a的最高位1对应的位置必须为0
    //找到s[z]^s[x-1] 使得与a对应的最高位的1为0

    //对于ai来说 设最高位是1的位是第k位
    // 对于第k位来说 s[z]和s[x-1] 为0 0 或者 1 1
    //在 1-i中找到 s[x-1]为0 在 i-n中s[z] 为0
    //或者 在 1-i中找到 s[x-1]为1 在 i-n中s[z] 为1

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]^a[i];
        for(int j=0;j<=32;j++){
            dp[j][i]=dp[j][i-1]+(s[i]>>j&1);
        }
    }

    LL ans=0;
    for(int i=1;i<=n;i++){
        int k=32;
        while((a[i]>>k&1)==0&&k>=0) k--;
        if(k==-1) continue;//a为0

        ans+=(dp[k][n]-dp[k][i-1])*dp[k][i-1];//全为1
        ans+=(n-i+1-(dp[k][n]-dp[k][i-1]))*(i-dp[k][i-1]);//全为0
    }
    cout<<ans<<endl;
}
int main()
{
        cinquick();
        int t;
        cin>>t;
        while(t--) solve();
        return 0;
}