#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using ll=long long;
void solve(){
    int n,k;
    cin>>n>>k;
    vector<ll> a(n);
    unordered_map<int,ll> mp;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    for(auto&x:a){
        int r=x%k;
        if(mp.find(r)!=mp.end()){
            //不能比自己还小，同余数的数字
            x=max(mp[r]+k,x);
            mp[r]=x;
        }else mp[r]=x;
    }
    sort(a.begin(),a.end());
    if(a[0]>0) cout<<0<<"\n";
    else{
        for(int i=1;i<n;i++){
            if(a[i]-a[i-1]>1){
                cout<<a[i-1]+1<<"\n";
                return ;
            }
        }
        cout<<a[n-1]+1<<"\n";
    }
}
int main()
{
    read_fast;
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}