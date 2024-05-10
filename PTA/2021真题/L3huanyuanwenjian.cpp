#include <bits/stdc++.h>
using namespace std;
const int N=100010;
int q[N];
int pre[110],st[110];//pre表示选了什么位置，st表示还要哪些没选
vector<int> ord[110];
int ans[110],t;
int n,m;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
bool check(int len,int u){
    int idx=len;
    for(int i=0;i<ord[u].size();i++)
    {
        if(q[idx]!=ord[u][i])
            return false;
        idx++;
    }
    return true;
}
void dfs(int len)
{
    if(len>=n) return;

    for(int i=1;i<=m;i++)
        if(!pre[i]){
            if(!check(len,i)) continue;
            pre[i]=1;
            ans[++t]=i;
            dfs(len+ord[i].size()-1);
            pre[i]=0;
            t--;
     
    }
}
int main()
{
        cinquick();
        cin>>n;
        for(int i=1;i<=n;i++) cin>>q[i];
        cin>>m;

        int k,x;
        for(int j=1;j<=m;j++) {
            cin>>k;
            while(k--){
                cin>>x;
                ord[j].push_back(x);
            }
        }     
        dfs(1);
        for(int i=1;i<=m;i++)
            if(i==1) cout<<ans[i];
            else cout<<' '<<ans[i];
        return 0;
}