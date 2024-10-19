#include <bits/stdc++.h>
#define int long long
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    
    for(int i=0;i<n;i++) cin>>a[i];

    int l=1,r=1e12;
    auto check1=[&](int x)->bool{
        vector<int> b(a);
        for(int i=0;i<n-1;i++){
            if(b[i]>x) b[i+1]+=(b[i]-x);
        }
        return (b[n-1]<=x);
    };
    //最大值
    while(l<r){
        int mid=(l+r)>>1;
        if(check1(mid))  r=mid;
        else l=mid+1;
    }


    int mx=l;
    l=1,r=1e12;
    auto check2=[&](int x)->bool{
        vector<int> b(a);
        for(int i=n-1;i>=1;i--){
            if(b[i]<x) b[i-1]-=(x-b[i]);
        }
        return (b[0]>=x);
    };
    while(l<r){
        int mid=(l+r+1)>>1;
        if(check2(mid)) l=mid;
        else r=mid-1;
    }
    
    cout<<mx-l<<"\n";
}
signed main()
{
    read_fast;
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}