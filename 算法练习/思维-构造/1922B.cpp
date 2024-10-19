#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using ll=long long;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    sort(a.begin(),a.end());
    ll ans=0;
    for(int i=0,j=i;i<n;i++){
        while(j<n && a[i]==a[j]) j++;
       
        if((j-i)<2) continue;
        for(int k=i;k<j-1;k++){
            ans+=(ll)k*(j-k-1);
        } 
        i=j-1;
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