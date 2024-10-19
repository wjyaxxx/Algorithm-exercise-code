//并查集的删除操作
#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const int N=5*1e4+10,D=1e3+10;
typedef pair<int,int> PII;
vector<int> g[N];
int p[N];
struct node
{
    int id,cnt;
    vector<PII> Q;
}q[D];
int ans[D];
int n,m,t;
unordered_set<int> s;
int find(int x){
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}
int main()
{
    read_fast
    cin>>n>>m>>t;
    for(int i=1;i<=n;i++) p[i]=i;
    
    int u,v;
    for(int i=1;i<=m;i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    int id,cnt,x,y;
    for(int i=1;i<=t;i++){
        cin>>id>>cnt;
        q[i].id=id,q[i].cnt=cnt;
        s.insert(id);
        for(int k=1;k<=cnt;k++){
            cin>>x>>y;
            q[i].Q.push_back({x,y});
        }
    }
    
    for(int i=1;i<=n;i++)
        if(s.find(i)==s.end()){
            for(auto x:g[i]){
                if(s.find(x)==s.end()){
                    p[find(i)]=find(x);
                }
            }
        }
    
    for(int i=t;i>=1;i--){
        int res=0;
        for(auto [u,v]:q[i].Q){
            int fu=find(u),fv=find(v);
            if(fu!=fv) res++;
        }

        ans[i]=res;
        int id=q[i].id;
        s.erase(id);
        for(auto x:g[id]){
            int fx=find(x),fid=find(id);
            if(s.find(x)==s.end()&&fx!=fid) p[fid]=fx;
        }
    }   
    for(int i=1;i<=t;i++) cout<<ans[i]<<"\n"[i==t];
    return 0;
}
