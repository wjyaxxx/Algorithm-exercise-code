#include <bits/stdc++.h>
using namespace std;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
void solve()
{
    int n,x,y;
    cin>>n>>x>>y;
    map<pair<int,int>,int> mp;//因为两个是一对，所以要一起记录下来，如果两个都一样就会映射在一起，后面用乘法法则即可
    long long ans=0;//因为是互补所以被记录在了两个map中
    for(int i=0;i<n;i++)
    {
        int m;
        cin>>m;
        int tmp1=m%x,tmp2=m%y;
        if(tmp1==0) ans+=mp[{0,tmp2}];
        else ans+=mp[{x-tmp1,tmp2}];
        mp[{tmp1,tmp2}]++;
    }

    
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