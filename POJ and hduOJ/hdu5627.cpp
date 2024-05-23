#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=300010;
int p[N];
struct  node
{
    int a,b;
    LL w;
    bool operator<(const  node &t) const{
        return w>t.w;
    }
}edge[N];
int n,m;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
int find(int x)
{
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) p[i]=i;

    for(int i=1;i<=m;i++){
        cin>>edge[i].a>>edge[i].b>>edge[i].w;
    }

    sort(edge+1,edge+m+1);
    LL ans=0;
    int res=0;
    for(int i=1;i<=m;i++){
        int a=edge[i].a,b=edge[i].b,w=edge[i].w;
        int pa=find(a),pb=find(b);
        if(pa!=pb){
            ans^=w;
            res++;
            p[pa]=pb;
        }
    }
    if(res<n-1) cout<<0<<endl;
    else cout<<ans<<endl;
}
int main()
{
        cinquick();
        int t;
        cin>>t;
        while(t--) solve();
        return 0;
}