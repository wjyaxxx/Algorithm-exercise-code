#include <bits/stdc++.h>
using namespace std;
const int N=1e4+10;
vector<int> g[N];
vector<int> ans,tmp;
int st[N];
int n;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
void dfs(int u)
{
    

    tmp.push_back(u);
    for(auto x:g[u]){
        dfs(x);
    }
    if(tmp.size()>ans.size())
    {
        ans=tmp;
    }
    tmp.pop_back();
}
int main()
{
        cinquick();
        cin>>n;
        for(int i=0;i<n;i++){
            int k;
            cin>>k;
            for(int j=0;j<k;j++){
                int x;
                cin>>x;
                g[i].push_back(x);//i指向x
                st[x]=1;
            }
            if(g[i].size())
                sort(g[i].begin(),g[i].end());

        }
        
        for(int i=0;i<n;i++){
            if(!st[i]){
                dfs(i);
                break;
            }
        }

        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++)
            if(i==0) cout<<ans[i];
            else cout<<' '<<ans[i];
        return 0;
}