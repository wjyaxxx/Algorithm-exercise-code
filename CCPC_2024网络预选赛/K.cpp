#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
void solve()
{
    int n,k;
    cin>>n>>k;
    int ln=n&(-n);
    if(ln<=k) cout<<"Alice\n";
    else cout<<"Bob\n";
}
int main()
{
    read_fast;
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}