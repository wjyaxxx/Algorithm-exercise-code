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
        int m=lower_bound(a.begin(),a.end(),0)-a.begin();
        for(int i=0;i<=m;i++){
            int idx=lower_bound(a.begin()+i,a.begin()+m,-i)-a.begin();
            int res=m-idx;
            //此时在数轴上这个人处在 -i的位置，假设右边能到的边界的右边为x位置，那么(n-x)为移动点的个数，-i+(n-x)为最终移动的位置
            //若无法到达，那么他能到达的边界的右边为m，全部能达到则为n-1+1
            int lo=m,hi=n;
            while(lo<hi){
                int mid=(lo+hi+1)>>1;
                if(a[mid-1]<=n-mid-i) lo=mid;
                else hi=mid-1;
            }            
            res+=lo-m;
            ans=max(ans,res);
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