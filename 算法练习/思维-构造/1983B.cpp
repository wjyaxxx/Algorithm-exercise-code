#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using vc=vector<char>;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vc> a(n,vc(m));
    vector<vc> b(n,vc(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>a[i][j];

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>b[i][j];
    
    bool ok=false;
    for(int i=0;i<n;i++){
        int s1=0,s2=0;
        for(int j=0;j<m;j++) s1+=(a[i][j]-'0'),s2+=(b[i][j]-'0');
        if((s1%3)!=(s2%3)) {
            // cout<<i<<"\n";
            ok=true;
            break;
        }
    }
    for(int j=0;j<m;j++){
        int s1=0,s2=0;
        for(int i=0;i<n;i++) s1+=(a[i][j]-'0'),s2+=(b[i][j]-'0');
        if((s1%3)!=(s2%3)) {
            
            ok=true;
            break;
        }
    }
    if(ok) cout<<"NO\n";
    else cout<<"YES\n";
}
int main()
{
    read_fast;
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}