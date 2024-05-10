#include <bits/stdc++.h>
using namespace std;
const int N=200010;
int h[N];
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
    for(int i=0;i<n;i++) cin>>h[i];
   int l=0,r=n-1;
    while(h[l]==h[l+1]) l++;
    while(h[r]==h[r-1]) r--;
    if(h[l]==h[r])
    {
        if(l>=r-1) cout<<0<<endl;
        else{
            cout<<r-l-1<<endl;
        }
    }
    else
    {
        int ans=max(n-r,l+1);
        cout<<n-ans<<endl;
    }
}
int main()
{
        cinquick();
        int t;
        cin>>t;
        while(t--) solve();
        return 0;
}