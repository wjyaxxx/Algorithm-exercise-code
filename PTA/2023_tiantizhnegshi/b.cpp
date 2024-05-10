#include <bits/stdc++.h>
using namespace std;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
int fsum(int x)
{
    int res=0;
    while(x)
    {
        res+=x%10;
        x/=10;
    }
    return res;
}
void solve()
{
    int a,b;
    cin>>a>>b;
    int sa=fsum(a),sb=fsum(b);
    if((a%sb==0&&b%sa==0)||(a%sb!=0&&b%sa!=0))
    {
        if(a>b) cout<<"A"<<endl;
        else cout<<"B"<<endl;
    }
    else if(a%sb==0) cout<<"A"<<endl;
    else cout<<"B"<<endl;
}
int main()
{
        cinquick();
        int t;
        cin>>t;
        while(t--) solve();
        return 0;
}