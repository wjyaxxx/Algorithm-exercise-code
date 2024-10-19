#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int n,m;
const int N=2*1e7+10,INF=0x3f3f3f3f;
char news[N];
int z[N];
int dp[N],q[N];
int hh,tt=-1;
int main()
{
    //read_fast
    cin>>n>>m;
    //举一反三
    scanf("%s",news);
    news[n]='#';
    scanf("%s",news+n+1);
    
    int sz = strlen(news);
    
    for (int i = 1, l = 0, r = 0; i < sz; ++i) {
        if (i <= r && z[i - l] < r - i + 1) {
        z[i] = z[i - l];
        } else {
        z[i] = max(0, r - i + 1);
        while (i + z[i] < sz && news[z[i]] == news[i + z[i]]) ++z[i];
        }
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    for(int i=1,j=0;i<=m;++i) j>i+z[i+n]?z[i+n]=INF:j=i+z[i+n];
    //for(int i=1;i<=m;i++) cerr<<z[i+n]<<" ";    
    //单调队列优化
    fill(dp,dp+N,INF);
    dp[m+1]=0;
    q[++tt]=m+1;//加入哨兵
    for(int i=m;i;i--){
        int len=z[i+n];
        if(len==INF) continue;
        //清除不合格的对头d
        while(hh<= tt && q[hh]-i>len) {
            hh++;
        }
        int j=q[hh];
        dp[i]=min(dp[i],dp[j]+1);
        while(hh<=tt && dp[q[tt]]>=dp[i]) tt--;
        q[++tt]=i;
    }

    if(dp[1]<INF)printf("%d\n",dp[1]);
    else puts("Fake");
    return 0;
}
