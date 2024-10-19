#include <bits/stdc++.h>
using namespace std;
#define int long long
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int a,b,c;
bool cul(int mid){
    return mid+((mid-b)/(a-b))*b>=c;
}
void solve()
{
    cin>>a>>b>>c;
    int l=0,r=c;
    if(a==b){
        cout<<min(c,a)<<"\n";
        return ;
    }
    while(l<r){
        int mid=(l+r)>>1;
        if(cul(mid)) r=mid;
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