#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
void solve()
{
    int n;
    cin>>n;
    
    vector<int> p(n+1);
    for(int i=1;i<=n;i++) p[i]=i;
    auto find=[&p](auto self,int x)->int{
        if(p[x]!=x) p[x]=self(self,p[x]);
        return p[x];
    };
    int u,v;
    bool ok=false;
    for(int i=0;i<n;i++){
        cin>>u>>v;
        u--;
        int fu=find(find,u),fv=find(find,v);
        if(fu==fv){
            ok=true;
        }
        else{
            p[fu]=fv;
        }
    }
    cout<<(!ok)<<"\n";
}
int main()
{
    read_fast;
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}