#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
void solve(){
    int n,x,y;
    cin>>n>>x>>y;
    vector<int> a(n+1);
    for(int i=y;i<=x;i++) a[i]=1;
    bool ok=false;
    for(int i=y-1;i>=1;i--){
        if(!ok) a[i]=-1;
        else a[i]=1;
        ok=!ok;
    }
    ok=false;
    for(int i=x+1;i<=n;i++){
        if(!ok) a[i]=-1;
        else a[i]=1;
        ok=!ok;
    }
    
    for(int i=1;i<=n;i++) cout<<a[i]<<' ';
    cout<<"\n";
}
int main()
{
    read_fast;
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}