#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
void solve()
{
    int n;
    cin>>n;
    vector<int>f(n+1);
    f[1]=1;
    f[2]=1;
    for(int i=3;i<=n;i++) f[i]=f[i-1]+f[i-2];
    cout<<f[n]<<"\n";
}
int main()
{
    read_fast;
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}