#include <iostream>
#define int long long
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int p[500050],f[500050],vis[500050];
void solve(){
    int n;
    cin>>n;
    if(vis[n]) cout<<"no\n";
    else cout<<"yes\n";
}

signed main()
{
    read_fast;
    for(int i=1;i<500050;i++){
        for(int j=2;j*i<500050;j++){
            f[i*j]+=i;
        }
    }
    //这个题目，可能很大的数的因数和还是很小
    for(int i=1;i<500050;i++){
        if(f[i]>=2 && f[i]<=1000) vis[f[i]]=1;
    }
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}