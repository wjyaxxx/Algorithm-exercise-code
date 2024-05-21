#include <bits/stdc++.h>
using namespace std;
const int N=310;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
int e[N][N];
int dis[N];//各点到最小生成树的距离
bool st[N];
int n;
int prime()
{
    fill(dis,dis+N,0x3f3f3f3f);
  
    int ans=0;
    for(int i=0;i<=n;i++){
        int t=-1;
        for(int j=0;j<=n;j++)
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
        cinquick();
        cin>>n;
        int x;
        for(int i=1;i<=n;i++){
            cin>>x;
            e[0][i]=x;
            e[i][0]=x;
        }

        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                cin>>e[i][j];

        //prime
        cout<<prime()<<endl;
        return 0;
}