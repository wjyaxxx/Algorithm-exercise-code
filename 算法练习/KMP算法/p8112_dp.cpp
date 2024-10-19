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
    
    //for(int i=1;i<=m;i++) cerr<<z[i+n]<<" ";    
    //单调队列优化
    fill(dp,dp+N,INF);
    dp[m+1]=0;
    
    for(int i=m;i;i--)
    {
        int len=z[i+n];
       for(int j=1;j<=len;j++){
            dp[i]=min(dp[i],dp[i+j]+1);
        }
    }
    cerr<<z[101+n]<<"\n";
    for(int i=1;i<=m;i++)
        //if(dp[i]==25) cout<<i<<"\n"; 
    //cout<<dp[i]<<" ";
    // if(dp[1]<INF)printf("%d\n",dp[1]);
    // else puts("Fake");
    return 0;
}