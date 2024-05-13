#include <bits/stdc++.h>
using namespace std;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
typedef long long LL;
int n;
const int N=1e5+10;
LL tree[N],w[55];
void dfs(int u,int d)
{
    if(u>n) return ;
    w[d]+=tree[u];
    dfs(u*2,d+1);
    dfs(u*2+1,d+1);
}
LL ans,maxdeep;
int main()
{
        cinquick();
        cin>>n;
        
        for(int i=1;i<=n;i++) cin>>tree[i];
        dfs(1,1);
        ans=w[1],maxdeep=1;
        for(int i=2;i<=50;i++){
            if(w[i]>ans){
                ans=w[i];
                maxdeep=i;
            }
        }
        
        cout<<maxdeep<<endl;
        return 0;
}