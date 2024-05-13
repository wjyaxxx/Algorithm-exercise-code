#include <bits/stdc++.h>
using namespace std;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
const int N=1e5+10;
vector<int> g[N];
int n,d;
int ans;
void dfs(int u,int deep,int f){
    if(deep>d) return;
    ans++;
    for(auto x:g[u]){
        if(x!=f){
            dfs(x,deep+1,u);
        }
    }
}
int main()
{
        cinquick();
        cin>>n>>d;
        int u,v;
        for(int i=1;i<=n-1;i++){
            cin>>u>>v;
            
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1,0,-1);
        cout<<ans-1<<endl;
        return 0;
}