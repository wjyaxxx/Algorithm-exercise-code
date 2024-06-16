#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
// int e[N],ne[N],h[N],idx;
// void add(int a,int b){
//     e[idx]=b,ne[idx]=h[a],h[a]=idx++;
// }
vector<int> g[N];
bool st[N];
int n,m;
void dfs(int u){
    cout<<u<<' ';
    st[u]=true;
    sort(g[u].begin(),g[u].end());
    for(auto x:g[u]){
        if(!st[x])
            dfs(x);
    }
}
void bfs(int u){
    queue<int> q;
    q.push(u);
    st[u]=true;
    while(q.size()){
        int t=q.front();
        q.pop();
        cout<<t<<' ';
        sort(g[t].begin(),g[t].end());
        for(auto x:g[t]){
            if(!st[x]){
                q.push(x);
                st[x]=true;
            }
        }
    }
}
int main()
{
        ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
        cin>>n>>m;
        int u,v;
        for(int i=1;i<=m;i++){
            cin>>u>>v;
            g[u].emplace_back(v);
        }
        dfs(1);
        cout<<"\n";
        memset(st,0,sizeof st);
        bfs(1);
        return 0;
}