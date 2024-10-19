#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
void solve()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    //直接枚举用来移动的点即可
    int ans=0;
    auto work = [&](){
        int m=upper_bound(a.begin(),a.end(),0)-a.begin();
        //观察到两边到达的边界都在减小
        int res=0;
        int l=0,r=n-1;
        for(int i=0;i<m;i++){
            while()
        }
    };
    work();
    for(int i=0;i<n;i++) a[i]=-a[i];
    reverse(a.begin(),a.end());
    work();
    cout<<ans<<"\n";
}
int main()
{
    read_fast;
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}