#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
void solve(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<int> a(n);
    vector<int> b(m);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    vector<int> z;
    unordered_map<int,int> mp;
    for(int i=0;i<m;i++){
        auto it=mp.find(b[i]);
        if(it==mp.end()){
            z.emplace_back(b[i]);
            mp[b[i]]=1;
        }
    }
    
    for(int i=0;i<min(n,(int)z.size());i++){
        if(z[i]!=a[i]){
            cout<<"TIDAK\n";
            return;
        }
    }
    cout<<"YA\n";
}
int main()
{
    read_fast;
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}