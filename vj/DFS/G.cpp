#include <bits/stdc++.h>
using namespace std;
const int N=15;
int used[N],num[N];
int c[50],d[50];
int n,ans;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
void dfs(int u)
{
    if(u>n){
        ans++;
        if(ans<=3){
            for(int i=1;i<=n;i++) cout<<num[i]<<' ';
            cout<<endl;
        }
        return ;
    }


    for(int i=1;i<=n;i++)
    {
        if(!used[i]&&!c[u+i]&&!d[u-i+n])
        {
            used[i]=1;
            num[u]=i;
            c[u+i]=1;
            d[u-i+n]=1;
            dfs(u+1);
            used[i]=0;
            num[u]=0;
            c[u+i]=0;
            d[u-i+n]=0;
        }
    }
}
int main()
{
        cinquick();

  
        cin>>n;
        dfs(1);
        cout<<ans<<endl;
        return 0;
}