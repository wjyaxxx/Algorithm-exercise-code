#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const int mod=998244353;
void solve()
{
    int n;
    cin>>n;
    vector<int> a(n);
    int sum=0;
    for(int i=0;i<n;i++) cin>>a[i];
   bool ok=1;
   while(ok){
    ok=0;
    for(int i=n-1;i;i--){
        if(a[i-1]<a[i]){
            ok=1;
            while(a[i-1]<a[i]) a[i-1]++,a[i]--;
        }
    }
}
    
    long long tmp=1;
    for(int i=0;i<n;i++){
        tmp=(tmp*a[i])%mod;
    }
    cout<<tmp<<"\n";
}
int main()
{
    read_fast;
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}