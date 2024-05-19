#include <bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
vector<int> g[N];
bool status[N];
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
int n,t;
bool dfs(int u,int f)//先手是否失败
{
    int cnt=0;
    for(auto x:g[u]){
        if(x==f) continue;
        //如果他的儿子失败,那么他必定成功
        cnt++;
        if(!dfs(x,u)) return true;
    }
    if(!cnt) return false;
}
int main()
{
        cinquick();
        cin>>n>>t;
        int u,v;
        for(int i=1;i<n;i++){
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        
        while(t--){
            int st;
            cin>>st;
            if(dfs(st,-1)) cout<<"Ron"<<endl;
            else cout<<"Hermione"<<endl;
        }
        return 0;
}