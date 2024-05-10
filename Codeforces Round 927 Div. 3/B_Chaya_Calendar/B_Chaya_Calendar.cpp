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
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    // 朴素做法
    // int ans=a[0];

    // for(int i=1;i<n;i++)
    // {
    //     int les=ans;
    //     ans=((a[i]+ans-1)/a[i])*a[i];
    //     if(ans==les) ans+=a[i];
    // }

    //数论做法
    long long ans=0;
    for(int i=0;i<n;i++)
    {
        ans=ans-ans%a[i]+a[i];
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