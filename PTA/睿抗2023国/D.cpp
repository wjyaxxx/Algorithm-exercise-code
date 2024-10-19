#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const int N=1010;
unordered_map<int,int> mp,f;
int  idx;
vector<int> edge[N];
int d[N];//保存每个点的入度
int n,m;
int g[N][N];
int main()
{
    read_fast
    cin>>n>>m;
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            cin>>g[i][j];
            if(mp.find(g[i][j])==mp.end()){
                mp[g[i][j]]=++idx;
                f[idx]=g[i][j];
            }
        }
    
    for(int i=1;i<n;i++)
        for(int j=1;j<=m;j++){
            int u=mp[g[i][j]],v=mp[g[i+1][j]];
            if(find(edge[u].begin(),edge[u].end(),v)!=edge[u].end()||u==v) continue;
            edge[u].push_back(v);
            d[v]++;
        }
    
    priority_queue<int,vector<int>,greater<int>> q;
    for(int i=1;i<=idx;i++)
        if(!d[i]) q.push(f[i]);
    vector<int> ans;
    
    while(q.size()){
        int t=q.top();
        q.pop();
        ans.push_back(t);
        t=mp[t];
        for(auto x:edge[t]){
            if(--d[x]==0)
                q.push(f[x]);
        }
    }
    for(int i=0;i<ans.size();i++)
        if(i!=ans.size()-1)
            cout<<ans[i]<<' ';
        else cout<<ans[i];
    if(ans.size()<idx) cout<<" Impossible";
    return 0;
}