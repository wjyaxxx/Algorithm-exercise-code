#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
typedef long long ll;
void solve(){
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n);
    ll sum=0,mx=0;
    for(int i=0;i<n;i++) cin>>a[i],sum+=a[i],mx=max(mx,a[i]);
    ll sheng=mx*n-sum;
    if(sheng<=k) cout<<n<<"\n";
    else{
        //枚举能够补多少列
        ll ans=0;
        for(ll i=n;i>=1;i--){
            mx=max(mx,(sum+i-1)/i);//列数
            if(mx*i>sum+k) continue;
            ans=max(ans,i);
        }
        cout<<ans<<"\n";
    }
}
int main()
{
    read_fast;
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}