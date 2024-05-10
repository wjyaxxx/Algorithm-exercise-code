#include <bits/stdc++.h>
using namespace std;
int v,g;
const int N=30;
int goal[N],ans[N];
int p[N][N];
int pre[N],used[N];
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
bool dfs(int u,int x,int d)
{
    if(u>d)
    {
        for(int i=1;i<=v;i++)
        {
            int sum=0;
            for(int j=1;j<=d;j++)
                sum+=p[pre[j]][i];
            if(sum<goal[i]) return false;
        }
        for(int i=1;i<=d;i++){
            ans[i]=pre[i];
        }
        return true;
    }
    for(int i=x;i<=g;i++)
    {
        if(!used[i])
        {
            used[i]=1;
            pre[u]=i;
            if(dfs(u+1,i+1,d)) return true;
            else{
                used[i]=0;
                pre[u]=0;
            }
        }
    }
    return false;
}

int main()
{
        cinquick();
        cin>>v;

        for(int i=1;i<=v;i++) cin>>goal[i];
        cin>>g;

        for(int i=1;i<=g;i++){
            for(int j=1;j<=v;j++) cin>>p[i][j];
        }
        
        for(int d=1;d<=g;d++)
        {
            if(dfs(1,1,d)) {
                cout<<d<<' ';
                 for(int i=1;i<=d;i++)
                    cout<<ans[i]<<' ';
                break;
            }
        }
        return 0;
}