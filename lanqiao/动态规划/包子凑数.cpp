#include <bits/stdc++.h>
using namespace std;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
/*
    当这n个数的gcd!=1时一定凑不出来

    每一个笼子可以选无数种（完全背包问题）
    
    思考大于什么的时候就一定能被凑出来

    当大于最小公倍数时就一定能被凑出来?
    设 x>=lcm(a1,a2,......,an)

    
*/
const int N=110,M=10010;
bool dp[N][M];
int a[N];
/*
    dp[i][j]表示能否用前i个物品凑出j来
    选i个 dp[i][j-a[i]](可重复)
    不选第i个 dp[i-1][j]

*/
int n;
int gcd(int a,int b)
{
    return b ? gcd(b, a % b) : a;
}
int main()
{
        cinquick();
        cin>>n;
        int gcdnum=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            gcdnum=gcd(gcdnum,a[i]);
        }
        if(gcdnum!=1) {
            cout<<"INF"<<endl;
            return  0;
        }

        for(int i=0;i<=n;i++)
            dp[i][0]=1;

        for(int i=1;i<=n;i++)
            for(int j=0;j<M;j++){
                dp[i][j]=dp[i-1][j];
                if(j-a[i]>=0) dp[i][j]|=dp[i][j-a[i]];
            }
        int cnt=0;
        for(int i=1;i<M;i++){
            if(!dp[n][i]){
               
                cnt++;
            }
        }
        cout<<cnt<<endl;
        return 0;
}