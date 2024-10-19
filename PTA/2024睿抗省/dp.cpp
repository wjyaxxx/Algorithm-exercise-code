#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const int N=5010;
struct task
{
    int t,d,p;
    bool operator<(task s){
        return d<s.d;
    }
}a[N];

int n;
int dp[N];//考虑前i个任务，在第j分钟结束时所获得的最大利润=
void solve()
{
    cin>>n;
    int t,d,p;
    for(int i=1;i<=n;i++){
        cin>>t>>d>>p;
        a[i]={t,d,p};
    }
    sort(a+1,a+1+n);
    memset(dp,0,sizeof dp);
    //dp的时效性，dp的一次计算性，决策只有一次
    for(int i=1;i<=n;i++){//阶段
        int ed=a[i].d;
        for(int j=ed;j>=0;j--){
            if(j-a[i].t>=0) dp[j]=max(dp[j],dp[j-a[i].t]+a[i].p);
            //cout<<dp[j]<<' ';
        }
        //cout<<"\n";
    }
    //cout<<"--------\n";
    int ans=0;
    for(int j=0;j<=a[n].d;j++) 
        ans=max(ans,dp[j]);
    cout<<ans<<"\n";
}
int main()
{
    read_fast;
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}