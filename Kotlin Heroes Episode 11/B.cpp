#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define int long long
void solve(){
    int k;
    cin>>k;
    int l=1,r=2e18;
    auto cul=[](int n)->int{
        int d=sqrt(n);
        return n-d;
    };
    while(l<r){
        int mid=(l+r)>>1;
        if(cul(mid)>=k) r=mid;
        else l=mid+1;
    }
    cout<<l<<"\n";
}

signed main()
{
    read_fast;
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}