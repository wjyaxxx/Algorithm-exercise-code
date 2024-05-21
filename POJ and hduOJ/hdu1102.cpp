#include <bits/stdc++.h>
using namespace std;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
const int N=110;
int e[N][N],dis[N],st[N];
int n,m;
int prime()
{
    int ans=0;
    for(int i=0;i<n;i++){
        int t=-1;
        for(int j=1;j<=n;j++)
            if(!st[j]&&(t==-1||dis[t]>dis[j]))
                t=j;
        st[t]=true;
        
        if(i) ans+=dis[t];
        for(int j=1;j<=n;j++) dis[j]=min(dis[j],e[t][j]);
    }
    return ans;
}
int main()
{
        //cinquick();
        
        while(scanf("%d",&n)!=EOF){
            fill(dis,dis+N,0x3f3f3f3f);
            fill(st,st+N,0);
            for(int  i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    cin>>e[i][j];
            cin>>m;
            int a,b;
            for(int i=1;i<=m;i++){
                cin>>a>>b;
                e[a][b]=0;
                e[b][a]=0;
                
            }  
            cout<<prime()<<endl;
    }
        
    return 0;
}