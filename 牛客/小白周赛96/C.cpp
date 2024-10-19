#include <bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
typedef long long LL;
LL a[N];
int n;

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],a[i]+=a[i-1];

    LL ans=0;
    for(int i=1;i<n-1;i++){
        LL res=(a[n]+a[i])/2;
        int j1=upper_bound(a+2,a+n,res)-a;
        int j2=upper_bound(a+2,a+n,2*a[i])-a;
        int j=max(j1,j2);
        
        ans+=(n-j);
    }

    cout<<ans<<"\n";
}
int main()
{
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int t=1;
        //cin>>t;
        while(t--) solve();
        return 0;
}