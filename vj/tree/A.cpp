#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
vector<int> g[N];
int n,ans;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
void dfs(int u,int deep)
{
    ans=max(ans,deep);
    for(auto v:g[u]){
        dfs(v,deep+1);
    }
}
int main()
{
        cinquick();
        cin>>n;
        int l,r;
        for(int i=1;i<=n;i++){
            cin>>l>>r;
            if(l==0&&r==0) continue;
            if(l)g[i].push_back(l);
            if(r)g[i].push_back(r);
        }
        dfs(1,1);
        cout<<ans<<endl;
        return 0;
}