#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL x,y;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
void solve()
{
    cin>>x>>y;
    LL l=0,r=1e18;
    if(x==0||y==0)
    {
        cout<<"-1"<<endl;
        return ;
    }
    if(x==1&&y>1)
    {
        cout<<"-1"<<endl;
        return ;
    }
    if(x==1)
    {
        cout<<0<<endl;
        return ;
    }
    double k=log10(y)/log10(x);
    int ans=int(k);
    cout<<ans<<endl;
}
int main()
{
        cinquick();
        int t;
        cin>>t;
        while(t--) solve();
        return 0;
}