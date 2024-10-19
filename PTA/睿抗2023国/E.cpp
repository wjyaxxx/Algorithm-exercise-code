//顺序无所谓
/*
    这个题能不能化成一个子问题？
    假设我们已经解决了子问题

    状态如何定义呢？
    dp[i][j].first 为数组中的最大空间数
    dp[i][j].second 为当前的空间数

*/
#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
typedef pair<int,int> PII;
int a,b,k;
const int N=1010,INF=0x3f3f3f3f;
PII dp[N][N];
int num1[N],num2[N];
//能够有前一个状态影响后一个状态就是dp
unordered_map<int,int> mp1;
void solve()
{
    cin>>a>>b>>k;
    for(int i=1;i<=a;i++) cin>>num1[i];
    for(int i=1;i<=b;i++) cin>>num2[i];

    memset(dp,0x3f,sizeof dp);
    mp1.clear();
    dp[0][1]=dp[1][0]={1,1};

    for(int i=1;i<=a;i++){
        mp1[num1[i]]++;
        unordered_map<int,int> mp2;
        for(int j=1;j<=b;j++){
            mp2[num2[j]]++;
            //dp[i][j-1]的转移
            int x= dp[i][j-1].first,y=dp[i][j-1].second;
            PII t1={INF,INF};
            //说明最大容量一定要加1
            if(x==y) t1.first=x+1;
            else t1.first=x;
            //考虑加入此数(j)后要删除
            ((mp1[num2[j]]+mp2[num2[j]])%k==0)? t1.second=y+1-k:t1.second=y+1;

            //dp[i-1][j]
            x= dp[i-1][j].first,y=dp[i-1][j].second;
            PII t2={INF,INF};
            //说明最大容量一定要加1
            if(x==y) t2.first=x+1;
            else t2.first=x;
            //考虑加入此数(j)后要删除
            ((mp1[num1[i]]+mp2[num1[i]])%k==0)? t2.second=y+1-k:t2.second=y+1;

            dp[i][j]=min(t1,t2);
        }
    }
    cout<<dp[a][b].first<<'\n';
}
int main()
{
    read_fast;
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}