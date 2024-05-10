#include <bits/stdc++.h>
using namespace std;
int ans,l,r;
int sum=0x3f3f3f3f;
int s[4];
int m[4][30];
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
void dfs(int u,int i)
{
    if(u>s[i])
    {
        sum=min(sum,max(l,r));//max表示必须要处理完每件事
        return;
    }

    l+=m[i][u];
    dfs(u+1,i);
    l-=m[i][u];

    r+=m[i][u];
    dfs(u+1,i);
    r-=m[i][u];
}
int main()
{
        cinquick();
        for(int i=0;i<4;i++) cin>>s[i];
        
        for(int i=0;i<4;i++)
        {
            for(int j=1;j<=s[i];j++)
                cin>>m[i][j];
        }
        for(int i=0;i<4;i++)
        {
            sum=0x3f3f3f3f;
            l=r=0;
            dfs(1,i);
            ans+=sum;
        }
        cout<<ans<<endl;
        return 0;
}