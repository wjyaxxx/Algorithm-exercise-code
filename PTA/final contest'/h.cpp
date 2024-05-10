#include <bits/stdc++.h>
using namespace std;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
int s(int x)
{
    int res=0;
    while(x)
    {
        res+=x%10;
        x/=10;
    }
    return  res;
}
void solve()
{
    int a,b;
    cin>>a>>b;
    int sa=s(a),sb=s(b);
    bool oka=false,okb=false;
    if(a%sb==0) oka=true;
    if (b%sa==0) okb=true;
    if((oka&&okb)||(!oka&&!okb)) a>b?cout<<'A'<<endl:cout<<'B'<<endl;
    else if(oka) cout<<'A'<<endl;
    else cout<<'B'<<endl;
     
}
int main()
{
        cinquick();
        int t;
        cin>>t;
        while(t--) solve();
        return 0;
}