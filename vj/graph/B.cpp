#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
// int e[N],ne[N],h[N],idx;
// void add(int a,int b){
//     e[idx]=b,ne[idx]=h[a],h[a]=idx++;
// }
 vector<int> g[N];
int maxp[N];
int n,m;
bool st[N];
void dfs(int u,int maxv){
    if(maxp[u]!=-1) return;
    maxp[u]=maxv;

    for(auto x:g[u]){
        dfs(x,maxv);
    }

}
// void bfs(int u){
//     queue<int> q;
//     q.push(u);
//     st[u]=true;
//     while(q.size()){
//         int t=q.front();
//         q.pop();
//         //cout<<t<<' ';
//         sort(g[t].begin(),g[t].end());
//         for(auto x:g[t]){
//             if(!st[x]){
//                 q.push(x);
//                 st[x]=true;
//             }
//         }
//     }
// }
int main()
{
        ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
       memset(maxp,-1,sizeof maxp);
       //memset(h,-1,sizeof h);
        cin>>n>>m;
        int u,v;
        
        for(int i=1;i<=m;i++){
            cin>>u>>v;
            //add(u,v);
            g[v].emplace_back(u);
        }
        
        for(int i=n;i>=1;i--){
            dfs(i,i);
        }

        for(int i=1;i<=n;i++) cout<<maxp[i]<<' ';
        
        return 0;
}