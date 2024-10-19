#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
void solve()
{
    long long l,x,y;
    cin>>l>>x>>y;
    if((x*x+y*y)<=l*l) {
        cout<<"Yes\n";
        cout<<0<<"\n";
        return ;
    }
    if((x-l)*(x-l)+y*y<=l*l){
        cout<<"Yes\n";
        cout<<l<<"\n";
        return ;
    }
    cout<<"No\n";
}
int main()
{
    read_fast;
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}