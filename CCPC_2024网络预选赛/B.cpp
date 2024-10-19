#include <bits/stdc++.h>
#define int long long
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const int mod=998244353;
signed main()
{
    read_fast
    int  n;
    cin>>n;
    vector<int> a(n);
    map<int,int> mp;
    for(int i=0;i<n;i++){
        cin>>a[i];        
        mp[a[i]]++;
    }
    sort(a.begin(),a.end());
    
    auto fact=[&](int x) ->int{
       
        int res=1;
        for(int i=1;i<=x;i++) res=(res*i)%mod;
        return res;
    };
    int ans=0,cnt=1;
    //由点到区间
    for(int i=n-1;i>=0;i--){
        
        cnt=(cnt*fact(mp[a[i]]))%mod;
        mp[a[i]]=0;
        ans+=a[i]*(i+1);
    }
    for(int i=0;i<n;i++) a[i]=-a[i];
    sort(a.begin(),a.end());
    if(mp.size()!=1) cnt=(cnt*2)%mod;
    for(int i=n-1;i>=0;i--){
        ans+=a[i]*(i+1);
    }
    
    cout<<ans<<' '<<cnt<<"\n";
    return 0;
}