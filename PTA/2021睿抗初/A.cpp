#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int n,m;
const int N=55;
int a[N],vis[N];
unordered_set<int> s;
void dfs(int u,int x,int sum){
    if((4-u)>=(n-x+1)) return;
    if(u>4){
        s.insert(sum);
        return ;
    }
    for(int i=x;i<=n;i++){
        dfs(u+1,i+1,sum+a[i]);
    }
}
int main()
{
    read_fast
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    
    dfs(1,1,0);
    int k,x;
    for(int i=1;i<=m;i++){
        cin>>k;
        bool ok=false;
        for(int j=1;j<=k;j++){
            cin>>x;
            if(s.find(4*x)==s.end()) {
                ok=true;
            }
        }
        ok?cout<<"No\n":cout<<"Yes\n";
    }

    return 0;
}