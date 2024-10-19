//带权并查集
#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const int  N=1e6+10;
int p[N],d[N],deep[N];
int find(int x){
    if(p[x]!=x){
        int t=p[x];
        p[x]=find(p[x]);
        d[x]+=d[t];
        //cerr<<x<<' '<<t<<" "<<d[x]<<' '<<d[t]<<"\n";
    }
    return p[x];
}
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) p[i]=i,d[i]=0,deep[i]=0;

    int u,v,x;
    for(int i=1;i<n;i++){
        cin>>u>>v>>x;
        int fu=find(u),fv=find(v);
        if(fu!=fv){
            p[fv]=u;
            //合并两者的高度
            d[fv]=1;
            find(v);
            //更新新的根节点的高度
            deep[fu]=max(deep[fu],deep[fv]+d[fv]);            
        }
        cout<<deep[x]<<" ";
    }
    cout<<"\n";
    for(int i=1;i<=n;i++)
         cerr<<d[i]<<' ';
    cerr<<"\n";
    cerr<<"---\n";
}
int main()
{
    read_fast;
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}