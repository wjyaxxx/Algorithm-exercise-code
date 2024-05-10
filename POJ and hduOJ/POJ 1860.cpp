#include <iostream>
#include <cstdio>
using namespace std;
const int N=500;
struct edge{
    int a,b;
    double rab,cab,rba,cba;
}e[N];
double dis[N];
int n,m,s;
double k;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
bool bellman_fold()
{
    for(int i=1;i<=n;i++) dis[i]=-100;
    
        dis[s]=k;
      for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            int a=e[j].a,b=e[j].b;
           
            double rab=e[j].rab,cab=e[j].cab,rba=e[j].rba,cba=e[j].cba;
        
           
            
            if(dis[b]<(dis[a]-cab)*rab){
                dis[b]=(dis[a]-cab)*rab;
                if(i>=n) return true;
                //printf("点为:%d 值为:%lf\n",b,dis[b]);
                
            }
            if(dis[a]<(dis[b]-cba)*rba){
                dis[a]=(dis[b]-cba)*rba;
                if(i>=n) return true;
                //printf("点为:%d 值为:%lf\n",a,dis[a]);
            }
        }

    return false;
    
}
int main()
{
        //cinquick();
        while(~scanf("%d%d%d%lf",&n,&m,&s,&k)){
        for(int j=1;j<=m;j++)
        {
            int a,b;
            double rab,cab,rba,cba;
            cin>>a>>b>>rab>>cab>>rba>>cba;
             e[j].a=a,e[j].b=b;
             e[j].rab=rab,e[j].cab=cab,e[j].rba=rba,e[j].cba=cba;
        }
        
        if(bellman_fold()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        }
        return 0;
}