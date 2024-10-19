#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
typedef pair<int,int> PII;
const int N=1e5+10;
vector<int> g[N];
int p[N],s[N],d[N];
bool vis[N];
int n,m;

int l,r;
int find(int x){
    if(x!=p[x]) p[x]=find(p[x]);
    return p[x];
}
int bfs(int l,int r){

    memset(vis,0,sizeof vis);
    queue<int> q;
    q.push(l);
    d[l]=0;
    while(q.size()){
        int t=q.front();
        q.pop();
        if(vis[t]) continue;
        if(t==r) break;
        vis[t]=1;
        //就遍历这个点
        for(auto x:g[t]){
            if(!vis[x]){
                if(t==l && x==r) continue;
                d[x]=d[t]+1;
                q.push(x);
            }
        }
    }
    return d[r]+1;
}
void solve()
{
   
    cin>>n>>m;
    memset(p,0,sizeof p);
    for(int i=1;i<=n;i++) {
        p[i]=i;
        s[i]=0;
        d[i]=0;
        g[i].clear();
    }
    int u,v;
    for(int i=1;i<=m;i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        int fv=find(v),fu=find(u);
        if(fv!=fu){
            p[fv]=fu;
            s[fu]+=s[fv];
        }else{
            //说明出现了环s
            l=u,r=v;
            s[fu]++;  
        }
    }
    
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(find(i)==i && s[i]==1) {
            cnt++;
        }
    }
    if(cnt!=1) cout<<"No"<<' '<<cnt<<"\n";
    else{
        
        cout<<"Yes "<<bfs(l,r)<<"\n";
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