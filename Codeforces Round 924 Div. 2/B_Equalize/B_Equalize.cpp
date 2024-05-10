#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    scanf("%d",&n);
    vector<int> a(n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    int ans=0;
    for(int i=0;i<a.size();i++)
    {
        int j=int(lower_bound(a.begin(),a.end(),a[i]+n)-a.begin());
        ans=max(ans,j-i);
    }
    printf("%d\n",ans);
}
int main()
{
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}