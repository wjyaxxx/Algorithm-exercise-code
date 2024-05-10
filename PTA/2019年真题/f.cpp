#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int> e[N],f[N];
int dis[N],st[N];
int n;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
void bfs(int u)
{
    queue<int> q;
    q.push(u);
    dis[u]=0;
    while(!q.empty()){
        int t=q.front();
        q.pop();
        for(auto x:e[t]){
            dis[x]=dis[t]+1;
            q.push(x);
        }
    }
    int maxv=-1,maxid=0;
    for(int i=1;i<=n;i++){
        if(maxv<dis[i]){
            maxv=dis[i];
            maxid=i;
        }
    }
    cout<<maxid<<endl;
}
int main()
{
        cinquick();
        cin>>n;
        for(int i=1;i<=n;i++){
            int k;
            cin>>k;
            int x;
            for(int j=1;j<=k;j++){
                cin>>x;
                e[i].push_back(x);
                st[x]=true;
            }
        }

        for(int i=1;i<=n;i++){
            if(!st[i]){
                bfs(i);
            }

        }
        return 0;
}