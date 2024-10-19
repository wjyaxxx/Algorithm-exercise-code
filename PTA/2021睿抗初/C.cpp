#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
typedef pair<int,int> PII;

const int N=1100;
PII g[N][N];//建图
int dis[N][N];
int n,m;
int path[N],st[N];
int dist[N];
int sum[N];
void dijkstra(int s){
    memset(dist, 0x3f, sizeof dist);
    dist[s]=0;
    
    path[s]=-1;
    for(int i=1;i<=n-1;i++){
        int t=-1;
        for(int j=1;j<=n;j++)
            if(!st[j]&&( t==-1 ||dist[t]> dist[j]))
                t=j;
        
        for(int j=1;j<=n;j++){
            int v=g[t][j].first,s1=g[t][j].second;
            if(v==0) continue;
            //dist[j]=min(dist[j],dist[t]+v);
            
            if(dist[j]>dist[t]+v){
                dist[j]=dist[t]+v;
                sum[j]=sum[t]+s1;
                path[j]=t;
            }
            else if(dist[j]==dist[t]+v){
                if(sum[j]<sum[t]+s1){
                    sum[j]=sum[t]+s1;
                    path[j]=t;
                }
            }
        }
        st[t]=1;
    }
}

void print(int s,int t){
	if(s==t){
		printf("%d",s);
		return;
	}
	print(s,path[t]);
	printf("->%d",t);
}
int main()
{
   cin>>n>>m;
   int u,v,a,b; 
   for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i==j) dis[i][j]=0;
            else dis[i][j]=0x3f3f3f3f;
   for(int i=1;i<=m;i++){
        cin>>u>>v>>a>>b;
        g[u][v]={a,b};
        g[v][u]={a,b};
        dis[u][v]=a;
        dis[v][u]=a;
   }
   

    //floyd跑一遍最大距离
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);

    
    int st=-1,ansv=0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        //i-->j的最大距离的最大值
        int maxv=0;
        for(int j=1;j<=n;j++){
            maxv=max(maxv,dis[i][j]);
        }
        
        if(maxv<ansv){
            ansv=maxv;
            st=i;
        }
    }
    cout<<st<<"\n";
    dijkstra(st);
    
    int k;
    cin>>k;
    int x;
    for(int i=1;i<=k;i++){
        cin>>x; 
        print(st,x);
        cout<<"\n";
        cout<<dist[x]<<' '<<sum[x]<<"\n";
    }
   
    return 0;
}