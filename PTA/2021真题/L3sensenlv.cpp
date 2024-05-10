#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,int> PII;
const int N=4*1e5+10;
const LL LL_MAX=0x3f3f3f3f3f3f3f3f;
int h[N],rh[N],e[N],ne[N],w[N],idx;
LL dis1[N],dis2[N],a[N];//a表示每个点的汇率
int st[N];
int n,m,q;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
void add(int h[],int a,int b,int v)
{
    e[idx]=b,w[idx]=v,ne[idx]=h[a],h[a]=idx++;
}
void dijkstra(int h[],LL dis[],int u)
{
    fill(st,st+N,0);
    fill(dis,dis+N,LL_MAX);
    
    dis[u]=0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;

    heap.push({0,u});

    while(heap.size()){
        auto t=heap.top();
        heap.pop();
        int v=t.second;
        LL distance=t.first;
        if(st[v]) continue;
        st[v]=true;

        for(int i=h[v];i!=-1;i=ne[i]){
            int j=e[i];
            if(dis[j]>distance+w[i]){
                
                dis[j]=distance+w[i];
                heap.push({dis[j],j});
            }
        }
    }
}
int main()
{
        cinquick();
        cin>>n>>m>>q;
        memset(h,-1,sizeof h);
        memset(rh,-1,sizeof rh);
        for(int i=1;i<=m;i++){
            int u,v,d,w;
            cin>>u>>v>>d>>w;
            add(h,u,v,d);
            add(rh,v,u,w);
        }

        for(int i=1;i<=n;i++) cin>>a[i];
        dijkstra(h,dis1,1);
        dijkstra(rh,dis2,n);
        multiset<LL> s;//还有这个是最绝的
        for(int p=1;p<=n;p++){
            if(dis1[p]!=LL_MAX&&dis2[p]!=LL_MAX){
                s.insert(dis1[p]+(dis2[p]+a[p]-1)/a[p]);//这个公式很妙啊
            }
        }

        while(q--)
        {
            int x,y;
            cin>>x>>y;
            if(dis1[x]!= LL_MAX &&dis2[x]!=LL_MAX){
                s.erase(s.find(dis1[x]+(dis2[x]+a[x]-1)/a[x]));
                a[x]=y;
                s.insert(dis1[x]+(dis2[x]+a[x]-1)/a[x]);
            }
            cout<<*(s.begin())<<endl;
        }
        return 0;
}