#include <bits/stdc++.h>
using namespace std;
int n,m;
int g[220][220];
bool st[220];
int V[220];
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
int main()
{
        cinquick();
        cin>>n>>m;
        for(int i=1;i<=m;i++){
            int u,v,w;
            cin>>u>>v>>w;
            g[u][v]=w;
            g[v][u]=w;
        }
        int k;
        cin>>k;
        int minv=0x3f3f3f3f,min_id,cnt=0;
        for(int j=1;j<=k;j++){
            int nz;
            cin>>nz;
            vector<int> path(nz+2);
            set<int> s;
            for(int i=1;i<=nz;i++){
                cin>>path[i];
                s.insert(path[i]);
            }
            path[0]=0,path[nz+1]=0;
            if(nz!=n||s.size()!=n) {
                cnt++;
                continue;
            }
            int sum=0;
            bool ok=false;
            for(int i=0;i<=nz;i++){
                int u=path[i],v=path[i+1];
                if(!g[u][v]){
                    cnt++;
                    ok=true;
                    break;
                }
                else{
                    sum+=g[u][v];
                }
            }
            if(ok) continue;
            if(sum<minv){
                minv=sum;
                min_id=j;
            }
        }

        cout<<k-cnt<<endl;
        cout<<min_id<<' '<<minv<<endl;
        return 0;
}