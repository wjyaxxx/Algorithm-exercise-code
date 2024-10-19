#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using ll=long long;
void solve(){
    int n;
    cin>>n;
    vector<ll> a(n);
    ll sum=0;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n-2;i++) sum+=a[i];
    cout<<(a[n-1]+sum-a[n-2])<<"\n";
}
int main()
{
    read_fast;
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}