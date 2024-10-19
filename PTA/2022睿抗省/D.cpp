#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
typedef long long LL;
const int N=1e6+10;
vector<int> g[N];
int n;
int sa[N],sb[N],ca,cb;
void dfs(int u,int f,int d){
    if(d&1) sb[++cb]=u;
    else sa[++ca]=u;

    for(auto x:g[u]){
        if(x==f) continue;
        dfs(x,u,d+1);
    }
}
int main()
{
    read_fast
    cin>>n;
    int a,b;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,-1,0);
    cout<<((LL)ca*cb)-(n-1)<<endl;
    return 0;
}