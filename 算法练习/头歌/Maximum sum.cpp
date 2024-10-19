#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const int N=50010;
int a[N],dpl[N],dpr[N];
int n;
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    //将问题转化为两个dp问题,求左边的以i为结尾的最大字段和
    for(int i=1;i<=n;i++){
        dpl[i]=max(a[i],dpl[i-1]+a[i]);
    }
    int res=0,ans=INT_MIN;
    dpl[0]=0;
    dpr[n+1]=0;
    for(int i=n;i>=1;i--){
        dpr[i]=max(a[i],dpr[i+1]+a[i]);
        ans=max(ans,dpl[i]+res);
        res=max(res,dpr[i]);
    }
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