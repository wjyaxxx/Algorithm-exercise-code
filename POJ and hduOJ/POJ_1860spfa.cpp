#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int N=510;
int ne[N],e[N],h[N],idx;
struct node
{
    double r,c;
}g[N];
double dis[N];
int st[N],cnt[N];
int n,m,s;
double k;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
void add(int a,int b,int r,int c)
{
    e[idx]=b,g[idx].r=r,g[idx].c=c,ne[idx]=h[a],h[a]=idx++;
}
bool spfa()
{
    
    fill(st,st+N,0);
    fill(cnt,cnt+N,0);
    queue<int> q;
    for(int i=1;i<=n;i++) dis[i]=-100;
    for(int i=1;i<=n;i++){
        st[i]=true;
        q.push(i);
    }
    dis[s]=k;
    
    while(!q.empty())
    {
        int t=q.front();
        q.pop();

        st[t]=false;

        for(int i=h[t];i!=-1;i=ne[i])
        {
            int j=e[i];
            
            if(dis[j]<(dis[t]-g[i].c)*g[i].r){
                dis[j]=(dis[t]-g[i].c)*g[i].r;
                cnt[j]=cnt[t]+1;
                cout<<cnt[j]<<endl;
                if(cnt[j]>=n) return true;
                if(!st[j]){
                    q.push(j);
                    st[j]=true;
                }
            }
        }
    }
    
    return false;
    
}

int main()
{
        //cinquick();
        while(~scanf("%d%d%d%lf",&n,&m,&s,&k)){
            fill(h,h+N,-1);
            idx=0;
        for(int j=1;j<=m;j++)
        {
            int a,b;
            double rab,cab,rba,cba;
            cin>>a>>b>>rab>>cab>>rba>>cba;
            add(a,b,rab,cab);
            add(b,a,rba,cba);
        }
        
        if(spfa()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
        return 0;
}